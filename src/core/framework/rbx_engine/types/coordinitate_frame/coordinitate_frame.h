#include "../matrix3/matrix3.h"
#include "../vector3/vector3.h"
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 position;
};