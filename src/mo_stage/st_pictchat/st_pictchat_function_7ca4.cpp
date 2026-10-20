#pragma force_active on
struct Base {
    unsigned char pad0[0x3c];

    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void method73();
    virtual void method74();
    virtual void method75();
    virtual void method76();
    virtual void method77();
    virtual void method78();
    virtual void method79();
    virtual void method80();
    virtual void method81();
    virtual void method82();
    virtual void method83();
    virtual void method84();
    virtual void method85();
    virtual void method86();
    virtual void method87();
    virtual void method88();
    virtual void method89();
    virtual void method90();
    virtual void method91();
    virtual void method92();
    virtual void method93();
    virtual void method94();
    virtual void method95();
    virtual void method96();
    virtual void method97();
    virtual void method98();
    virtual void method99();
    virtual void method100();
    virtual void method101();
    virtual void method102();
    virtual void method103();
    virtual void method104();
    virtual void method105();
    virtual void method106();
    virtual void method107();
    virtual void method108();
    virtual void method109();
    virtual void method110();
    virtual void method111();
    virtual void method112();
    virtual void method113();
    virtual void method114();
    virtual void method115();
    virtual void method116();
    virtual void method117();
    virtual void method118();
    virtual void method119();
    virtual void method120();
    virtual void method121();
    virtual void method122();
    virtual void method123();
    virtual void method124();
    virtual void update();
    virtual void extra0();
    virtual void extra1();
    virtual void extra2();
    virtual void extra3();
    virtual void extra4();
    virtual void extra5();
    virtual void extra6();
    virtual void extra7();
    virtual void extra8();
    virtual void extra9();
    virtual void extra10();
    virtual void extra11();
    virtual void finish();
};

struct Object : Base {
    unsigned char pad1[0x10c];
    int state;
    unsigned char phase;
    unsigned char pad2[0x12f];
    unsigned char active;
};

extern "C" void fn_73_7CA4(Object* self) {
    if (self->active == 1) {
        switch (self->phase) {
        case 3:
            self->finish();
            break;
        }
    } else {
        self->update();
        if (self->state != 0) {
            self->active = 1;
        }
    }
}
