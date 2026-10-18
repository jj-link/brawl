#pragma force_active on
struct Vec {
    float x, y, z;
};

struct Constants {
    float x[18];
};

extern "C" const Constants lbl_50_rodata_100;

struct Attack {
    char pad[36];
    Vec v;
    int a;
    int b;
    unsigned upper : 27;
    unsigned flags : 5;
    int c;

    Attack(const Constants* data) {
        v.x = data->x[1];
        v.y = data->x[1];
        v.z = data->x[1];
        flags = 0;
    }
};

struct Pad {
    char p[0x3c];
};

#define D(n) virtual void d##n();
#define E(n) virtual void e##n();

struct Obj : Pad {
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23)
    D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31)
    D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47)

    virtual void get(Vec*, int, int);

    E(0) E(1) E(2) E(3) E(4) E(5) E(6) E(7)
    E(8) E(9) E(10) E(11) E(12) E(13) E(14) E(15)
    E(16) E(17) E(18) E(19) E(20) E(21) E(22) E(23)
    E(24) E(25) E(26) E(27) E(28) E(29) E(30) E(31)
    E(32) E(33) E(34) E(35) E(36) E(37) E(38) E(39)
    E(40) E(41) E(42) E(43) E(44) E(45) E(46) E(47)
    E(48) E(49) E(50) E(51) E(52) E(53) E(54) E(55)
    E(56) E(57) E(58) E(59)

    virtual void make(
        Attack*, int, Vec*, float, int, int, int, int,
        float, float, float,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int,
        int, int, int, int, int, int, int, int, int
    );

    char q[0xc4 - 0x40];
    int id;
    char r[0x14c - 0xc8];
    void* module;
    char s[0x179 - 0x150];
    unsigned char done;
};

#undef D
#undef E

extern "C" void fn_27_2636F0(void*, int, int, Attack*);

extern "C" void fn_50_93AC(Obj* o) {
    const Constants* data = &lbl_50_rodata_100;
    if (o->done != 1) {
        Attack a(data);
        Vec p;

        o->get(&p, 0, o->id);
        p.x = data->x[0];
        p.y = data->x[16];
        p.z = -p.z;

        o->make(
            &a, 20, &p, data->x[17], 20, 42, 0, 90,
            data->x[1], data->x[1], data->x[1],
            o->id, 1023, 7, 0, 15, 0, 2, 2, 0,
            0, 0, 1, 0, 0, 0, 0, 0, 0,
            0, 3, 0, 0, 0, 0, 0, 0, 0
        );

        fn_27_2636F0(o->module, 0, 0, &a);
        o->done = 1;
    }
}
