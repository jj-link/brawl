#pragma force_active on
#pragma opt_propagation off

struct Vec2 {
    float x, y;
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
};

struct Modules {
    char pad[0x7c];
    Object_vptr_0* status;
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
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_94;

Temp* fn_113_1E0A0(
    Temp*, const Vec2*, const Vec2*, const Vec2*,
    const Vec2*, const Vec2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
}

extern "C" void fn_113_1F360(void*, void* arg2, Access* access) {
    access->mods->status->slot12();

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
