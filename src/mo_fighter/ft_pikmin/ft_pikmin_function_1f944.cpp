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

struct Temp {
    char data[0x34];
};

struct Flag {
    unsigned char value;
};

extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_94;

Temp* fn_113_1E0A0(
    Temp*, const Vec2*, const Vec2*, const Vec2*,
    const Vec2*, const Vec2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
}

extern "C" void fn_113_1F944(void* arg1, void* arg2, Access* access) {
    access->mods->status->reset();
    
    Flag flag = {0};
    char* obj = (char*)arg2 + 0x10;
    Vec2 e, d, v, b, a;
    
    a.x = lbl_113_rodata_94;
    a.y = lbl_113_rodata_94;
    b.x = lbl_113_rodata_90;
    b.y = lbl_113_rodata_90;
    v.x = lbl_113_rodata_94;
    v.y = lbl_113_rodata_94;
    d.x = lbl_113_rodata_90;
    d.y = lbl_113_rodata_90;
    e.x = lbl_113_rodata_90;
    e.y = lbl_113_rodata_90;
    
    Temp temp;
    fn_113_1E0A0(&temp, &e, &d, &v, &b, &a, 0, 0);
    fn_113_1E164(obj, &temp);
    fn_113_4730(&temp, 0);
    
    obj[5] |= 0x80;
}