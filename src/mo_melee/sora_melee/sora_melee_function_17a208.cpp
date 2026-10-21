#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_2E5F8[];
extern "C" char lbl_27_data_CDF8[];

struct Module7C {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void* get(int) = 0;
};

struct Module64 {
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual int get(int) = 0;
    virtual void set(int, int) = 0;
};

struct Module10 {
    int padding[2];

    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual void s23() = 0;
    virtual void s24() = 0;
    virtual void s25() = 0;
    virtual void s26() = 0;
    virtual void s27() = 0;
    virtual void s28() = 0;
    virtual void set(int, int) = 0;
};

struct Modules {
    char pad00[0x10];
    Module10* module10;
    char pad14[0x50];
    Module64* module64;
    char pad68[0x14];
    Module7C* module7C;
};

struct Object {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_27_17A208(void*, Object* object) {
    unsigned char* p = (unsigned char*)__dynamic_cast(
        object->modules->module7C->get(3),
        0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    p[5] |= 0x80;

    int value = object->modules->module64->get(0x20000000);
    switch (value) {
    case 0x7E:
    case 0x7F:
    case 0x80:
        value = 0x80;
        break;
    case 0x81:
    case 0x82:
    case 0x83:
        value = 0x83;
        break;
    }

    object->modules->module64->set(value, 0x20000000);
    object->modules->module10->set(1, 0);
}
