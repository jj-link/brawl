#pragma force_active on

struct Constants {
    float zero, one, offset, unused;
};

struct Vec3 {
    float x, y, z;
};

struct Effect {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void request(unsigned long, int, Vec3*, Vec3*, float,
                         Vec3*, Vec3*, bool, bool);
};

struct Modules {
    char pad[0x88];
    Effect* effect;
};

struct Accesser {
    char pad[8];
    void* owner;
    char pad2[0xCC];
    Modules* modules;
};

extern "C" {
extern const char lbl_95_data_5F8[];
extern const char lbl_95_data_36D8[];
extern const Constants lbl_95_rodata_38;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_AE3C(void*);
Vec3* fn_95_ABB4(Vec3*, float, float, float);

void fn_95_F798(void*, Accesser* accesser, int status) {
    const Constants* values = &lbl_95_rodata_38;
    if (status != 0x1B) {
        fn_95_AE3C(__dynamic_cast(accesser->owner, 0x3C,
                                 lbl_95_data_5F8, lbl_95_data_36D8,
                                 short(1)));

        Effect* effect = accesser->modules->effect;
        Vec3 a, b, c, d;

        effect->request(
            0x50003, 0,
            fn_95_ABB4(&a, values->zero, values->zero, values->zero),
            fn_95_ABB4(&b, values->zero, values->zero, values->zero),
            values->one,
            fn_95_ABB4(&c, values->zero, values->zero, values->zero),
            fn_95_ABB4(&d, values->zero, values->offset, values->zero),
            0, 0);
    }
}
}
