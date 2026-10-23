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
    u32 i158;
    u32 i15c;
    float f160;
    unsigned char b164;
    char pad165[3];
    float f168;
    unsigned char b16c;
    char pad16d[3];
    u32 i170;
    u32 i174;
    u32 i178;
};

extern "C" void __ct__11grDxBigBlueFPCc(Object*, const char*);
extern "C" char lbl_81_data_1AE8[];
extern "C" const float lbl_81_rodata_E0;

extern "C" Object* fn_81_6900(Object* self, const char* name) {
    __ct__11grDxBigBlueFPCc(self, name);
    float f = lbl_81_rodata_E0;
    u32 z = 0;
    Sub* s = &self->sub;
    self->i158 = z;
    self->vtable = lbl_81_data_1AE8;
    self->i15c = z;
    self->f160 = f;
    self->b164 = z;
    self->f168 = f;
    self->b16c = z;
    self->i170 = z;
    self->i174 = z;
    self->i178 = z;
    if (!s) return self;
    s->state = 1;
    s->v4(0, 15);
    s->data->flags |= 1;
    s->data->flags |= 2;
    return self;
}
