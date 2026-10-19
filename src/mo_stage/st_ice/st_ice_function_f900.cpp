#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Constants {
    float x[21];
};

extern "C" const Constants lbl_62_rodata_1B0;
extern "C" char lbl_62_data_563C[];

struct Attack {
    char pad[36];
    Vec v;
    int a, b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* data) {
        v.x = data->x[9];
        v.y = data->x[9];
        v.z = data->x[9];
        flags = 0;
    }
};

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

struct Pad {
    char p[0x3c];
};

#define V(n) virtual void v##n();

struct Ground : Pad {
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

    virtual void make(
        Attack*, int, Vec*, float, int, int, int, int,
        float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int
    );

    int getNodeIndex(unsigned long*, unsigned long, const char*);
};

#undef V

struct Obj : Ground {
    char q[0x14c - 0x40];
    void* module;
    char r[0x171 - 0x150];
    unsigned char done;
};

extern "C" void fn_62_F900(Obj* o) {
    const Constants* data = &lbl_62_rodata_1B0;
    if (o->done != 1) {
        Attack a(data);
        Vec p;
        unsigned long idx;

        o->getNodeIndex(&idx, 0, lbl_62_data_563C);
        p.x = data->x[0];
        p.y = data->x[0];
        p.z = data->x[0];

        o->make(
            &a, 15, &p, data->x[10], 90, 140, 0, 50,
            data->x[9], data->x[9], data->x[9],
            idx, 1023, 7, 0, 15, 0, 2, 2, 0,
            0, 0, 1, 0, 0, 0, 60, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
        );

        fn_27_2636F0(o->module, 0, 0, &a);
        o->done = 1;
    }
}
