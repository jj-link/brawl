#pragma force_active on
extern "C" {
void fn_8014F6D4(unsigned char);
void fn_8014F700(unsigned char);
void fn_8014F828(unsigned short, unsigned char, unsigned char);
void fn_8014F848(unsigned short, unsigned char, unsigned char);
void fn_8014F868(unsigned short, unsigned char, unsigned char);
void fn_8014F888(unsigned short, unsigned char, unsigned char);
void fn_8014F8A8(unsigned short, unsigned char, unsigned char);
void fn_8014F8C8(unsigned short, unsigned char, unsigned char);
void fn_8014F8F8(unsigned char);
void fn_8014F908(unsigned int, unsigned int);
void fn_8014F958(unsigned int, unsigned int);
void fn_8014F9B8(unsigned char);
void* fn_8014FE34(void);
}

union Grp {
    unsigned int w;
    struct {
        unsigned short h;
        unsigned char a;
        unsigned char b;
    } p;
};

struct Src {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    Grp g4;
    Grp g8;
    Grp gC;
    Grp g10;
    Grp g14;
    Grp g18;
    unsigned int w1C;
    unsigned int w20;
    unsigned int w24;
    unsigned int w28;
    unsigned char t[0x37];
};

struct Obj {
    char pad[0xC];
    Src* src;
};

#define COPY(n) d[0x11 + n] = arg0->src->t[n];

extern "C" void fn_80152FA4(Obj* arg0) {
    unsigned short var_r31;
    unsigned char var_r30;
    unsigned char var_r29;
    int f;

    if (!((arg0->src->f0 >> 7) & 1)) {
        fn_8014F6D4(arg0->src->f0);
    }
    if (!((arg0->src->f1 >> 7) & 1)) {
        fn_8014F700(arg0->src->f1 != 0);
    }
    if (arg0->src->g4.w >> 31) {
        f = 0;
    } else {
        var_r31 = arg0->src->g4.p.h;
        f = 1;
        var_r30 = arg0->src->g4.p.a;
        var_r29 = arg0->src->g4.p.b;
    }
    if (f != 0) {
        fn_8014F828(var_r31, var_r30, var_r29);
    }
    if (arg0->src->g8.w >> 31) {
        f = 0;
    } else {
        var_r31 = arg0->src->g8.p.h;
        f = 1;
        var_r30 = arg0->src->g8.p.a;
        var_r29 = arg0->src->g8.p.b;
    }
    if (f != 0) {
        fn_8014F848(var_r31, var_r30, var_r29);
    }
    if (arg0->src->gC.w >> 31) {
        f = 0;
    } else {
        var_r31 = arg0->src->gC.p.h;
        f = 1;
        var_r30 = arg0->src->gC.p.a;
        var_r29 = arg0->src->gC.p.b;
    }
    if (f != 0) {
        fn_8014F868(var_r31, var_r30, var_r29);
    }
    if (arg0->src->g10.w >> 31) {
        f = 0;
    } else {
        var_r31 = arg0->src->g10.p.h;
        f = 1;
        var_r30 = arg0->src->g10.p.a;
        var_r29 = arg0->src->g10.p.b;
    }
    if (f != 0) {
        fn_8014F888(var_r31, var_r30, var_r29);
    }
    if (arg0->src->g14.w >> 31) {
        f = 0;
    } else {
        var_r31 = arg0->src->g14.p.h;
        f = 1;
        var_r30 = arg0->src->g14.p.a;
        var_r29 = arg0->src->g14.p.b;
    }
    if (f != 0) {
        fn_8014F8A8(var_r31, var_r30, var_r29);
    }
    if (arg0->src->g18.w >> 31) {
        f = 0;
    } else {
        var_r31 = arg0->src->g18.p.h;
        f = 1;
        var_r30 = arg0->src->g18.p.a;
        var_r29 = arg0->src->g18.p.b;
    }
    if (f != 0) {
        fn_8014F8C8(var_r31, var_r30, var_r29);
    }
    if (!((arg0->src->f3 >> 7) & 1)) {
        fn_8014F8F8(arg0->src->f3);
    }
    {
        unsigned int w1 = arg0->src->w1C;
        unsigned int w2 = arg0->src->w20;
        if (!(w1 >> 31)) {
            fn_8014F908(w1, w2);
        }
    }
    {
        unsigned int w1 = arg0->src->w24;
        unsigned int w2 = arg0->src->w28;
        if (!(w1 >> 31)) {
            fn_8014F958(w1, w2);
        }
    }
    if (!((arg0->src->f2 >> 7) & 1)) {
        fn_8014F9B8(arg0->src->f2);
    }
    unsigned char* d = (unsigned char*)fn_8014FE34();
    COPY(0) COPY(1) COPY(2) COPY(3) COPY(4) COPY(5) COPY(6) COPY(7)
    COPY(8) COPY(9) COPY(10) COPY(11) COPY(12) COPY(13) COPY(14) COPY(15)
    COPY(16) COPY(17) COPY(18) COPY(19) COPY(20) COPY(21) COPY(22) COPY(23)
    COPY(24) COPY(25) COPY(26) COPY(27) COPY(28) COPY(29) COPY(30) COPY(31)
    COPY(32) COPY(33) COPY(34) COPY(35) COPY(36) COPY(37) COPY(38) COPY(39)
    COPY(40) COPY(41) COPY(42) COPY(43) COPY(44) COPY(45) COPY(46) COPY(47)
    COPY(48) COPY(49) COPY(50) COPY(51) COPY(52) COPY(53) COPY(54)
}
