#pragma force_active on
struct Inner {
    int a;
    unsigned int flags;
};

struct Sub {
    int x0;
    Inner* inner;
};

struct Obj {
    char pad0[0x3c];
    void* data3c;
    char pad1[0xd0 - 0x40];
    Sub sub;
    char pad2[0x174 - 0xd8];
    int f174;
    int f178;
    int f17c;
    unsigned char b180;
    int f184;
    int f188;
    int f18c;
    unsigned char b190;
    unsigned char b191;
};

extern "C" {
extern char lbl_63_data_6580[];
void fn_63_2B6C(Obj*);

Obj* fn_63_16B90(Obj* self) {
    fn_63_2B6C(self);
    self->data3c = lbl_63_data_6580;
    self->f174 = 0;
    self->f178 = 0;
    self->f17c = 0;
    self->b180 = 0x10;
    self->f184 = 0;
    self->f188 = 0;
    self->f18c = 0;
    self->b190 = 0;
    self->b191 = 0;
    Sub* s = &self->sub;
    if (s == 0) {
        return self;
    }
    Inner* in = s->inner;
    in->flags |= 1;
    return self;
}
}
