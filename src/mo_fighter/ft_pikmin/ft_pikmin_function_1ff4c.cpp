#pragma force_active on
#pragma opt_propagation off

struct Vec2 {
    float x, y;
};

struct Temp {
    char data[0x34];
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
    virtual float get(Access* access, unsigned int id, unsigned int index);
};

struct Status {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void reset();
};

struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual float lr();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual float getScale();
};

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual ValueX* accessor();
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

extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_94;
Temp* fn_113_1E0A0(Temp*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
void fn_113_BC00(Vec2*, const Vec2*);
}

extern "C" void fn_113_1FF4C(void*, char* owner, Access* access) {
    char* obj;
    access->mods->status->reset();
    ValueX* value = access->mods->work->accessor();
    Flag flag = {0};
    obj = owner + 0x10;

    Vec2 e, d, c, b, a;
    a.x = lbl_113_rodata_94;
    a.y = lbl_113_rodata_94;
    b.x = lbl_113_rodata_90;
    b.y = lbl_113_rodata_90;
    c.x = lbl_113_rodata_94;
    c.y = lbl_113_rodata_94;
    d.x = lbl_113_rodata_90;
    d.y = lbl_113_rodata_90;
    e.x = lbl_113_rodata_90;
    e.y = lbl_113_rodata_90;
    Temp temp;
    fn_113_1E0A0(&temp, &e, &d, &c, &b, &a, 0, 0);
    fn_113_1E164(obj, &temp);
    fn_113_4730(&temp, 0);

    float f = value->get(access, 0xfdc, 0);
    f = f * access->mods->posture->getScale();
    if (access->mods->posture->lr() < lbl_113_rodata_90) {
        f = -f;
    }
    Vec2 vel;
    vel.x = f;
    vel.y = lbl_113_rodata_90;
    fn_113_BC00((Vec2*)(obj + 8), &vel);

    int sign;
    if (access->mods->posture->lr() < lbl_113_rodata_90) {
        sign = -1;
    } else {
        sign = 1;
    }
    float direction = (float)sign;
    float g = value->get(access, 0xfdd, 0);
    g = g * direction;
    g = g * access->mods->posture->getScale();
    Vec2 vel2;
    vel2.x = g;
    vel2.y = lbl_113_rodata_90;
    fn_113_BC00((Vec2*)(obj + 0x10), &vel2);

    Vec2 vel3;
    vel3.x = lbl_113_rodata_94;
    vel3.y = lbl_113_rodata_94;
    fn_113_BC00((Vec2*)(obj + 0x18), &vel3);

    Vec2 vel4;
    vel4.x = value->get(access, 0xfde, 0);
    vel4.y = lbl_113_rodata_94;
    fn_113_BC00((Vec2*)(obj + 0x20), &vel4);

    Vec2 vel5;
    vel5.x = value->get(access, 0xfdf, 0);
    vel5.y = lbl_113_rodata_90;
    fn_113_BC00((Vec2*)(obj + 0x28), &vel5);

    obj[5] |= 0x80;
}
