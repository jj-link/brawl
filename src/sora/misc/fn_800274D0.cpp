#include <types.h>
#pragma force_active on

extern "C" {
void __dl__FPv(void*);
int fn_801DDEAC(void*);
void __dt__14gfFileIOHandleFv(void*, int);
int strncmp(const char*, const char*, unsigned long);

void fn_800274D0(u8* arg0, const char* arg1) {
    u8* entry = arg0 + 8;
    u32 i = 0;
    do {
        if (strncmp((const char*)(entry + 0x1A), arg1, 0x1F) == 0) {
            u8 c = entry[0x18];
            if (c > 1) {
                entry[0x18] = (u8)(c - 1);
                return;
            }
            entry[0x19] &= ~0x20;
            u8* mod = *(u8**)entry;
            if (mod != 0) {
                if (((mod[8] >> 6) & 1) == 0) {
                    mod[8] |= 0x40;
                    void* obj = *(void**)mod;
                    (*(void (**)(void*))((u8*)obj + 0x38))(obj);
                }
                if ((entry[0x19] >> 2) & 1) {
                    mod = *(u8**)entry;
                    if (mod != 0) {
                        fn_801DDEAC(*(void**)mod);
                        __dl__FPv(mod);
                    }
                }
                *(u32*)entry = 0;
            }
            *(u32*)entry = 0;
            *(u32*)(entry + 0x10) = 0;
            *(u32*)(entry + 4) = 0;
            u32 handle[2];
            handle[0] = 0;
            *(u32*)(entry + 0x14) = 0;
            __dt__14gfFileIOHandleFv(handle, -1);
            *(u32*)(entry + 0xC) = 0;
            union Flags {
                u8 f;
                struct { unsigned char b7:1, b6:1, b5:1, b4:1, b3:1, b2:1, b1:1, b0:1; } bits;
            } flags;
            flags.f = entry[0x19];
            flags.bits.b6 = 0;
            flags.bits.b3 = 0;
            flags.bits.b4 = flags.bits.b3;
            flags.bits.b5 = flags.bits.b4;
            flags.bits.b7 = flags.bits.b5;
            flags.bits.b2 = 1;
            entry[0x19] = flags.f;
            entry[0x1A] = 0;
            entry[0x18] = 0;
            return;
        }
        i++;
        entry += 0x3C;
    } while (i < 0x10);
}
}
