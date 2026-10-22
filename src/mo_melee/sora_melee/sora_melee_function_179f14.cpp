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

struct Module70 {
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
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual int get(int) = 0;
};

struct Module5C {
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
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual void s32() = 0;
    virtual void s33() = 0;
    virtual void s34() = 0;
    virtual void s35() = 0;
    virtual void s36() = 0;
    virtual void s37() = 0;
    virtual void s38() = 0;
    virtual void s39() = 0;
    virtual void s40() = 0;
    virtual void s41() = 0;
    virtual void s42() = 0;
    virtual void s43() = 0;
    virtual void s44() = 0;
    virtual void s45() = 0;
    virtual void s46() = 0;
    virtual void s47() = 0;
    virtual void s48() = 0;
    virtual void s49() = 0;
    virtual void s50() = 0;
    virtual void s51() = 0;
    virtual void s52() = 0;
    virtual void s53() = 0;
    virtual void s54() = 0;
    virtual void s55(int, int, int, int) = 0;
};

struct Modules {
    char pad00[0x10];
    Module10* module10;
    char pad14[0x48];
    Module5C* module5C;
    char pad60[0x4];
    Module64* module64;
    char pad68[0x8];
    Module70* module70;
    char pad74[0x8];
    Module7C* module7C;
};

struct Object {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_27_179F14(void*, Object* obj) {
    unsigned char* p = (unsigned char*)__dynamic_cast(
        obj->modules->module7C->get(3),
        0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    p[5] |= 0x80;

    int value = obj->modules->module64->get(0x20000000);
    switch (value) {
    case 0x7E:
    case 0x80:
        value = 0x7F;
        break;
    case 0x81:
    case 0x83:
        value = 0x82;
        break;
    }

    obj->modules->module64->set(value, 0x20000000);
    obj->modules->module10->set(1, 0);

    if (obj->modules->module70->get(0) == 0x3D) {
        obj->modules->module5C->s55(4, 0, 1, -1);
    }
}
