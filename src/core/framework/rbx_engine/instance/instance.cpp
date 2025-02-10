#include "../rbx_engine.hpp"
using namespace RBX;
std::string Instance::readstring(std::uint64_t address)
{
    std::string result;
    const auto stringLength = read<int>(address + 0x18);
    std::uint64_t stringAddress = (stringLength >= 16) ? read<std::uint64_t>(address) : address;

    while (true)
    {
        char character = read<char>(stringAddress++);
        if (character == '\0') break;
        result.push_back(character);
    }

    return result;
}

 std::string Instance::GetName() const {
     return readstring(read<std::uint64_t>(this->address + Offsets::Name));
 }
 std::vector<std::shared_ptr<Instance>> Instance::GetChildren() const {
     std::vector<std::shared_ptr<Instance>> children;
     if (!this->address) return children;

     std::uint64_t start = read<std::uint64_t>(this->address + Offsets::Children);
     std::uint64_t end = read<std::uint64_t>(start + Offsets::Size);

   
     if (!start || !end || start == end) return children;

     for (auto instance = read<std::uint64_t>(start); instance != end; instance += 16u) {
   
         std::uint64_t instanceAddr = read<std::uint64_t>(instance);
         if (instanceAddr) {
             auto newInstance = std::make_shared<Instance>(instanceAddr);
             children.push_back(newInstance);
         }
     }

     return children;
 }

 std::shared_ptr<Instance> Instance::FindFirstChild(const std::string& childName) const {
     auto children = this->GetChildren();
     for (const auto& child : children) {
         if (child->GetName() == childName) return child;
     }
//    return nullptr;
 }