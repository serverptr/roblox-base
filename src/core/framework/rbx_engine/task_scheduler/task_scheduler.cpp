#include "../rbx_engine.hpp"
using namespace RBX;
 std::shared_ptr<TaskScheduler> TaskScheduler::GetScheduler() {
    uintptr_t baseAddress = mem::find_image();
    if (!baseAddress) {
        return nullptr;
    }

    uintptr_t taskSchedulerAddress = baseAddress + 0x5CDCCD8;
    uintptr_t sigma = read<uintptr_t>(taskSchedulerAddress);
    if (!sigma) {
        return nullptr;
    }

    return std::make_shared<TaskScheduler>(sigma);
}

std::string GetJobName(const std::shared_ptr<Instance>& instance) {
    uintptr_t jobNameAddress = instance->address + 0x90;
    RBX::Instance Instance;
    return Instance.readstring(jobNameAddress);
}

std::vector<std::shared_ptr<Instance>> TaskScheduler::GetJobs() {
    std::vector<std::shared_ptr<Instance>> jobs;
    auto scheduler = GetScheduler();
    if (!scheduler) return jobs;

    uintptr_t jobStart = read<uintptr_t>(scheduler->address + 0x1C8);
    uintptr_t jobEnd = read<uintptr_t>(scheduler->address + 0x1D0);
    if (!jobStart || !jobEnd || jobStart >= jobEnd) {
        return jobs;
    }

    for (uintptr_t currentJob = jobStart; currentJob < jobEnd; currentJob += 0x10) {
        uintptr_t jobAddress = read<uintptr_t>(currentJob);
        if (jobAddress) {
            std::shared_ptr<Instance> jobInstance = std::make_shared<Instance>(jobAddress);
            jobs.push_back(jobInstance);
        }
    }
    return jobs;
}

uint64_t TaskScheduler::GetJobByName(const std::string& targetName) {
    auto jobs = GetJobs();
    if (jobs.empty()) {
        return 0;
    }

    for (const auto& job : jobs) {
        std::string jobName = GetJobName(job);
        if (jobName == targetName) {
            std::cout << "Found Valid job: " << targetName << std::endl;
            return job->address;
        }
    }
    return 0;
}