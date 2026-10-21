#pragma force_active on

class Obj {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void process(int) = 0;
    char pad[0xE4 - 0x04];
    int count;
};

class Mgr {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void finish(void*) = 0;
};

struct Blk {
    char _00[0x10];
    void* f10;
};

struct Owner64C {
    char _000[0x354];
    Blk* f354;
};

struct Ctx650 {
    char _00[0x74];
    Obj* f74;
};

struct Self {
    char _000[0x64C];
    Owner64C* f64C;
    Ctx650* f650;
    Mgr* f654;
    char _658[0x678 - 0x658];
    void* f678;
    char _67C[0x748 - 0x67C];
    unsigned char f748;
};

extern "C" {
void fn_800B8EDC(void*, void*);
}

extern "C" void fn_2_2FFFC(Self* self) {
    Obj* o;
    int n;

    if (self->f748 != 0) {
        self->f654->finish(self->f64C->f354->f10);
        fn_800B8EDC(self->f678, self->f64C->f354);
        self->f748 = 0;
    }
    o = self->f650->f74;
    while (n = o->count) {
        if (n == 0) continue;
        o->process(n - 1);
    }
    self->f654->finish(self->f650->f74);
}
