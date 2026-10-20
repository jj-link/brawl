#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

class Obj {
public:
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual Vec3 getVec(int a, int b, bool c);
};

struct Inner {
    char pad[0x54];
    Obj* obj;
};

struct Mid {
    char pad[0xd8];
    Inner* inner;
};

struct Outer {
    char pad[0x10];
    Mid* mid;
    int val;
};

extern "C" {
float fn_27_666AC(Outer* self) {
    return self->mid->inner->obj->getVec(0, self->val, true).y;
}
}
