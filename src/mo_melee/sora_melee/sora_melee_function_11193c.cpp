#pragma force_active on
struct Inner {
    unsigned int pad[2];
    float value;
};

struct Pad {
    Inner* m_inner;
    unsigned int pad[2];
};

struct Obj : Pad {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float get();
};

extern const float lbl_27_rodata_F48;

extern "C" {
float fn_27_11193C(Obj* self) {
    float f = self->get();
    float d = self->m_inner->value - f;
    if (d < lbl_27_rodata_F48) {
        d = lbl_27_rodata_F48;
    }
    return d;
}
}
