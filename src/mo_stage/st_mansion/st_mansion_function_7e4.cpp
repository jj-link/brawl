#pragma force_active on
extern char lbl_47_data_0[];

struct Stage {
    char _0[0x9c];
    void* p9c;
    char _a0[0x100];
    void* p1a0;
};

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39(void*, int, int);
    virtual void f40();
    virtual void f41(void*);
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117(unsigned long);
    virtual void f118(void*);
    virtual void f119(void*);
    virtual void f120(void*);
    virtual void f121(void*);
    virtual void f122(int);
    virtual void f123(int);
    virtual void f124(int);
};

extern "C" Ground* fn_47_A104(int, void*, void*);
extern "C" Ground* fn_47_A590(int, void*, void*);
extern "C" Ground* fn_47_AA78(int, void*, void*);
extern "C" void addGround__5StageFP6Ground(Stage*, Ground*);
extern "C" void getNodeIndex__6GroundFPUlUlPCc(Ground*, unsigned long*, unsigned long, const char*);

extern "C" void fn_47_7E4(Stage* stage, int kind) {
    char* data = lbl_47_data_0;
    Ground* ground;
    void* p29;
    void* p28;
    void* p27;
    int p26;
    int p25;
    int p24;
    unsigned long node;

    switch (kind) {
    case 4:
        ground = fn_47_A104(5, data + 0xcc, data + 0xe0);
        p29 = (char*)stage + 0x21c;
        p28 = (char*)stage + 0x24c;
        p27 = 0;
        p26 = 1;
        p25 = 0;
        p24 = 0;
        break;
    case 5:
        ground = fn_47_A590(7, data + 0xf0, data + 0x108);
        p29 = (char*)stage + 0x228;
        p28 = (char*)stage + 0x24d;
        p27 = 0;
        p26 = 0;
        p25 = 0;
        p24 = 0;
        break;
    case 6:
        ground = fn_47_AA78(8, data + 0x118, data + 0x130);
        p28 = (char*)stage + 0x24d;
        p27 = (char*)stage + 0x24f;
        p29 = 0;
        p26 = 2;
        p25 = 0;
        p24 = 0;
        break;
    case 7:
        ground = fn_47_A104(9, data + 0x144, data + 0x158);
        p29 = (char*)stage + 0x234;
        p28 = (char*)stage + 0x24e;
        p27 = 0;
        p26 = 1;
        p25 = 1;
        p24 = 0;
        break;
    case 8:
        ground = fn_47_A590(0xb, data + 0x168, data + 0x180);
        p29 = (char*)stage + 0x240;
        p28 = (char*)stage + 0x24f;
        p27 = 0;
        p26 = 0;
        p25 = 1;
        p24 = 0;
        break;
    case 9:
        ground = fn_47_AA78(0xc, data + 0x190, data + 0x1a8);
        p28 = (char*)stage + 0x24f;
        p27 = (char*)stage + 0x24d;
        p29 = 0;
        p26 = 2;
        p25 = 1;
        p24 = 0;
        break;
    case 10:
        ground = fn_47_AA78(0xd, data + 0x1bc, data + 0x1d8);
        p28 = (char*)stage + 0x24c;
        p29 = 0;
        p27 = 0;
        p26 = 3;
        p25 = 2;
        p24 = 1;
        break;
    default:
        ground = 0;
        break;
    }

    if (ground != 0) {
        addGround__5StageFP6Ground(stage, ground);
        ground->f39(stage->p1a0, 0, 0);
        ground->f41(stage->p9c);
        ground->f118(p29);
        ground->f119(p28);
        ground->f120(p27);
        ground->f121((char*)stage + 0x214);
        ground->f122(p26);
        ground->f123(p25);
        ground->f124(p24);

        switch (kind) {
        case 4:
            getNodeIndex__6GroundFPUlUlPCc(ground, &node, 0, data + 0x1e8);
            ground->f117(node);
            break;
        case 5:
            getNodeIndex__6GroundFPUlUlPCc(ground, &node, 0, data + 0x1f4);
            ground->f117(node);
            break;
        case 7:
            getNodeIndex__6GroundFPUlUlPCc(ground, &node, 0, data + 0x200);
            ground->f117(node);
            break;
        case 8:
            getNodeIndex__6GroundFPUlUlPCc(ground, &node, 0, data + 0x20c);
            ground->f117(node);
            break;
        }
    }
}
