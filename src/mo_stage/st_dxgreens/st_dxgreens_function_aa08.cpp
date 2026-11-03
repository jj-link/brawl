#pragma force_active on
extern "C" const float lbl_79_rodata_50;

struct Returned {
    float pad[10]; // 0x00-0x27
    float max_val; // 0x28
    float rate;    // 0x2c
};

struct Target {
    float pad;               // 0x00
    float cur;               // 0x04
    float pad2[2];           // 0x08, 0x0c
    float target;            // 0x10
    unsigned char pad3[5];   // 0x14-0x18
    unsigned char state;     // 0x19
};

#define S(x) virtual void unused##x();
#define S8(a) S(a##0) S(a##1) S(a##2) S(a##3) S(a##4) S(a##5) S(a##6) S(a##7)
#define S16(a) S8(a##0) S8(a##8)

struct Base {
    unsigned char padding[0x3c];
    S16(0) S16(1)
    S(32) S(33) S(34) S(35) S(36) S(37) S(38) S(39)
    virtual Returned* getReturned(); // index 40, vtable offset 0xa8
};

struct Object : Base {
    unsigned char padding1[0x118]; // val at 0x158
    float val;          // 0x158
    unsigned char pad4[4]; // 0x15c
    Target* target;     // 0x160
    unsigned char flag; // 0x164
};

#undef S16
#undef S8
#undef S

extern "C" void fn_79_AA08(Object* self, float delta) {
    Returned* ret = self->getReturned();
    if (ret) {
        float v = self->val + ret->rate * delta;
        self->val = v;
        if (v > ret->max_val) {
            self->val = ret->max_val;
        }

        self->target->cur -= self->val * delta;

        if (self->target->cur <= self->target->target) {
            self->target->cur = self->target->target;
            if (self->target->state != 2) {
                self->flag = 1;
            }
            self->target->state = 2;
            self->val = lbl_79_rodata_50;
        }
    }
}