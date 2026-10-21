#include <types.h>
#pragma force_active on

extern "C" void fn_801F0208(int, const void*, int);

struct Obj {
    int pad0;
    int pad4;
    int offset8;
    unsigned char padC[0x11];
    unsigned char byte_1d;
};

extern "C" void fn_80192710(Obj** wrapper) {
    Obj* obj = *wrapper;
    if (!obj) return;
    const void* target = obj->offset8 ? (const void*)((char*)obj + obj->offset8) : nullptr;
    fn_801F0208(9, target, (int)obj->byte_1d);
}
