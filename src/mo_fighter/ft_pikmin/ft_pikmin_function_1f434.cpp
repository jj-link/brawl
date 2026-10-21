#pragma force_active on
#pragma opt_propagation off

struct Vec2 {
    float x, y;
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

struct Modules {
    char pad[0x7c];
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
extern const float lbl_113_rodata_88[];

Temp* fn_113_1E0A0(
    Temp*, const Vec2*, const Vec2*, const Vec2*,
    const Vec2*, const Vec2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
}

extern "C" void fn_113_1F434(void*, char* owner, Access* access) {
    const float* c = lbl_113_rodata_88;
    access->mods->status->reset();

    Flag flag = {0};
    char* obj = owner + 0x10;
    Vec2 e, d, v, b, a;

    a.x = c[3];
    a.y = c[3];
    b.x = c[2];
    b.y = c[2];
    v.x = c[3];
    v.y = c[3];
    d.x = c[2];
    d.y = c[2];
    e.x = c[2];
    e.y = c[2];

    Temp temp;
    fn_113_1E0A0(&temp, &e, &d, &v, &b, &a, 0, 0);
    fn_113_1E164(obj, &temp);
    fn_113_4730(&temp, 0);

    obj[5] |= 0x80;
    Flag flag2 = {0};

    *(float*)(owner + 0x58) = c[7];
    *(float*)(owner + 0x5c) = c[8];
    *(float*)(owner + 0x60) = c[2];
    owner[0x55] |= 0x80;
}
