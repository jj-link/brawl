#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_29510[];
extern "C" char lbl_27_data_CDF8[];
extern "C" float lbl_27_rodata_222C;

struct Object;
struct Modules;

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Target {
    char pad[0x34];
    int state;
};

struct Module7C {
    virtual void s0() = 0; virtual void s1() = 0; virtual void s2() = 0; virtual void s3() = 0;
    virtual void s4() = 0; virtual void s5() = 0; virtual void* s6(int) = 0;
};

struct Module8 {
    virtual void s0() = 0; virtual void s1() = 0; virtual void s2() = 0; virtual void s3() = 0;
    virtual void s4() = 0; virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0;
    virtual void s8() = 0; virtual void s9() = 0; virtual void s10() = 0; virtual void s11() = 0;
    virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0; virtual void s15() = 0;
    virtual void s16() = 0; virtual void s17() = 0; virtual void s18() = 0; virtual void s19() = 0;
    virtual void s20() = 0; virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0;
    virtual void s24() = 0; virtual void s25() = 0; virtual void s26() = 0; virtual void s27() = 0;
    virtual void s28() = 0; virtual void s29() = 0; virtual void s30() = 0; virtual void s31() = 0;
    virtual void s32() = 0; virtual void s33() = 0; virtual void s34() = 0; virtual void s35() = 0;
    virtual void s36() = 0; virtual void s37() = 0; virtual void s38() = 0; virtual void s39() = 0;
    virtual void s40() = 0; virtual void s41() = 0; virtual void s42() = 0; virtual void s43() = 0;
    virtual void s44() = 0; virtual void s45() = 0; virtual void s46() = 0; virtual void s47() = 0;
    virtual void s48() = 0; virtual void s49() = 0; virtual void s50() = 0; virtual void s51() = 0;
    virtual void s52() = 0; virtual void s53() = 0; virtual void s54() = 0; virtual void s55() = 0;
    virtual void s56() = 0; virtual void s57() = 0; virtual void s58() = 0; virtual void s59() = 0;
    virtual void s60() = 0; virtual void s61() = 0; virtual void s62() = 0; virtual void s63() = 0;
    virtual void s64() = 0; virtual void s65() = 0; virtual void s66() = 0;
    virtual Vec3 s67() = 0;
};

struct Module10 {
    int padding[2];

    virtual void s0() = 0; virtual void s1() = 0; virtual void s2() = 0; virtual void s3() = 0;
    virtual void s4() = 0; virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0;
    virtual void s8() = 0; virtual void s9() = 0; virtual void s10() = 0; virtual void s11() = 0;
    virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0; virtual void s15() = 0;
    virtual void s16() = 0; virtual void s17() = 0; virtual void s18() = 0; virtual void s19(int, int) = 0;
    virtual int s20(int) = 0; virtual void s21() = 0; virtual void s22() = 0; virtual void s23() = 0;
    virtual void s24() = 0; virtual void s25() = 0; virtual void s26() = 0; virtual void s27() = 0;
    virtual void s28() = 0; virtual void s29() = 0; virtual void s30() = 0; virtual void s31() = 0;
    virtual void s32() = 0; virtual void s33() = 0; virtual unsigned int s34(int) = 0; virtual void s35() = 0;
    virtual void s36() = 0; virtual void s37() = 0; virtual void s38(int) = 0; virtual void s39() = 0;
    virtual void s40() = 0; virtual void s41(int) = 0; virtual void s42() = 0; virtual void s43() = 0;
    virtual void s44() = 0; virtual void s45() = 0; virtual void s46() = 0; virtual void s47() = 0;
    virtual void s48() = 0; virtual void s49() = 0; virtual void s50() = 0; virtual void s51() = 0;
    virtual void s52() = 0; virtual void s53() = 0; virtual void s54() = 0; virtual unsigned int s55(int, int) = 0;
    virtual void s56() = 0; virtual void s57() = 0; virtual void s58() = 0; virtual void s59() = 0;
    virtual void s60() = 0; virtual void s61() = 0; virtual void s62() = 0; virtual void s63() = 0;
    virtual void s64() = 0; virtual void s65() = 0; virtual void s66() = 0; virtual void s67() = 0;
    virtual void s68() = 0; virtual void s69() = 0; virtual void s70() = 0; virtual void s71() = 0;
    virtual void s72() = 0; virtual void s73() = 0; virtual void s74() = 0; virtual void s75() = 0;
    virtual void s76() = 0; virtual void s77() = 0; virtual void s78() = 0; virtual void s79() = 0;
    virtual void s80() = 0; virtual void s81() = 0; virtual void s82() = 0; virtual void s83() = 0;
    virtual void s84() = 0; virtual void s85() = 0; virtual void s86() = 0; virtual void s87() = 0;
    virtual void s88() = 0; virtual void s89() = 0; virtual void s90() = 0; virtual void s91() = 0;
    virtual void s92() = 0; virtual void s93() = 0; virtual void s94() = 0; virtual void s95() = 0;
    virtual void s96() = 0; virtual void s97() = 0; virtual void s98() = 0; virtual void s99() = 0;
    virtual void s100() = 0; virtual void s101() = 0; virtual void s102() = 0; virtual void s103() = 0;
    virtual void s104() = 0; virtual void s105(int, int, int) = 0;
};

struct Module14 {
    virtual void s0() = 0; virtual void s1() = 0; virtual void s2() = 0; virtual int s3() = 0;
    virtual void s4() = 0; virtual void s5() = 0; virtual void s6(int, int) = 0;
};

struct Module64 {
    virtual void s0() = 0; virtual void s1() = 0; virtual void s2() = 0; virtual void s3() = 0;
    virtual void s4() = 0; virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0;
    virtual void s8() = 0; virtual void s9() = 0; virtual void s10() = 0; virtual void s11() = 0;
    virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0; virtual void s15() = 0;
    virtual void s16() = 0; virtual void s17() = 0; virtual void s18(int, Modules*) = 0;
};

struct Module70 {
    virtual void s0() = 0; virtual void s1() = 0; virtual void s2() = 0; virtual void s3(int, Object*) = 0;
    virtual void s4() = 0; virtual void s5() = 0; virtual void s6() = 0; virtual void s7() = 0;
    virtual void s8() = 0; virtual void s9() = 0; virtual void s10() = 0; virtual void s11() = 0;
    virtual void s12() = 0; virtual void s13() = 0; virtual void s14() = 0; virtual void s15() = 0;
    virtual int s16() = 0;
};

struct Modules {
    char pad00[0x8];
    Module8* m8;
    char pad0C[0x4];
    Module10* m10;
    Module14* m14;
    char pad18[0x4C];
    Module64* m64;
    char pad68[0x8];
    Module70* m70;
    char pad74[0x8];
    Module7C* m7C;
};

struct Object {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_27_170268(void*, Object* obj) {
    int v = obj->modules->m70->s16();
    switch (v) {
    case 0x75:
        if (obj->modules->m10->s55(8, 0) == 1) {
            obj->modules->m14->s6(0, 0);
            obj->modules->m70->s3(0, obj);
        }
        break;
    case 0x74:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
        {
            Target* t = (Target*)__dynamic_cast(obj->modules->m7C->s6(0), 0, lbl_27_data_29510, lbl_27_data_CDF8, 1);
            if (obj->modules->m10->s34(0) == 1) {
                unsigned int flag = 0;
                if (t->state == 0xB) {
                    const Vec3& vec = obj->modules->m8->s67();
                    if (vec.z >= lbl_27_rodata_222C && vec.y >= lbl_27_rodata_222C) {
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    t->state = 2;
                    obj->modules->m10->s105(9, 0, 0);
                    obj->modules->m14->s6(0, 0);
                    obj->modules->m10->s19(2, 0);
                    obj->modules->m10->s41(0);
                    obj->modules->m10->s38(0);
                    obj->modules->m64->s18(0x22000015, obj->modules);
                }
            } else {
                if (obj->modules->m14->s3() == 0) {
                    if ((unsigned char)obj->modules->m10->s20(0) == 4) {
                        t->state = 2;
                        obj->modules->m10->s105(9, 0, 0);
                        obj->modules->m10->s19(2, 0);
                        obj->modules->m10->s38(0);
                        obj->modules->m64->s18(0x22000015, obj->modules);
                    }
                } else if (obj->modules->m14->s3() == 1) {
                    obj->modules->m14->s6(2, 0);
                    obj->modules->m70->s3(0xE, obj);
                }
            }
        }
        break;
    }
}
