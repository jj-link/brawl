#pragma force_active on
extern "C" float lbl_27_rodata_2370;
extern "C" float lbl_27_rodata_2374;

struct Obj {
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
    virtual int v14(int) = 0;
    virtual int v15(int) = 0;
    virtual int v16(int) = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31(int, float, float) = 0;
};

struct Holder {
    char pad[0xa8];
    Obj* sub;
};

struct Fighter {
    char pad[0xd8];
    Holder* h;
};

extern "C" void fn_27_17AEAC(void* unused, Fighter* fp) {
    if (fp->h->sub->v14(0) != 0) {
        if (fp->h->sub->v15(0) == 1 || fp->h->sub->v16(0) == 0xD) {
            fp->h->sub->v31(0, lbl_27_rodata_2370, lbl_27_rodata_2374);
        }
    }
}
