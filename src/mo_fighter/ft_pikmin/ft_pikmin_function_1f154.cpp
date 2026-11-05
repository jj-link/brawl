#pragma force_active on
#include <mt/mt_vector.h>

struct PikSpeed {
    float x, y;
};

struct Flag {
    unsigned char value;
};

struct Access;

struct Pad8 {
    char pad[8];
};

struct ValueX : Pad8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float v4(Access* access, unsigned int id, unsigned int index);
};

struct Status {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11();
    virtual void v12();
    virtual PikSpeed v13(short* p);
};

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual ValueX* v23();
};

struct Modules {
    char p0[0x64];
    Work* work;
    char p1[0x7c - 0x68];
    Status* status;
};

struct Access {
    char pad[0xd8];
    Modules* mods;
};

extern "C" {
extern const float lbl_113_rodata_90;
void fn_113_BC00(Vec2f*, const Vec2f*);
float fn_113_22580(void*);
float fn_113_225F4(void*);
float fn_113_22668(void*);
}

extern "C" void fn_113_1F154(void*, char* owner, Access* access) {
    short spA = 1;
    Vec2f speed;
    PikSpeed sum = access->mods->status->v13(&spA);
    Vec2f::copy(speed, *reinterpret_cast<const Vec2f*>(&sum));
    access->mods->status->v12();
    ValueX* value = access->mods->work->v23();
    Flag flag = {0};
    Vec2f a;
    a.m_x = speed.m_x;
    a.m_y = lbl_113_rodata_90;
    fn_113_BC00((Vec2f*)(owner + 0x18), &a);
    Vec2f b;
    b.m_x = fn_113_22580(access);
    b.m_y = lbl_113_rodata_90;
    fn_113_BC00((Vec2f*)(owner + 0x28), &b);
    Vec2f c;
    c.m_x = fn_113_225F4(access);
    c.m_y = lbl_113_rodata_90;
    fn_113_BC00((Vec2f*)(owner + 0x30), &c);
    Vec2f d;
    d.m_x = fn_113_22668(access);
    d.m_y = lbl_113_rodata_90;
    fn_113_BC00((Vec2f*)(owner + 0x38), &d);
    owner[0x15] |= 0x80;
    Flag flag2 = {0};
    *(float*)(owner + 0x58) = value->v4(access, 0xfd2, 0);
    *(float*)(owner + 0x5c) = -value->v4(access, 0xfd4, 0);
    *(float*)(owner + 0x60) = value->v4(access, 0xfd5, 0);
    owner[0x55] |= 0x80;
}
