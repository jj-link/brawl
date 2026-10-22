#include <types.h>
#pragma force_active on

extern "C" void fn_801BC4C0(void* self);
extern "C" void fn_801CD1C4(void* self);
extern "C" char lbl_80466CA8[];

extern "C" void* fn_801CF664(void* self, void* arg) {
    unsigned char* p = (unsigned char*)self;
    fn_801BC4C0(self);
    *(char**)p = lbl_80466CA8;
    fn_801CD1C4(p + 0xD8);
    *(void**)(p + 0x924) = arg;
    *(int*)(p + 0x920) = 0;
    return self;
}
