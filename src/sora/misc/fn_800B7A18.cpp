#pragma force_active on
struct VA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(float);
    virtual float v8();
};

struct VB {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v8(int, int);
};

struct Mid {
    char pad[0x18];
    VA* obj;
};

struct MuObject {
    char pad0[0x10];
    VB* unk10;
    Mid* unk14;

    void setFrameMatCol(float f);
};

void MuObject::setFrameMatCol(float f) {
    if (f != unk14->obj->v8()) {
        unk10->v8(3, 0);
    }
    unk14->obj->v7(f);
}
