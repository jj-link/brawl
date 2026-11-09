#pragma force_active on
#include <types.h>

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* lbl_805A0EC8;
extern "C" void fn_802F5994(s32, s32, void*);

struct Class_802F5930 {
    void* ptr;
    s32 size;
    s32 capacity;

    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, ptr, (capacity & 0x3FFFFFFF) * 0x24, 0x15); }
};

extern "C" void fn_802F5930(s32 arg0, s32 arg1, void* arg2) {
    Class_802F5930 local;
    local.ptr = arg2;
    local.size = 1;
    local.capacity = 0x80000001;
    fn_802F5994(arg0, arg1, &local);
    if (local.isOwned()) local.dealloc();
}
