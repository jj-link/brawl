#pragma force_active on
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v6(int);
    virtual void v7(int, int);
};

struct Mid {
    unsigned char pad[0x64];
    Target* target;
};

struct Self {
    unsigned char pad[0xd8];
    Mid* mid;
};

extern "C" {
void* fn_113_109E0();
void fn_27_50330(void* manager, int selection);
void fn_27_50190(void* manager, int selection);
}

extern "C" void fn_113_1094C(Self* self) {
    int result = self->mid->target->v6(0x10000042);
    if (result >= 0) {
        fn_27_50330(fn_113_109E0(), result);
        fn_27_50190(fn_113_109E0(), result);
        self->mid->target->v7(-1, 0x10000042);
    }
}
