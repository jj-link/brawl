#pragma force_active on
struct VObj {
    virtual ~VObj();
    virtual void v0(int) = 0;
    virtual void v1(int) = 0;
    virtual void v2(int) = 0;
    virtual void v3(int) = 0;
    virtual void v4(int) = 0;
    virtual void v5(int) = 0;
    virtual void v6(int) = 0;
    virtual void v7(int) = 0;
    virtual void v8(int) = 0;
    virtual void v9(int) = 0;
    virtual void v10(int) = 0;
    virtual void v11(int) = 0;
    virtual void v12(int) = 0;
    virtual void v13(int) = 0;
    virtual void v14(int) = 0;
    virtual void v15(int) = 0;
    virtual void v16(int) = 0;
    virtual void v17(int) = 0;
    virtual void v18(int) = 0;
    virtual void v19(int) = 0;
    virtual void v20(int) = 0;
    virtual void v21(int) = 0;
};

struct Holder {
    char pad0[0x3C];
    VObj* m2;
    char pad1[0x64 - 0x40];
    VObj* m1;
};

struct Param {
    char pad[0xD8];
    Holder* holder;
};

extern "C" void fn_118_D72C(void*, Param*);

extern "C" void fn_118_D72C(void*, Param* param) {
    param->holder->m1->v18(0x22000010);
    param->holder->m2->v4(-1);
}
