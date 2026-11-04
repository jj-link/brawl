#pragma force_active on
extern "C" {

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(int);
    char pad1[0x110];
    unsigned char f_150;
    char pad2[3];
    float f_154;
    float f_158;
    char pad3[8];
    unsigned char f_164;
};

extern const float lbl_68_rodata_88[];

void fn_68_45A8(Ground* self, float val) {
    const float* c = lbl_68_rodata_88;
    if (self->f_150 == 2 || (self->f_164 == 3 && self->f_154 > c[1])) {
        self->f_158 = c[2];
        return;
    }
    float result = self->f_158 - val;
    self->f_158 = result;
    if (result < c[0]) {
        self->f_158 = c[0];
    }
    if (self->f_158 > c[3]) {
        self->v27(1);
    } else {
        self->v27(0);
    }
    if (c[0] == self->f_158) {
        self->f_158 = c[2];
    }
}

}