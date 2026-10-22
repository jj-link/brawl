#pragma force_active on

typedef unsigned char u8;

struct Vec {
    float x, y, z;
};

struct Attack {
    char pad[0x24];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;
};

struct Rodata {
    float f0;
    char p[0x14];
    float f18;
    char q[4];
    float f20;
};

extern "C" const Rodata lbl_57_rodata_360;

#define V(n) virtual void f##n();

struct Pad {
    char p[0x3c];
};

struct Obj : Pad {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107) V(108)

    virtual void make(Attack*, int, Vec*, int, int, int, int,
        float, float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int);

    char q[0x14c - 0x40];
    void* module;
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_57_10DD0(u8* self) {
    const Rodata* d = &lbl_57_rodata_360;
    if (self[0x175] != 1) {
        Attack a;
        Vec p;
        a.v.x = d->f18;
        a.v.y = d->f18;
        a.v.z = d->f18;
        a.flags = 0;
        p.x = d->f0;
        p.y = d->f0;
        p.z = d->f0;
        ((Obj*)self)->make(&a, 0xA, &p, 0x169, 0x50, 0, 0x46, d->f20, d->f18, d->f18, d->f18,
             *(int*)(self + 0xc4), 0x3FF, 7, 0, 0xF, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0x3C,
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        fn_27_2636F0(*(void**)(self + 0x14c), 0, 0, &a);
        self[0x175] = 1;
    }
}
