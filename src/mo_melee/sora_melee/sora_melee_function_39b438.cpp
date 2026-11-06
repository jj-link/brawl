#include <types.h>
#pragma force_active on

class Work {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(u32, u32);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(u32, u32);
};

extern "C" void fn_27_39B438(u8* p, u32 a1, u32 a2, u32 a3) {
    u8* modules = *(u8**)(p + 0xd8);
    Work* work = *(Work**)(modules + 0x64);
    work->slot20(a1, 0x1200003D);
    work->slot5(a2, 0x10000040);
    work->slot5(a3, 0x10000041);
}
