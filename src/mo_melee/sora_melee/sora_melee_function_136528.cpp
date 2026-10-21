#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_29510[];
extern "C" char lbl_27_data_CDF8[];
extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_1058;

struct A {
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
    virtual void v12();
    virtual void v13();
    virtual void target();
};

struct B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual unsigned int target();
};

struct Vec {
    float x, y, z;
};

struct C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(int);
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void set(const Vec&, const short&);
};

extern "C" void fn_27_136528(void*, char* obj, float, float amount) {
    (*(A**)(*(char**)(obj + 0xd8) + 0x70))->target();

    if ((*(B**)(*(char**)(obj + 0xd8) + 0x48))->target() == 1U) {
        Vec v;
        v.x = lbl_27_rodata_1058;
        v.y = lbl_27_rodata_1048;
        v.z = lbl_27_rodata_1048;
        short mode = 1;

        (*(C**)(*(char**)(obj + 0xd8) + 0x7c))->set(v, mode);

        char* res = (char*)__dynamic_cast(
            (*(C**)(*(char**)(obj + 0xd8) + 0x7c))->get(0),
            0, lbl_27_data_29510, lbl_27_data_CDF8, 1);

        if (amount != *(float*)(res + 0x38)) {
            *(float*)(res + 0x44) = -*(float*)(res + 0x44);
            *(float*)(res + 0x38) = amount;
        }
    }
}
