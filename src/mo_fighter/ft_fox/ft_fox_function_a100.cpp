#pragma force_active on
extern "C" void fn_27_12BAF8(void* object, int param);

struct SubX {
    virtual ~SubX();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

struct Self {
    char pad[0x1CD44];
    unsigned char a;
    unsigned char b;
    char pad2[2];
    SubX* sub;
};

extern "C" void fn_97_A100(Self* self, int param) {
    self->sub->vf7();
    fn_27_12BAF8(self, param);
    self->b = 0;
    self->a = 0;
}
