#include <gf/gf_module.h>
#include <string.h>
#pragma force_active on

extern "C" int fn_801DDEAC(void*);
extern "C" void __dl__FPv(void*);

inline void cleanup(char* e) {
    e[0x19] = (char)(e[0x19] & ~0x20);
    u8 state;
    u8* obj = *(u8**)e;
    if (obj != NULL) {
        state = obj[8];
        if (!((state >> 6) & 1)) {
            obj[8] = (u8)(state | 0x40);
            void** vt = *(void***)obj;
            typedef void (*F)(void*);
            ((F)vt[0x38 / 4])(vt);
        }
        if (((u8)e[0x19] >> 2) & 1) {
            u8* mod = *(u8**)e;
            if (mod != 0) {
                fn_801DDEAC(*(void**)mod);
                __dl__FPv(mod);
            }
        }
        *(void**)e = NULL;
    }
    *(u32*)e = 0;
    *(u32*)(e + 0x10) = 0;
    *(u32*)(e + 4) = 0;
    {
        gfFileIOHandle handle;
        *(u32*)(e + 0x14) = 0;
    }
    *(u32*)(e + 0xC) = 0;
    union Flags {
        u8 f;
        struct { unsigned char b7:1, b6:1, b5:1, b4:1, b3:1, b2:1, b1:1, b0:1; } bits;
    } flags;
    flags.f = e[0x19];
    flags.bits.b6 = 0;
    flags.bits.b3 = 0;
    flags.bits.b4 = flags.bits.b3;
    flags.bits.b5 = flags.bits.b4;
    flags.bits.b7 = flags.bits.b5;
    flags.bits.b2 = 1;
    e[0x19] = flags.f;
    e[0x1A] = 0;
    e[0x18] = 0;
}

inline s32 destroyImpl(s32 result, char* e, const char* name) {
    u32 i = 0;
    do {
        if (strncmp(e + 0x1A, name, 0x1F) == 0) {
            u8 cnt = (u8)e[0x18];
            if (cnt > 1)
                e[0x18] = (char)(cnt - 1);
            else
                cleanup(e);
            result = 1;
            break;
        }
        i++;
        e += 0x3C;
    } while (i < 0x10);
    return result;
}
extern "C" s32 destroy__15gfModuleManagerFPCc(gfModuleManager* self, const char* name) {
    return destroyImpl(0, (char*)self + 8, name);
}
