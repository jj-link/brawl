#pragma force_active on
typedef unsigned int u32;

class SubV {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
};

struct Sub {
    SubV* vt;
    void* p4;
    u32 f8;
};

struct Object {
    char pad0[0x3C];
    char* field3C;
    char pad40[0xD0 - 0x40];
    Sub sub;
    char padDC[0x158 - 0xDC];
    u32 field158;
    u32 field15C;
    u32 field160;
    u32 field164;
    u32 field168;
    u32 field16C;
    u32 field170;
    u32 field174;
    char pad178[0x10];
};

extern "C" void fn_88_4368(Object* self);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" char lbl_88_data_1A88[];

extern "C" Object* fn_88_65C4(Object* self) {
    fn_88_4368(self);
    self->field158 = 0;
    self->field3C = lbl_88_data_1A88;
    self->field15C = 0;
    self->field160 = 0;
    self->field164 = 0;
    self->field168 = 0;
    self->field16C = 0;
    self->field170 = 0;
    self->field174 = 0;
    memset((char*)self + 0x178, 0, 0x10);
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    s->f8 = 1;
    ((SubV*)s)->v4(0, 0xF);
    u32* p = (u32*)s->p4;
    p[1] |= 1;
    return self;
}
