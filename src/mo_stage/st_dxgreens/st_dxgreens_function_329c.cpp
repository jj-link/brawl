#pragma force_active on

typedef unsigned char u8;

struct Vec {
    float x, y, z;
};

struct Constants {
    float x[16];
};

extern "C" const Constants lbl_79_rodata_10;

struct Attack {
    char pad[36];
    Vec v;
    int a, b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* data) {
        v.x = data->x[13];
        v.y = data->x[13];
        v.z = data->x[13];
        flags = 0;
    }
};

struct Block {
    Vec a, pos;
    u8 id, state, kind, pad;
};

struct Pad {
    char p[0x3c];
};

#define D(n) virtual void d##n();

struct Obj : Pad {
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23)
    D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31)
    D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47)
    D(48) D(49) D(50) D(51) D(52) D(53) D(54) D(55)
    D(56) D(57) D(58) D(59) D(60) D(61) D(62) D(63)
    D(64) D(65) D(66) D(67) D(68) D(69) D(70) D(71)
    D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79)
    D(80) D(81) D(82) D(83) D(84) D(85) D(86) D(87)
    D(88) D(89) D(90) D(91) D(92) D(93) D(94) D(95)
    D(96) D(97) D(98) D(99) D(100) D(101) D(102) D(103)
    D(104) D(105) D(106) D(107) D(108)

    virtual void make(
        Attack*, int, Vec*, float, int, int, int, int,
        float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int
    );

    char q[0x150 - 0x40];
    Block* blocks;
    char r[5];
    u8 done[6][5];
    char s[0x20c - 0x177];
    void* module;
};

#undef D

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_79_329C(Obj* o, u8 group, u8 id) {
    const Constants* data = &lbl_79_rodata_10;

    if (o->done[group][id] != 1) {
        Attack a(data);
        int index = group * 5 + id;
        Block* b = &o->blocks[index];

        if (b) {
            float x, y;
            y = b->a.y;
            x = b->a.x;

            Vec p;
            p.x = x;
            p.y = y;
            p.z = data->x[0];

            o->make(
                &a, 20, &p, data->x[15], 361, 50, 0, 78,
                data->x[13], data->x[13], data->x[13],
                0, 1023, 7, 0, 15, 5, 2, 8, 0,
                0, 0, 1, 0, 0, 0, 60, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0
            );

            fn_27_2636F0(o->module, index, 0, &a);
            o->done[group][id] = 1;
        }
    }
}
