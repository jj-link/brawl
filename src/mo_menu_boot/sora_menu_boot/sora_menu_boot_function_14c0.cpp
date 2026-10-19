#pragma force_active on
extern "C" {
void fn_800307B4(void*);
void fn_800BF830(void*);
void exit__6gfTaskFv(void*);
void fn_8018E808(void*);
}

struct MenuObjectBase {
    char pad[0x5C];
};

class MenuObject : public MenuObjectBase {
public:
    virtual void destroy(int);
};

struct Boot {
    char pad0[0x40];
    unsigned int f40;
    char pad44[0x18];
    void* f5C;
    unsigned int f60;
    unsigned int f64;
    void* f68;
    void* f6C;
    MenuObject* f70;
};

extern "C" void fn_22_14C0(Boot* self) {
    fn_800307B4(self);
    self->f40 = 0;
    if (self->f68) {
        fn_800BF830(self->f68);
        exit__6gfTaskFv(self->f68);
        self->f68 = 0;
    }
    exit__6gfTaskFv(self->f6C);
    self->f6C = 0;
    self->f5C = 0;
    fn_8018E808(&self->f60);
    fn_8018E808(&self->f64);
    if (self->f70) {
        self->f70->destroy(1);
    }
    self->f70 = 0;
}
