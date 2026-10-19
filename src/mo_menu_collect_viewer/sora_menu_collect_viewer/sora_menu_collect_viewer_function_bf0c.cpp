#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);

void* fn_6_BF0C(void* p) {
    char* self = (char*)p;
    void* task = *(void**)(self + 0x140);
    if (*(s32*)((char*)task + 0x104) == 3) {
        exit__6gfTaskFv(task);
        *(void**)(self + 0x140) = nullptr;
        return (void*)0xc;
    }
    return *(void**)(self + 0x128);
}
}
