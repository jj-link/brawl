#include <types.h>
#pragma force_active on

struct Pad8 {
    s32 a;
    s32 b;
};

class ObjA : public Pad8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(void* p);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
};

class ObjB {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
};

extern "C" void fn_27_60D4(void* self) {
    u8* base = (u8*)self;
    u8* p = *(u8**)(base + 0x60);
    ObjA* o1 = *(ObjA**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0x4);
    o1->s5(p);

    ObjB* o2 = *(ObjB**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0xa4);
    o2->s5();

    ObjB* o3 = *(ObjB**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0x58);
    o3->s5();

    ObjA* o4 = *(ObjA**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0x9c);
    o4->s15();

    ObjB* o5 = *(ObjB**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0xac);
    o5->s5();

    ObjA* o6 = *(ObjA**)(*(u8**)(*(u8**)(base + 0x60) + 0xd8) + 0x4);
    o6->s6();
}
