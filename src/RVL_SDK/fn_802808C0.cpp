#include <types.h>
#pragma force_active on

extern "C" char lbl_80486450[];
extern "C" void* fn_80281430(void* obj, int a, int b, u8* p);

class SoHeapAllocator {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int size, int align, int extra);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Class_8028096C {
public:
    Class_8028096C(int, int, int, int);
    void* vtable;
    char pad4[2];
    s16 unk6;
    void* unk8;
};

Class_8028096C::Class_8028096C(int arg0, int arg1, int arg2, int arg3) {
    unk6 = 1;
    vtable = lbl_80486450;
    void* obj = lbl_805A0EB8->v4(0x1c, 0x18, arg2);
    ((s16*)obj)[2] = 0x1c;
    if (obj != 0) {
        u8 b = *(u8*)arg2;
        obj = fn_80281430(obj, arg0, arg1, &b);
    }
    unk8 = obj;
}
