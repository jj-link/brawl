#pragma force_active on
struct soB {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void* vf15();
};

struct soA {
    unsigned char pad[0x40];
    soB* b;
};

struct soOuter {
    unsigned char pad[0xD8];
    soA* a;
};

extern "C" void* fn_27_1874C8(void*, soOuter* outer) {
    return outer->a->b->vf15();
}
