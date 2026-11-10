#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void __dla__FPv(void*);
void fn_8004FB48(unsigned int);
void fn_80052704(unsigned short, unsigned char);
void fn_80052AC0(unsigned short, unsigned char);
void fn_80051440(int);
void* memset(void*, int, unsigned int);
}

extern "C" void fn_8015A978(u8* self, unsigned int arg1, int arg2) {
    int off;
    {
        u8* gg28 = (self = self, arg1 = arg1, (u8*)g_GameGlobal->m_advData);
        if (arg2 != 0) {
            unsigned int i;
            i = 0;
            off = 0;
            for (; i < *(unsigned int*)(self + 0x1C); off += 0xC, i++) {
                if (*(u8*)(*(char**)(self + 0x14) + off + 8) != 0) {
                    if (*(int*)(*(char**)(self + 0x14) + off) == 0x17) {
                        fn_80052704(
                            (u16)*(int*)(*(char**)(self + 0x14) + off + 4),
                            *(u8*)(*(char**)(self + 0x14) + off + 8));
                    }
                    if (*(int*)(*(char**)(self + 0x14) + off) == 0x33) {
                        fn_80052AC0(
                            (u16)*(int*)(*(char**)(self + 0x14) + off + 4),
                            *(u8*)(*(char**)(self + 0x14) + off + 8));
                    }
                    if (*(int*)(*(char**)(self + 0x14) + off) == 0x0B) {
                        fn_8004FB48(*(int*)(*(char**)(self + 0x14) + off + 4));
                    }
                }
            }
            *(int*)(self + 0x1C) = 0;
            memset(*(void**)(self + 0x14), 0, 0xBF4);
            if (*(void**)(self + 0x18) != 0) {
                __dla__FPv(*(void**)(self + 0x18));
                *(void**)(self + 0x18) = 0;
            }
            *(int*)(self + 0x20) = 0;
        }

        if (arg1 != 0) {
            fn_80051440(*(u16*)(gg28 + 0x4920) * 0xA);
            *(u16*)(gg28 + 0x4920) = 0;
        }
        *(u8*)(gg28 + 0x4914) = 0;
        *(u8*)(gg28 + 0x4915) = 0;
    }
}
