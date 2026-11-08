#pragma force_active on
#include <types.h>

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* lbl_805A0EC8;

class Class_802D75E0 {
public:
    Class_802D75E0() {}
    ~Class_802D75E0() {
        if (isOwned()) dealloc();
    }

    void* ptr;
    s32 size;
    s32 capacity;

    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, ptr, capacity * 4, 0x15); }
};

extern "C" void fn_8032B8DC(s32, s32, Class_802D75E0*);

extern "C" void fn_8032BB7C(s32 arg0, s32 arg1, void* arg2) {
    Class_802D75E0 local0;
    local0.ptr = arg2;
    local0.size = 1;
    local0.capacity = 0x80000001;
    fn_8032B8DC(arg0, arg1, &local0);
}
