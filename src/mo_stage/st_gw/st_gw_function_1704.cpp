#pragma force_active on
#pragma global_optimizer off

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* memset(void*, int, unsigned long);
extern const float lbl_63_rodata_0[];
extern char lbl_63_data_388[];
extern char lbl_63_data_394[];
}

struct Params {
    char pad[0x20];
    float a, b, c, d, e, f, g, h;
    char pad40[8];
    unsigned char mode;
    char tail[7];
};

#define D(n) virtual void dummy##n();

struct Ground {
    char pad[0x3c];

    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7)
    D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23)
    D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31)
    D(32) D(33) D(34) D(35) D(36)
    virtual void startup(void*, int, int);
    D(38)
    virtual void set(void*);
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47)
    D(48) D(49) D(50) D(51) D(52) D(53) D(54) D(55)
    D(56) D(57) D(58) D(59) D(60) D(61) D(62) D(63)
    D(64) D(65) D(66) D(67) D(68) D(69) D(70) D(71)
    D(72) D(73) D(74) D(75) D(76) D(77) D(78) D(79)
    virtual void params(Params*);
    D(81) D(82) D(83) D(84) D(85) D(86) D(87)
    D(88) D(89) D(90) D(91) D(92) D(93) D(94) D(95)
    D(96) D(97) D(98) D(99) D(100) D(101) D(102) D(103)
    D(104) D(105) D(106) D(107) D(108) D(109) D(110) D(111)
    D(112) D(113) D(114) D(115) D(116) D(117)
    virtual void v1(void*);
    virtual void v2(int);
    virtual void v3(void*);
    virtual void v4(void*);
};

#undef D

struct Stage {
    char pad0[0x9c];
    void* at9c;
    char padA0[0x100];
    void* at1a0;
    char pad1A4[0x3c];
    char at1e0[4];
    char at1e4[0x130];
    char at314[0x150];
    Params* data;
};

extern "C" Ground* fn_63_162C0(int, char*, char*);
extern "C" void addGround__5StageFP6Ground(Stage*, Ground*);

extern "C" void fn_63_1704(Stage* s) {
    const float* values = lbl_63_rodata_0;
    s->data = (Params*)__nw__FUlQ25Heaps8HeapType(0x50, 17);
    memset(s->data, 0, 0x50);

    s->data->e = values[0];
    s->data->f = values[0];
    s->data->h = values[1];
    s->data->mode = 2;

    Params* p = s->data;
    p->a = values[2];
    p->b = values[3];
    p->c = values[4];
    p->d = values[5];

    Ground* g = fn_63_162C0(2, lbl_63_data_388, lbl_63_data_394);
    if (g) {
        g->params(s->data);
        addGround__5StageFP6Ground(s, g);
        g->startup(s->at1a0, 0, 0);
        g->set(s->at9c);
        g->v1(s->at1e0);
        g->v2(0);
        g->v3(s->at1e4);
        g->v4(s->at314);
    }
}
