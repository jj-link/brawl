#include <types.h>
#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, u32 flag);

inline void copyPosition(char* q, char* src) {
    *(float*)(q + 0x8) = *(float*)(src + 0x14);
    *(float*)(q + 0xc) = *(float*)(src + 0x18);
    *(float*)(q + 0x10) = *(float*)(src + 0x1c);
}

extern "C" void fn_66_104DC(void* self) {
    char* p = (char*)self;
    char* base = p + 0xd0;
    if (base != 0) {
        char* model = *(char**)(*(char**)(p + 0x44));
        if (model != 0) {
            if (*(unsigned int*)(model + 0x11c) == 0) {
                *(unsigned int*)(base + 0xc) = 0;
                *(unsigned int*)(model + 0x11c) = (unsigned int)base;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(unsigned short*)(model + 0x122) = *(unsigned int*)(*(unsigned int**)(base + 4));
            }
            if (*(char**)(p + 0x164) != 0) {
                copyPosition(*(char**)(base + 4), *(char**)(p + 0x164));
                *(float*)(*(char**)(base + 4) + 0x18) = *(float*)(*(char**)(p + 0x164) + 0x20);
            }
        }
    }
}
