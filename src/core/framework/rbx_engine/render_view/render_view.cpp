#include "../rbx_engine.hpp"
using namespace RBX;

std::shared_ptr<std::uint64_t> RenderView::GetRenderView() {
    std::shared_ptr<TaskScheduler> scheduler = std::make_shared<TaskScheduler>();
    std::uint64_t jobAddress = scheduler->GetJobByName("RenderJob");

    if (jobAddress == 0) {
        return nullptr;
    }
    std::shared_ptr<std::uint64_t> renderViewAddress = std::make_shared<std::uint64_t>(
        read<std::uint64_t>(jobAddress + 0x218)
    );

    return renderViewAddress;
}