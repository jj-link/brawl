#pragma force_active on
#include <mt/mt_vector.h>

struct Vec3 { float x, y, z; };

extern "C" void fn_27_28DDC0(void*, int);

#define P(n) virtual void p##n();
#define P10(n) P(n##0) P(n##1) P(n##2) P(n##3) P(n##4) P(n##5) P(n##6) P(n##7) P(n##8) P(n##9)
#define P100(n) P10(n##0) P10(n##1) P10(n##2) P10(n##3) P10(n##4) P10(n##5) P10(n##6) P10(n##7) P10(n##8) P10(n##9)

struct Pad8 { u32 pad[2]; };

struct AttrFlag {
    u16 m_mask;
    AttrFlag(u16 bits) : m_mask(bits) {}
};

class M0C {
public:
    P(0) P(1) P(2) P(3)
    virtual Vec3 getPos();
    P(5) P(6) P(7) P(8)
    virtual float getF();
};

class M14 {
public:
    P(0) P(1) P(2)
    virtual u8 getKind();
};

class M7C {
public:
    P10(a) P(b0) P(b1) P(b2)
    virtual Vec2f getSumSpeed(AttrFlag);
};

class M64 {
public:
    P(0) P(1) P(2) P(3)
    virtual int getInt(int);
    virtual void setInt(int, int);
    P(6) P(7) P(8) P(9) P(10) P(11)
    virtual float getFloat(int);
    P(13) P(14) P(15) P(16)
    virtual bool isFlag(int);
};

class M08 {
public:
    P10(a) P(b0) P(b1)
    virtual float getF();
};

class M20 {
public:
    P10(a) P10(b) P10(c) P(d0)
    virtual int get(int);
};

class M5C {
public:
    P10(a) P10(b) P10(c) P10(d) P10(e) P(f0)
    virtual float get(int);
};

class MB8 : public Pad8 {
public:
    P10(a)
    virtual int get30();
    virtual int get34();
    P(c2) P(c3) P(c4) P(c5) P(c6)
    virtual int get4C();
    P(d8)
    virtual int get54();
};

class M60 {
public:
    P10(a) P10(b) P10(c) P10(d) P(e0) P(e1) P(e2) P(e3) P(e4) P(e5) P(e6)
    virtual void getC4(void*, int);
    virtual Vec3 getC8(int);
};

struct Obj {
    char pad[0x8bc];
    int val;
};

struct Item {
    int kind;
    Obj* obj;
    char pad[0xc];
};

class MA8 {
public:
    P10(a) P(b0) P(b1) P(b2) P(b3)
    virtual u32 check(int);
    P(b5) P(b6) P(b7) P(b8) P(b9) P(c0)
    virtual void get5C(Item*, int);
    P10(d) P10(e) P(f0) P(f1) P(f2) P(f3) P(f4)
    virtual int count();
    virtual void getItem(Item*, int);
    P(f9) P(g0)
    virtual void setD4(int, int, int);
    virtual void setD8(int, int, int);
};

class M38 : public Pad8 {
public:
    P10(a) P10(b) P10(c) P(d0) P(d1) P(d2) P(d3)
    virtual void set(void*);
};

struct Modules {
    char pad00[0x8];
    M08* m08;
    M0C* m0C;
    char pad10[0x4];
    M14* m14;
    char pad18[0x8];
    M20* m20;
    char pad24[0x14];
    M38* m38;
    char pad3C[0x20];
    M5C* m5C;
    M60* m60;
    M64* m64;
    char pad68[0x14];
    M7C* m7C;
    char pad80[0x28];
    MA8* mA8;
    char padAC[0xC];
    MB8* mB8;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct SelfBase { char pad[0x3c]; };

class Self : public SelfBase {
public:
    P100(a) P10(b0) P10(b1) P10(b2) P10(b3) P10(b4) P10(b5) P10(b6) P(c0)
    virtual u32 getMask();
    P(c1) P(c2)
    virtual int getFC();

    char pad40[0x20];
    Accesser* acc;
};

struct Out {
    Vec3 pos;
    float f0C;
    u8 b10; char p11[3];
    Vec2f speed1;
    Vec2f speed2;
    char x24[0x28];
    int i4C, i50, i54;
    float f58;
    int p5C;
    int i60;
    float f64;
    int i68, i6C, i70, i74;
    u8 b78; char p79[3];
    int i7C, i80;
    u8 b84; char p85[3];
    int i88;
    float f8C;
    u8 b90; char p91[3];
    int i94, i98;
    u8 b9C; char p9D[3];
    float fA0, fA4;
    u8 bA8; char pA9[3];
    int iAC, iB0;
    u8 bB4; char pB5[3];
    int iB8, iBC;
    u8 bC0; char pC1[3];
    int iC4;
    int count;
    int arr[4];
    char xDC[0x10];
    Vec3 posEC;
    u8 bF8; char pF9[3];
    int iFC;
};

extern "C" void fn_27_13CC24(Self* self, Out* out) {
    Accesser* acc = self->acc;
    u32 mask = self->getMask();

    out->f0C = acc->modules->m0C->getF();
    const Vec3& pos = acc->modules->m0C->getPos();
    out->pos.x = pos.x;
    out->pos.y = pos.y;
    out->pos.z = pos.z;
    out->b10 = acc->modules->m14->getKind();
    out->speed1 = acc->modules->m7C->getSumSpeed(AttrFlag(1));
    out->speed2 = acc->modules->m7C->getSumSpeed(AttrFlag(2));
    out->i4C = acc->modules->m64->getInt(0x10000001);
    out->i50 = acc->modules->m64->getInt(0x10000003);
    out->i54 = acc->modules->m64->getInt(0x10000005);
    out->f58 = acc->modules->m08->getF();
    out->i60 = acc->modules->m64->getInt(0x1000002D);
    out->f64 = acc->modules->m64->getFloat(0x11000003);
    out->i68 = acc->modules->m64->getInt(0x10000023);
    out->i6C = acc->modules->m64->getInt(0x10000024);
    out->i70 = acc->modules->m64->getInt(0x10000021);
    out->i74 = acc->modules->m20->get(0);
    out->b78 = acc->modules->m64->isFlag(0x1200000E);
    out->i7C = acc->modules->m64->getInt(0x1000001E);
    if (mask & 0x100) {
        out->i80 = acc->modules->m64->getInt(0x1000001F);
        acc->modules->m64->setInt(-1, 0x1000001F);
    }
    out->b84 = acc->modules->m64->isFlag(0x12000012);
    out->i88 = acc->modules->m64->getInt(0x10000025);
    out->f8C = acc->modules->m64->getFloat(0x1100000C);
    out->b90 = acc->modules->m64->isFlag(0x1200000A);
    out->i94 = acc->modules->m64->getInt(0x10000019);
    if (mask & 0x400) {
        out->i98 = acc->modules->m64->getInt(0x1000002E);
        acc->modules->m64->setInt(-1, 0x1000002E);
    }
    out->b9C = acc->modules->m64->isFlag(0x12000009);
    out->fA0 = acc->modules->m5C->get(1);
    out->fA4 = acc->modules->m64->getFloat(0x11000006);
    if (mask & 0x40) {
        out->bA8 = acc->modules->m64->isFlag(0x12000026);
        out->iAC = acc->modules->mB8->get30();
        out->iB0 = acc->modules->mB8->get34();
        out->bC0 = acc->modules->m64->isFlag(0x12000027);
        out->bB4 = acc->modules->m64->isFlag(0x12000028);
        out->iB8 = acc->modules->mB8->get4C();
        out->iBC = acc->modules->mB8->get54();
    }
    acc->modules->m60->getC4(out->xDC, 0);
    const Vec3& pos2 = acc->modules->m60->getC8(0);
    out->posEC.x = pos2.x;
    out->posEC.y = pos2.y;
    out->posEC.z = pos2.z;
    out->bF8 = acc->modules->m64->isFlag(0x12000008);
    if (mask & 0x8) {
        if (acc->modules->mA8->check(0) == 1) {
            Item item;
            acc->modules->mA8->get5C(&item, 0);
            acc->modules->mA8->setD4(0, 0, 1);
            out->iC4 = item.obj->val;
            fn_27_28DDC0(item.obj, 0);
        }
        for (int i = acc->modules->mA8->count() - 1; i >= 0; i--) {
            Item item;
            acc->modules->mA8->getItem(&item, i);
            if (item.kind != 0x2F) {
                acc->modules->mA8->setD8(i, 0, 1);
                out->arr[out->count] = item.obj->val;
                out->count++;
                fn_27_28DDC0(item.obj, 0);
            }
        }
    }
    out->iFC = self->getFC();
    acc->modules->m38->set(out->x24);
}
