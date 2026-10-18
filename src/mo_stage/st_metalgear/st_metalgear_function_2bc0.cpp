#pragma force_active on
struct Node {
    int a;
    unsigned int flags;
};

struct Sub {
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int a, int b);
    Node* node;
    int flag;
};

struct Self {
    char pad0[0x3c];
    void* tbl;
    char pad1[0xd0 - 0x40];
    Sub sub;
    char pad2[0x158 - 0xdc];
    int i158;
    int i15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    unsigned char b184;
    unsigned char b185;
    unsigned char b186;
    unsigned char b187;
    float f188;
    float f18c;
    unsigned char b190;
    unsigned char b191;
    int i194;
};

extern "C" {
extern char lbl_71_data_1358[];
extern const float lbl_71_rodata_58;
void fn_71_2708(Self* self);

Self* fn_71_2BC0(Self* self) {
    fn_71_2708(self);
    float f = lbl_71_rodata_58;
    self->tbl = lbl_71_data_1358;
    self->i158 = 0;
    self->i15c = 0;
    self->f160 = f;
    self->f164 = f;
    self->f168 = f;
    self->f16c = f;
    self->f170 = f;
    self->f174 = f;
    self->f178 = f;
    self->f17c = f;
    self->f180 = f;
    self->b184 = 0;
    self->b185 = 9;
    self->b186 = 0;
    self->b187 = 0x80;
    self->f188 = f;
    self->f18c = f;
    self->b190 = 0;
    self->b191 = 0;
    self->i194 = -1;
    Sub* p = &self->sub;
    if (p == 0) {
        return self;
    }
    p->flag = 1;
    p->f6(0, 0xf);
    p->node->flags |= 1;
    p->node->flags |= 2;
    return self;
}
}
