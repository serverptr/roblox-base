#include "../rbx_engine.hpp"
using namespace RBX;
std::shared_ptr<DataModel> DataModel::GetDataModelPTR() {
    
    std::shared_ptr<RenderView> renderView = std::make_shared<RenderView>();

  
    std::shared_ptr<std::uint64_t> renderViewAddress = renderView->GetRenderView();
    if (!renderViewAddress) {
        return nullptr;  
    }

  
    std::uint64_t dataModelAddress = read<std::uint64_t>(*renderViewAddress + Offsets::DataModel);
    if (dataModelAddress == 0) {
       return nullptr; 
    }

 
    return std::make_shared<DataModel>(dataModelAddress);
}
std::shared_ptr<Instance> DataModel::GetDataModel() {
    return std::make_shared<Instance>(
        read<std::uint64_t>(
            read<std::uint64_t>(
                *std::make_shared<RenderView>()->GetRenderView() + Offsets::DataModel) + Offsets::Game
        )
    );
}
