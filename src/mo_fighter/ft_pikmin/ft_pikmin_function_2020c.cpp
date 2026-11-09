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
    virtual float v4(Access* access, unsigned int id, unsigned int index);
};

struct Status {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
};

struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual float v9();
};

struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16();
    virtual unsigned int v17(unsigned int flag);
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual ValueX* v23();
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

extern "C" void fn_113_2020C(void* arg1, char* owner, Access* access) {
    char* obj;
    access->mods->status->v12();
    ValueX* value = access->mods->work->v23();
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
    float f = value->v4(access, 0xfd8, 0);
    if (access->mods->posture->v9() >= lbl_113_rodata_90) {
        f = -f;
    }
    Vec2 vel;
    vel.x = f;
    vel.y = lbl_113_rodata_90;
    fn_113_BC00((Vec2*)(obj + 8), &vel);
    obj[5] |= 0x80;
}
