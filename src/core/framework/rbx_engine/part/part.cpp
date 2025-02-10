#include "../rbx_engine.hpp"
using namespace RBX;
std::uint64_t Part::GetPart() const {
    return read<std::uint64_t>(this->address + Offsets::Part_Primitive);
}
Vector3 Part::GetPosition() const {

    return read<Vector3>(GetPart() + Offsets::Part_Position);
}

Vector3 Part::GetSize() const {
    return read<Vector3>(GetPart() + Offsets::Part_Size);
}
// non shared to make it only work on fellow part classes

    