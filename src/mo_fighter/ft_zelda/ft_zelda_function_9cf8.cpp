#include <types.h>
#pragma force_active on

extern "C" int fn_27_135DE8(void*);

struct FtVirtObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(int, int, int);
};

extern "C" int fn_104_9CF8(void* self) {
    u8* p = reinterpret_cast<u8*>(self);
    u8* q = p + 0x20000;
    if (q[-0x798c] == 1) {
        return 1;
    }
    if (q[-0x798b] == 1) {
        u8* a = *reinterpret_cast<u8**>(p + 0x60);
        u8* b = *reinterpret_cast<u8**>(a + 0xd8);
        FtVirtObj* obj = *reinterpret_cast<FtVirtObj**>(b + 0x28);
        obj->vf13(0, 0, 2);
    }
    return fn_27_135DE8(self);
}
