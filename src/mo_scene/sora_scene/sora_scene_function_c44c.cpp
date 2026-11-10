#include <types.h>
#include <gf/gf_application.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_scene.h>

#pragma force_active on

typedef struct {
    u32 w[20];
} Blob80;

typedef struct {
    u32 w[51];
} Blob204;

extern "C" char* fn_1_BF1C(char*);
extern "C" bool isReady__14gfFileIOHandleCFv(const void*);
extern "C" int isLoadFinishMenuSound__6muMenuFv(void*);
extern unsigned char lbl_1_rodata_6E8[];

extern "C" int fn_1_C44C(char* self) {
    int ready;
    if (*(char**)(self + 0x38C) == 0) {
        int n = 0;
        char* cur = self + 0x390;
        for (; n < 10; n++, cur += 4) {
            if (!isReady__14gfFileIOHandleCFv(cur)) {
                ready = 0;
                goto done;
            }
        }
        {
            char* menu = *(char**)(self + 0x35C);
            if (*(unsigned char*)(menu + 0x1A4) == 0)
                ready = 0;
            else
                ready = isLoadFinishMenuSound__6muMenuFv(menu) != 0;
        }
    done:
        if (!ready)
            return 0;
        g_gfApplication->unkD0.endKeepScreen();
        *(char**)(self + 0x38C) = fn_1_BF1C(self);
    }

    char* object = *(char**)(self + 0x38C);
    int state;
    if (*(int*)(object + 0x504) != 12) {
        state = 0;
    } else {
        state = *(int*)(object + 0x48);
    }

    if (state != 0) {
        int pos = *(int*)(object + 0x510) + *(int*)(object + 0x50C) * 10;
        *(int*)(self + 0x558) = pos;
        if (pos > 0x1869F) {
            *(int*)(self + 0x558) = 0x1869F;
        }

        if (state == 1) {
            char* src = *(char**)(self + 0x38C);
            *(int*)(self + 0x628) = *(int*)(src + 0x434);
            *(int*)(self + 0x62C) = *(int*)(src + 0x438);
            *(unsigned char*)(self + 0x630) = *(unsigned char*)(src + 0x43C);
            *(Blob80*)(self + 0x634) = *(Blob80*)(src + 0x440);

            int c;
            char* o = *(char**)(self + 0x38C);
            if (*(int*)(o + 0x434) == 0) {
                c = *(int*)(o + 0x514);
                unsigned char v;
                if (c == 0)
                    v = 0;
                else
                    v = *(unsigned char*)(o + (c - 1) * 0x14 + 0x450);
                *(unsigned char*)(self + 0x684) = v;
            } else {
                c = *(int*)(o + 0x514);
                int v;
                if (c == 0)
                    v = 0;
                else
                    v = *(int*)(o + (((c - 5) << 1)) * 0x14 + 0x44C);
                *(int*)(self + 0x688) = v;
            }

            object = *(char**)(self + 0x38C);
            int m;
            if (*(int*)(object + 0x514) == 0)
                m = 0;
            else
                m = *(int*)(object + 0x520) * 10;
            *(int*)(self + 0x68C) = m;
            *(int*)(self + 0x558) -= m;
            if (*(int*)(self + 0x558) < 0) {
                *(int*)(self + 0x558) = 0;
            }

            *(int*)(self + 0x488) = *(int*)(self + 0x3B8);
            *(Blob204*)(self + 0x48C) = *(Blob204*)(self + 0x3BC);
        }

        gfSceneManager* manager = gfSceneManager::getInstance();
        manager->unk1 = lbl_1_rodata_6E8[state];
        manager->processStep = 2;
    }
    return 0;
}
