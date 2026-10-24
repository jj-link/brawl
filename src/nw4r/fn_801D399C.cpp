#pragma force_active on
typedef int s32;

extern "C" s32 fn_801D40E8(void*, s32, s32, s32, s32, s32, s32, s32);

struct Base {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v25(s32, s32, s32, s32, s32, s32, s32) = 0;
};

struct Host {
    char pad[0xD8];
    char buf[0xE0];
    unsigned char flag;
};

extern "C" s32 fn_801D399C(Base* a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    a0->v25(a1, a2, a3, a4, a5, a6, a7);
    Host* h = (Host*)a0;
    if (fn_801D40E8(&h->buf, a1, a2, a3, a4, a5, a6, a7) == 0)
        return 0;
    h->flag = 1;
    return 1;
}
