#include <types.h>
#pragma force_active on

struct BitStruct {
    char pad[0x2E];
    u8 flags : 3;
    u8 x : 5;
};

extern "C" {
    void* getInstance__14gfSceneManagerFv();
    void fn_8004D010(void*);
    void fn_8005033C(void*);
    extern void* g_GameGlobal;
    extern void* lbl_1_bss_1A40;

    void fn_1_27934(s32* self) {
        self[11] = *(s32*)((char*)getInstance__14gfSceneManagerFv() + 0x31C);
        if (!lbl_1_bss_1A40) {
            lbl_1_bss_1A40 = getInstance__14gfSceneManagerFv();
        }
        if (self[11] == 0xFF) {
            self[2] = 0x17;
            self[11] = 0;
        } else {
            self[2] = 0;
            fn_8004D010(g_GameGlobal);
            fn_8005033C(((void**)g_GameGlobal)[2]);
            BitStruct* s = (BitStruct*)((void**)g_GameGlobal)[4];
            s->flags = 1;
        }
    }
}
