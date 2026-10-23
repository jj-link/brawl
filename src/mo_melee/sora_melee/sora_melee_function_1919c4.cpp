#pragma force_active on
#pragma fp_contract off

typedef unsigned long u32;

#define VF1(n) virtual int v##n(int a = 0);
#define VF2(n) virtual int v##n(int a, void* b);

class VT {
public:
    VF1(0) VF1(1) VF1(2) VF1(3) VF1(4) VF1(5) VF1(6) VF1(7) VF1(8) VF1(9)
    VF1(10) VF1(11) VF1(12) VF1(13) VF1(14) VF2(15) VF1(16) VF1(17) VF1(18) VF2(19)
    VF1(20) VF1(21) VF1(22) VF1(23) VF1(24) VF1(25) VF1(26) VF1(27) VF1(28) VF1(29)
    VF1(30) VF1(31) VF1(32) VF1(33) VF1(34) VF1(35) VF1(36) VF1(37) VF1(38) VF1(39)
    VF1(40) VF1(41) VF1(42) VF1(43) VF1(44) VF1(45) VF1(46) VF1(47) VF1(48) VF1(49)
    VF1(50) VF1(51) VF1(52) VF1(53) VF1(54) VF1(55) VF1(56) VF1(57) VF1(58) VF1(59)
    VF1(60) VF1(61) VF1(62) VF1(63) VF1(64) VF1(65) VF1(66) VF1(67) VF1(68) VF1(69)
    VF1(70) VF1(71) VF1(72) VF1(73) VF1(74) VF1(75) VF1(76) VF1(77) VF1(78) VF1(79)
    VF1(80) VF1(81) VF1(82) VF1(83) VF1(84)
    virtual void v85(void*, void*);
    VF1(86) VF1(87)
    virtual unsigned int v88();
};

struct Other {
    char pad[0x28];
    int v28;
};

struct Mid {
    char p0[0x54];
    VT* a54;
    VT* a58;
    char p1[8];
    VT* a64;
    char p2[0x20];
    VT* a88;
};

struct Acc {
    char p0[8];
    Other* o8;
    char p1[0xCC];
    Mid* mD8;
};

struct Msg {
    int a;
    char b;
    int c;
    int d;
    char e;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern "C" const float lbl_27_rodata_2678;

extern "C" void fn_27_1919C4(void*, Acc* arg1) {
    if (arg1->mD8->a54->v9(4) != 0) {
        Msg s;
        s.a = 0x33;
        s.b = 0;
        s.c = 0;
        s.d = 0;
        s.e = 0;
        s.c = arg1->o8->v28;
        arg1->mD8->a54->v15(4, &s);
        arg1->mD8->a54->v8(4);
    }
    if (arg1->mD8->a54->v9(5) != 0) {
        if (arg1->mD8->a54->v88() == 1) {
            float f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg1, 0xD45, 0);
            float f1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg1, 0xD44, 0);
            Vec3 p;
            Vec3 q;
            p.x = f1;
            p.y = f31;
            p.z = lbl_27_rodata_2678;
            q.x = lbl_27_rodata_2678;
            q.y = lbl_27_rodata_2678;
            q.z = lbl_27_rodata_2678;
            arg1->mD8->a54->v85(&p, &q);
            arg1->mD8->a54->v87(1);
        }
        arg1->mD8->a54->v8(5);
    }
    arg1->mD8->a64->v19(0x12000001, arg1->mD8);
    arg1->mD8->a58->v7(1);
    arg1->mD8->a88->v33(1);
}
