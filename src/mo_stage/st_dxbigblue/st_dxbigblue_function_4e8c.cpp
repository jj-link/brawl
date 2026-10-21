#pragma force_active on
typedef unsigned int u32;

struct Flags { u32 pad; u32 flags; };

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
    Flags* data;
    u32 state;
};

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x90];
    Sub sub;
    char padDC[0x7C];
    float f158;
    u32 f15C;
    float f160;
    u32 f164;
};

extern "C" void __ct__11grDxBigBlueFPCc(Object*, const char*);
extern "C" char lbl_81_data_E98[];
extern "C" const float lbl_81_rodata_B8;

extern "C" Object* fn_81_4E8C(Object* self, const char* name) {
    __ct__11grDxBigBlueFPCc(self, name);
    self->f15C = 0;
    self->vtable = lbl_81_data_E98;
    self->f158 = lbl_81_rodata_B8;
    self->f160 = lbl_81_rodata_B8;
    self->f164 = 0;

    Sub* s = &self->sub;
    if (!s) return self;

    s->state = 1;
    s->v4(0, 15);
    s->data->flags |= 1;
    s->data->flags |= 2;
    return self;
}
