#pragma force_active on
struct VT {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(float);
    virtual float v6(void);
};

struct VU {
    virtual void u0(void);
    virtual void u1(void);
    virtual void u2(void);
    virtual void u3(void);
    virtual void u4(void);
    virtual void u5(void);
    virtual void u6(int, int);
};

struct Holder {
    char pad[0x10];
    void* p;
};

struct MuObject {
    char pad0[0x10];
    void* unk10;
    void* unk14;
    void setFrameTex(float f);
};

void MuObject::setFrameTex(float f) {
    VT* y = (VT*)((Holder*)unk14)->p;
    float r = y->v6();
    if (f != r) {
        VU* z = (VU*)unk10;
        z->u6(3, 0);
    }
    VT* w = (VT*)((Holder*)unk14)->p;
    w->v5(f);
}
