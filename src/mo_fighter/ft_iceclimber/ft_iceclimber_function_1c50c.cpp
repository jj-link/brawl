#pragma force_active on

struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Status {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void reset();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float get(unsigned int);
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 getPos();
};

struct Modules {
    char p0[0xc];
    Posture* posture;
    char p1[0x64 - 0x10];
    Work* work;
    char p2[0x7c - 0x68];
    Status* status;
};

struct Access {
    char pad[0xd8];
    Modules* mods;
};

struct Flag {
    unsigned char value;
};

struct Temp {
    char data[0x34];
};

extern "C" {
extern const float lbl_105_rodata_100;
extern const float lbl_105_rodata_104;
extern const double lbl_105_rodata_108;

Temp* fn_105_1C698(
    Temp*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, const Vec2*,
    unsigned char, unsigned char);
void* fn_105_1C734(void*, Temp*);
void fn_105_3710(Temp*, short);
void fn_105_1C720(void*, const Vec2*);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    Access*, unsigned long, unsigned long);
}

extern "C" void fn_105_1C50C(void*, char* owner, Access* access) {
    access->mods->status->reset();

    float h = access->mods->work->get(0x11000004);
    h -= access->mods->posture->getPos().y;

    int cnt = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        access, 0x5dc0, 0);

    Temp temp;
    float n = (float)cnt;

    Flag flag = {0};
    unsigned char* obj = (unsigned char*)(owner + 0x10);

    Vec2 e, d, c, b, a;
    a.x = lbl_105_rodata_100;
    a.y = lbl_105_rodata_100;
    b.x = lbl_105_rodata_104;
    b.y = lbl_105_rodata_104;
    c.x = lbl_105_rodata_100;
    c.y = lbl_105_rodata_100;
    d.x = lbl_105_rodata_104;
    d.y = lbl_105_rodata_104;
    e.x = lbl_105_rodata_104;
    e.y = lbl_105_rodata_104;

    fn_105_1C698(&temp, &e, &d, &c, &b, &a, 0, 0);
    fn_105_1C734(obj, &temp);
    fn_105_3710(&temp, 0);

    Vec2 vel;
    vel.x = lbl_105_rodata_104;
    vel.y = h / n;
    fn_105_1C720(obj, &vel);

    obj[5] |= 0x80;
}
