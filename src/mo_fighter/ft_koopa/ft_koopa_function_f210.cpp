#pragma force_active on
struct VObj {
    virtual int v0() = 0;
    virtual int v1() = 0;
    virtual int v2() = 0;
    virtual int v3() = 0;
    virtual int v4() = 0;
    virtual int v5() = 0;
    virtual int v6() = 0;
    virtual int v7() = 0;
    virtual int v8() = 0;
    virtual int v9(int arg) = 0;
    virtual int v10() = 0;
    virtual int v11() = 0;
    virtual int v12() = 0;
    virtual int v13() = 0;
    virtual int v14() = 0;
    virtual int v15() = 0;
};

extern "C" unsigned int fn_102_F210(void* unused, void* ft) {
    VObj* sub = *(VObj**)(*(char**)((char*)ft + 0xd8) + 0x54);
    unsigned int r = sub->v9(0);
    if (r == 1) {
        VObj* sub2 = *(VObj**)(*(char**)((char*)ft + 0xd8) + 0x3c);
        return sub2->v13();
    }
    return 0;
}
