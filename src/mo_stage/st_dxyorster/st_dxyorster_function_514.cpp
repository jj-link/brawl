#pragma force_active on
extern "C" {

struct Stage {
    char pad0[0x9c];
    void* p9c;
    char pad1[0x1a0 - 0xa0];
    void* archive;
};

struct Ground {
    char pad[0x3c];
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void init(void*, int, int);
    virtual void d38();
    virtual void set(void*);
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void f70(int, int);
};

extern char lbl_76_data_0[];
Ground* fn_76_B00(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);

void fn_76_514(Stage* stage, int mode) {
    char* base = lbl_76_data_0;
    Ground* ground;

    switch (mode) {
    case 1:
        ground = fn_76_B00(1, base + 0x50, base + 0x54);
        break;
    case 2:
        ground = fn_76_B00(2, base + 0x50, base + 0x68);
        break;
    default:
        ground = 0;
        break;
    }

    if (ground != 0) {
        addGround__5StageFP6Ground(stage, ground);
        ground->init(stage->archive, 0, 0);
        ground->set(stage->p9c);
        switch (mode) {
        case 2:
            ground->f70(1, 0);
            break;
        }
    }
}

}
