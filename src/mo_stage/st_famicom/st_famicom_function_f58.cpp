#pragma force_active on
struct Stage {
    char _0[0x9c];
    void* p9c;
    char _a0[0x100];
    void* p1a0;
    char _1a4[0xc4];
    void* p268;
    char _26c[0x68];
    void* p2d4;
    char _2d8[0x78];
    void* p350;
    char _354[0x10];
    void* p364;
    char _368[0xc0];
    void* p428;
};

struct Ground {
    char _0[0x3c];
    virtual void f0();
    virtual void f1();
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
    virtual void f37(void*, int, int);
    virtual void f38();
    virtual void f39(void*);
    virtual void f40();
    virtual void f41();
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
    virtual void f117(void*);
    virtual void f118(void*);
    virtual void f119(void*);
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123(int);
    virtual void f124(int);
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130(int);
};

extern "C" char lbl_68_data_0[];
extern "C" Ground* fn_68_24D0(int, const char*, const char*);
extern "C" void addGround__5StageFP6Ground(Stage*, Ground*);
extern "C" void createCollisionSelf__7stMeleeFP15stCollisionWorkP6GroundPCcPCcUs(
    Stage*, void*, Ground*, const char*, const char*, unsigned short);

extern "C" void fn_68_F58(Stage* stage, int kind) {
    char* data = lbl_68_data_0;
    Ground* ground;
    void* work;
    int flag;
    void* area;
    int mode;
    void* frame;

    switch (kind) {
    case 6:
        ground = fn_68_24D0(8, data + 0x118, data + 0x12c);
        work = (char*)stage + 0x268;
        flag = 0;
        area = (char*)stage + 0x2d4;
        mode = 5;
        frame = (char*)stage + 0x350;
        break;
    case 7:
        ground = fn_68_24D0(11, data + 0x144, data + 0x158);
        work = (char*)stage + 0x278;
        flag = 1;
        area = (char*)stage + 0x2e0;
        mode = 6;
        frame = (char*)stage + 0x364;
        break;
    default:
        ground = 0;
        work = 0;
    }

    if (ground) {
        addGround__5StageFP6Ground(stage, ground);
        ground->f124(0x1a);
        ground->f130(flag);
        ground->f37(stage->p1a0, 0, 0);
        ground->f39(stage->p9c);
        ground->f117(area);
        ground->f118(stage->p428);
        ground->f119(frame);
        ground->f123(mode);

        switch (kind) {
        case 6:
            createCollisionSelf__7stMeleeFP15stCollisionWorkP6GroundPCcPCcUs(
                stage, work, ground, data + 0x118, data + 0x118, 0x41a);
            break;
        case 7:
            createCollisionSelf__7stMeleeFP15stCollisionWorkP6GroundPCcPCcUs(
                stage, work, ground, data + 0x144, data + 0x144, 0x41a);
            break;
        }

        ground->f46();
    }
}
