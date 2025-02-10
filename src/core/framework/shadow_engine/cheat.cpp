#include "../rbx_engine/rbx_engine.hpp"

    bool RBX::init() {
        RBX::TaskScheduler Instancel;
        RBX::DataModel Instance;
        if (!mem::find_driver()) {
            std::cout << "hi2" << std::endl;
       
        }
       

        mem::process_id = mem::find_process(TEXT("RobloxPlayerBeta.exe"));
        if (!mem::process_id) {
            std::cout << "hi" << std::endl;
        
        }

        uint64_t render_job = read< uint64_t>(Instancel.GetJobByName("RenderJob") + 0x218);
        auto DatamodelPTR = Instance.GetDataModel();
        std::cout << "Render_View: " << (void*)render_job << std::endl;
        std::cout << "Data_Model: " << DatamodelPTR << std::endl;

        auto workspace =   DatamodelPTR->FindFirstChild("Workspace");
        std::cout << "Workspace: " << workspace << std::endl;

        auto players = DatamodelPTR->FindFirstChild("Players");
        std::cout << "players: " << players << std::endl;
        auto lighting = DatamodelPTR->FindFirstChild("lighting");
        std::cout << "lighting: " << lighting << std::endl;
        int cool = 0;
      
      
        

       

       

      
        while (true) {
            if (workspace->address == 0) {
                printf("WorkSpace Invalid");
          }
            if (players->address == 0) {
                printf("players Invalid");
            }
           
            if (DatamodelPTR->address == 0) {
                printf("DatamodelPTR Invalid");
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            for (const auto players2 : DatamodelPTR->FindFirstChild("Players")->GetChildren()) {
                
                auto playernames = players2->GetName();
                std::cout << "PlayerName: " << playernames << "count: " << cool << " \n" << std::endl;
                cool++;
            }
        }
    }
  