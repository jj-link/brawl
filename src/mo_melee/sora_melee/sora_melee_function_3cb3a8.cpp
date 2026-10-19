#pragma force_active on
class fnInner {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual float v11();
};

class fnMid {
public:
    char pad[0xc];
    fnInner* inner;
};

class fnOuter {
public:
    char pad[0xd8];
    fnMid* mid;
};

extern "C" {
float fn_27_3CB3A8(void* unused, fnOuter* p) {
    return -p->mid->inner->v11();
}
}
