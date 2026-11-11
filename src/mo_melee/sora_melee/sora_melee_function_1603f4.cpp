#include <types.h>
#pragma force_active on

union PairBits {
    unsigned long long q;
    struct {
        u32 hi;
        u32 lo;
    } w;
};

union FloatBits {
    u32 u;
    float f;
};

struct Vec2f {
    float x;
    float y;
};

class SubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual unsigned long long eval();

    unsigned char pad0;
    unsigned char on : 1;
    unsigned char low : 7;
    unsigned char pad1[2];
    float data0;
    float data1;

    unsigned int isOn() const {
        return on != 0;
    }
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int);
};

struct MidObj {
    char pad[0xc];
    Object_vptr_0* inner;
    char pad2[0x54];
    Object_vptr_0* target;
};

struct AccObj {
    char pad[0xd8];
    MidObj* mid;
};

struct SrcVec {
    float x;
    float y;
};

struct Args {
    char pad0[0x10];
    SubObj subA;
    char padA[0x4c];
    SubObj subB;
    char pad1[0x24];
    SubObj subC;
    char pad2[0x48];
    SubObj subD;
};

extern "C" int fn_27_195EA8(void*);
extern "C" const float lbl_27_rodata_1FC0;

extern "C" void fn_27_1603F4(SrcVec* arg0, Args* arg1, AccObj* arg2) {
    if (fn_27_195EA8(arg2) != 0) {
        float val = arg2->mid->inner->slot9();
        float f31 = arg0->y;
        float f30 = arg0->x * val;

        if (lbl_27_rodata_1FC0 != f31) {
            SubObj* b = &arg1->subB;
            if (b->isOn() == 1) {
                Vec2f p;
                *(unsigned long long*)&p = b->eval();
                b->data1 = f31 + p.y;
                arg2->mid->target->slot19(0x22000002);
            } else {
                SubObj* d = &arg1->subD;
                if (d->isOn() == 1) {
                    Vec2f result;
                    Vec2f p2;
                    Vec2f p1;
                    *(unsigned long long*)&p1 = d->eval();
                    f31 += p1.y;
                    *(unsigned long long*)&p2 = d->eval();
                    result.x = p2.x;
                    result.y = f31;
                    d->data0 = result.x;
                    d->data1 = result.y;
                } else {
                    SubObj* a = &arg1->subA;
                    if (a->isOn() == 1) {
                        Vec2f result;
                        Vec2f p2;
                        Vec2f p1;
                        *(unsigned long long*)&p1 = a->eval();
                        f31 += p1.y;
                        *(unsigned long long*)&p2 = a->eval();
                        result.x = p2.x;
                        result.y = f31;
                        a->data0 = result.x;
                        a->data1 = result.y;
                    }
                }
            }
        }

        if (lbl_27_rodata_1FC0 != f30) {
            SubObj* c = &arg1->subC;
            if (c->isOn() == 1) {
                Vec2f result;
                Vec2f p;
                *(unsigned long long*)&p = c->eval();
                result.x = f30 + p.x;
                result.y = lbl_27_rodata_1FC0;
                c->data1 = result.y;
                c->data0 = result.x;
                arg2->mid->target->slot19(0x22000002);
            } else {
                SubObj* d = &arg1->subD;
                if (d->isOn() == 1) {
                    Vec2f result;
                    Vec2f p2;
                    Vec2f p1;
                    *(unsigned long long*)&p1 = d->eval();
                    float first = p1.y;
                    *(unsigned long long*)&p2 = d->eval();
                    result.y = first;
                    result.x = f30 + p2.x;
                    d->data0 = result.x;
                    d->data1 = result.y;
                } else {
                    SubObj* a = &arg1->subA;
                    if (a->isOn() == 1) {
                        Vec2f result;
                        Vec2f p2;
                        Vec2f p1;
                        *(unsigned long long*)&p1 = a->eval();
                        float first = p1.y;
                        *(unsigned long long*)&p2 = a->eval();
                        result.y = first;
                        result.x = f30 + p2.x;
                        a->data0 = result.x;
                        a->data1 = result.y;
                    }
                }
            }
        }
    }
}
