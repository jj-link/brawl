#pragma force_active on

typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_13690[];
extern "C" char lbl_27_data_CDF8[];
extern const f32 lbl_27_rodata_2328;
extern "C" void fn_27_174C08(s32, void*, void*);
extern "C" void fn_27_17496C(void*, void*, s32);

struct Access64 {
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
    virtual f32 get(int);
};

struct Access7C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* set(int);
};

struct Access58 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void set(int);
};

struct Mid {
    char pad[0x58];
    Access58* a58;
    char pad2[8];
    Access64* a64;
    char pad3[0x14];
    Access7C* a7c;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Vec3 {
    f32 x, y, z;
};

struct Words {
    s32 x, y, z;
};

struct Params {
    s32 a, b;
    Vec3 v;
    f32 f, g, h, i;
};

extern "C" void fn_27_178524(void* arg0, Obj* arg1, s32 arg2) {
    if (arg2 == 11) {
        Params p;
        Vec3 t;

        f32 hi = arg1->mid->a64->get(0x21000005);
        f32 lo = arg1->mid->a64->get(0x21000004);
        f32 vals[2];
        vals[0] = lo;
        vals[1] = hi;

        void* o = arg1->mid->a7c->set(3);
        char* res = (char*)__dynamic_cast(
            o, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);

        *(f32*)(res + 8) = vals[0];
        *(f32*)(res + 12) = vals[1];
        *(u8*)(res + 5) |= 0x80;

        t.x = lbl_27_rodata_2328;
        t.y = lbl_27_rodata_2328;
        t.z = lbl_27_rodata_2328;

        p.a = 30;
        p.b = 0;
        *(Words*)&p.v = *(Words*)&t;
        fn_27_174C08((s32)arg0, &p, arg1);
    }

    arg1->mid->a58->set(1);
    fn_27_17496C(arg0, arg1, arg2);
}
