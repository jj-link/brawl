#pragma force_active on
struct Context {
    int unknown0;
    int unknown4;
    int value8;
    int valueC;
    int state;
};

struct ManagerBase {
    char padding[0x3C];
};

struct Manager : ManagerBase {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void reserved22();
    virtual void reserved23();
    virtual void reserved24();
    virtual void reserved25();
    virtual void reserved26();
    virtual void reserved27();
    virtual void reserved28();
    virtual void reserved29();
    virtual void reserved30();
    virtual void reserved31();
    virtual void reserved32();
    virtual void reserved33();
    virtual void reserved34();
    virtual void reserved35();
    virtual void reserved36();
    virtual void reserved37();
    virtual void reserved38();
    virtual void reserved39();
    virtual void reserved40();
    virtual void reserved41();
    virtual void reserved42();
    virtual void reserved43();
    virtual void reserved44();
    virtual void reserved45();
    virtual void reserved46();
    virtual void reserved47();
    virtual void reserved48();
    virtual void reserved49();
    virtual void reserved50();
    virtual void reserved51();
    virtual void reserved52();
    virtual void reserved53();
    virtual void reserved54();
    virtual void reserved55();
    virtual void reserved56();
    virtual void reserved57();
    virtual void reserved58();
    virtual void reserved59();
    virtual void reserved60();
    virtual void reserved61();
    virtual void reserved62();
    virtual void reserved63();
    virtual void reserved64();
    virtual void reserved65();
    virtual void reserved66();
    virtual void reserved67();
    virtual void reserved68();
    virtual void reserved69();
    virtual void reserved70();
    virtual void reserved71();
    virtual void reserved72();
    virtual void reserved73();
    virtual void reserved74();
    virtual void reserved75();
    virtual void reserved76();
    virtual void reserved77();
    virtual void reserved78();
    virtual void reserved79();
    virtual void reserved80();
    virtual void reserved81();
    virtual void reserved82();
    virtual int call(int, int*, int*);
};

extern "C" Manager* lbl_27_bss_5668;

extern "C" int fn_27_25DF84(Context* self) {
    int ready = 0;
    if (self->state == 1 && lbl_27_bss_5668 != 0) {
        ready = 1;
    }
    if (ready) {
        return lbl_27_bss_5668->call(0, &self->value8, &self->valueC);
    }
    return 0;
}
