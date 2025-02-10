#include <windows.h>
#include <iostream>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>
#include <fstream>
#include <wininet.h>
#include <string>
#include <ShlObj.h>
#include <TlHelp32.h>
#include "../graphics/overlay/overlay.hpp"
#include "../../kmodule/driver_impl.hpp"
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include "types/matrix3/matrix3.h"
#include "types/color3/color3.h"
#include "types/matrix4/matrix4.h"
#include "types/ray/ray.h"
#include "types/vector2/vector2.h"
#include "types/vector3/vector3.h"
#include "types/vector4/vector4.h"
#include "offsets/offsets.h"
namespace RBX {
class Instance : public std::enable_shared_from_this<Instance> {
public:
    Instance() = default;
    explicit Instance(uintptr_t address) : address(address) {}

    uintptr_t address;

    static std::string readstring(std::uint64_t address);

    std::string GetName() const;

    std::vector<std::shared_ptr<Instance>> GetChildren() const;

    std::shared_ptr<Instance> FindFirstChild(const std::string& childName) const;

  

};

class Camera : public Instance {
public:
    Camera() = default;
    explicit Camera(uintptr_t address) : Instance(address) {}


};
class TaskScheduler : public Instance {
public:
    TaskScheduler() = default;
    explicit TaskScheduler(uintptr_t address) : Instance(address) {}


    static std::shared_ptr<TaskScheduler> GetScheduler();

    std::vector<std::shared_ptr<Instance>> GetJobs();

    uint64_t GetJobByName(const std::string& targetName);

};

class Player : public Instance {
public:
    Player() = default;
    explicit Player(uintptr_t address) : Instance(address) {}

};

class Humanoid : public Instance {
public:
    Humanoid() = default;
    explicit Humanoid(uintptr_t address) : Instance(address) {}

};

class Part : public Instance {
public:
    Part() = default;
    explicit Part(uintptr_t address) : Instance(address) {}


    std::uint64_t GetPart() const;

    Vector3 GetPosition() const;

    Vector3 GetSize() const;

    float GetTransparency() const;

    bool IsAnchored() const;

};

class Model : public Instance {
public:
    Model() = default;
    explicit Model(uintptr_t address) : Instance(address) {}

};

class Workspace : public Instance {
public:
    Workspace() = default;
    explicit Workspace(uintptr_t address) : Instance(address) {}

};

class Lighting : public Instance {
public:
    Lighting() = default;
    explicit Lighting(uintptr_t address) : Instance(address) {}


};

class Sound : public Instance {
public:
    Sound() = default;
    explicit Sound(uintptr_t address) : Instance(address) {}

 
};

class GuiObject : public Instance {
public:
    GuiObject() = default;
    explicit GuiObject(uintptr_t address) : Instance(address) {}

 
};

class DataModel : public Instance {
public:
    DataModel() = default;
    explicit DataModel(uintptr_t address) : Instance(address) {}
   
    std::shared_ptr<DataModel> GetDataModelPTR();

    std::shared_ptr<Instance> GetDataModel();

};

class RenderView : public Instance {
public:
    RenderView() = default;
    explicit RenderView(uintptr_t address) : Instance(address) {}
   
    std::shared_ptr<std::uint64_t> GetRenderView();

};

class ScriptContext : public Instance {
public:
    ScriptContext() = default;
    explicit ScriptContext(uintptr_t address) : Instance(address) {}
};

class PerformanceStats : public Instance {
public:
    PerformanceStats() = default;
    explicit PerformanceStats(uintptr_t address) : Instance(address) {}
};

class VisualEngine : public Instance {
public:
    VisualEngine() = default;
    explicit VisualEngine(uintptr_t address) : Instance(address) {}
};

bool init();

}