#include <types.h>
#pragma force_active on

extern "C" void fn_8005F08C(s32 self, void* payload);
extern s32 g_ecMgr;

extern "C" void fn_8001429C(u8* self) {
    u8* e;
    u8* node = *(u8**)(self + 0x68);
    while (node != nullptr) {
        e = node + 8;
        for (u32 i = 0; i < *(u16*)(node + 2); i++) {
            if ((*(s32*)e >> 24) == 8) {
                u8* p = *(u8**)(e + 8);
                if (p != nullptr) {
                    u8* payload;
                    if (*(u16*)(p + 4) == 0x101) {
                        payload = p + 0x10;
                    } else {
                        payload = nullptr;
                    }
                    if (payload != nullptr) {
                        fn_8005F08C(g_ecMgr, payload);
                    }
                }
            }
            e += 0x10;
        }
        node = *(u8**)(node + 4);
    }
}
