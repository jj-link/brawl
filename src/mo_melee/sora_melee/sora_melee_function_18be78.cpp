#include <it/it_manager.h>
#include <nw4r/g3d/g3d_resfile.h>
#pragma force_active on

struct WorkModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
    virtual void f5(int, int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual float get(unsigned long);
};

struct SlotObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23(float);
};

struct Modules {
    unsigned char pad0[0xc];
    SlotObj* slotC;
    unsigned char pad10[0x54];
    WorkModule* work;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

struct SrcVec {
    float x, y, z;
};

struct SrcBlock {
    unsigned int flags;
    SrcVec v;
    unsigned char pad[0x3c];
};

extern "C" const float lbl_27_rodata_2578;
extern "C" void* fn_27_2AC0A4(itManager* it, int id);
extern "C" void fn_8019564C(void* dst, SrcBlock* src, int zero, float f);
extern "C" void fn_801956CC(SrcBlock* src, SrcVec* dst);

extern "C" void fn_27_18BE78(void*, Accesser* accesser) {
    int first = accesser->modules->work->f4(0x20000000);
    int last = accesser->modules->work->f4(0x20000001);
    accesser->modules->work->f5(first + 1, 0x20000000);
    if (first + 1 <= last) {
        int r30 = accesser->modules->work->f4(0x20000002);
        itManager* it = itManager::getInstance();
        nw4r::g3d::ResFile file(fn_27_2AC0A4(it, r30));
        nw4r::g3d::ResAnmChr anm = file.GetResAnmChr(0);
        SrcBlock sp1C;
        SrcVec sp10;
        fn_8019564C(&anm, &sp1C, 0, (float)(first + 1));
        fn_801956CC(&sp1C, &sp10);
        float f31 = accesser->modules->work->get(0x11000009);
        float f1 = accesser->modules->work->get(0x1100000A);
        float var;
        if (r30 == 0) {
            var = f31 + sp10.x * (f1 - f31);
        } else {
            var = f31 + (lbl_27_rodata_2578 - sp10.x) * (f1 - f31);
        }
        accesser->modules->slotC->f23(var);
    }
}
