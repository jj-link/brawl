#pragma force_active on
extern const float lbl_92_rodata_68;
extern const float lbl_92_rodata_60;

struct FtDonkeyObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int v14(int);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31(float, float, int);
};

extern "C" void fn_92_F4CC(void*, void* obj, int id) {
    if (id == 0x117) {
        goto end;
    }
    if (id < 0x117) {
        if (id == 0x97) {
            goto end;
        }
    } else {
        if (id == 0x11d) {
            goto end;
        }
    }
    {
        FtDonkeyObj* q =
            *(FtDonkeyObj**)((char*)*(void**)((char*)obj + 0xd8) + 0xa8);
        if (q->v14(0)) {
            FtDonkeyObj* q2 =
                *(FtDonkeyObj**)((char*)*(void**)((char*)obj + 0xd8) + 0xa8);
            q2->v31(lbl_92_rodata_68, lbl_92_rodata_60, 0);
        }
    }
end:;
}
