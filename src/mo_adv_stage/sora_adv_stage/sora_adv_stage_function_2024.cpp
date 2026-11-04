#include <st/stage.h>
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#include <gf/gf_camera.h>
#pragma force_active on

extern "C" {
extern void* lbl_805A0360;
extern void* g_GameGlobal;
extern float lbl_40_rodata_58;
void fn_27_226A88(void*, float*);
int fn_27_10A848(ftManager*, int, int);
}

extern "C" void fn_40_2024(Stage* self) {
    self->Stage::processAnim();
    void* obj = *(void**)((char*)self + 0x90);
    if (obj) {
        float rect[4];
        fn_27_226A88(obj, rect);
        char* global = (char*)lbl_805A0360;
        *(float*)(global + 0x48) = rect[0];
        *(float*)(global + 0x4c) = rect[1];
        *(float*)(global + 0x50) = rect[2];
        *(float*)(global + 0x54) = rect[3];
    }
    if (!*(unsigned char*)((char*)self + 0x551)) {
        Vec3f pos;
        int success;
        Fighter* fighter;
        int entry = g_ftManager->getEntryId(0);
        if (entry == -1) {
            success = 0;
        } else {
            fighter = g_ftManager->getFighter(entry, -1);
            if (!fighter) {
                success = 0;
            } else if (!g_ftManager->isFighterActivate(entry, -1)) {
                success = 0;
            } else if (!fn_27_10A848(g_ftManager, entry, -1)) {
                success = 0;
            } else {
                pos = soExternalValueAccesser::getPos(fighter);
                success = 1;
            }
        }
        if (success) {
            unsigned char mode = *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x30) + 0x604);
            switch (mode) {
            case 0:
            case 4:
                break;
            case 1:
            case 2:
            case 3:
                CameraController::getInstance()->changeInput(CameraController::AI);
                gfCameraManager* manager = gfCameraManager::getManager();
                manager->m_cameras[0].m_far = lbl_40_rodata_58;
                break;
            }
            *(unsigned char*)((char*)self + 0x551) = 1;
        }
    }
}