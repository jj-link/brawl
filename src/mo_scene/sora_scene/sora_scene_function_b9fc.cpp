#include <gf/gf_application.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_scene.h>

#pragma force_active on

extern "C" char* fn_1_B6F8(void*);
extern unsigned char lbl_1_rodata_6D8[];

extern "C" int fn_1_B9FC(char* self) {
    if (*(char**)(self + 0x380) == 0) {
        int i = 0;
        gfFileIOHandle* handle = (gfFileIOHandle*)(self + 0x384);
        int ready;
        for (; i < 9; i++, handle++) {
            if (!handle->isReady()) {
                ready = 0;
                goto done;
            }
        }
        ready = 1;
    done:
        if (!ready) {
            return 0;
        }
        g_gfApplication->unkD0.endKeepScreen();
        *(char**)(self + 0x380) = fn_1_B6F8(self);
    }
    char* object = *(char**)(self + 0x380);
    int state = *(int*)(object + 0x44);
    if (state != 0) {
        *(int*)(self + 0x3A8) = *(int*)(object + 0x2ABC);
        gfSceneManager* manager = gfSceneManager::getInstance();
        manager->unk1 = lbl_1_rodata_6D8[state];
        manager->processStep = 2;
    }
    return 0;
}
