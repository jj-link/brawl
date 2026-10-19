#pragma force_active on
struct D {
    int a; short b; short c; float d; float e; int f; float g; float h;
    int i; int j; int k; int l; int m;
    unsigned char n0, n1, n2, n3, n4;
};

struct O {
    virtual void v0() {}  virtual void v1() {}  virtual void v2() {}  virtual void v3() {}
    virtual void v4() {}  virtual void v5() {}  virtual void v6() {}  virtual void v7() {}
    virtual void v8() {}  virtual void v9() {}  virtual void v10() {} virtual void v11() {}
    virtual void v12() {} virtual void v13() {} virtual void v14() {} virtual void v15() {}
    virtual void v16() {} virtual void v17() {} virtual void v18() {} virtual void v19() {}
    virtual void v20() {} virtual void v21() {} virtual void v22() {} virtual void v23() {}
    virtual void v24() {} virtual void v25() {}
    virtual D* get(int i);
};

extern "C" void fn_40_1FDC8(O* o, int a, int idx) {
    D* s = o->get(a);
    D* d = o->get(idx);
    *d = *s;
}
