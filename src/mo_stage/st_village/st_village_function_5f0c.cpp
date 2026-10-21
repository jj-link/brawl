#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_70_2088(void*, void*);
void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
    void*, void*, unsigned long, void*, unsigned long);
void __ct__14snd3DGeneratorFv(void*);
extern void* lbl_70_data_27A0[];
extern void* lbl_70_data_29E0[];
extern const float lbl_70_rodata_D0[];
}

struct Pad {
    char p[0x3c];
};

struct Obj : Pad {
    virtual void v0(void*);
    virtual void v1(void*);
    virtual void v2(void*);
    virtual void v3(void*);
    virtual void v4(void*);
    virtual void v5(void*);
    virtual void v6(void*);
    virtual void v7(void*);
    virtual void v8(void*);
    virtual void v9(void*);
    virtual void v10(void*);
    virtual void v11(void*);
    virtual void v12(void*);
    virtual void v13(void*);
    virtual void v14(void*);
    virtual void v15(void*);
    virtual void v16(void*);
    virtual void v17(void*);
    virtual void v18(void*);
    virtual void v19(void*);
    virtual void v20(void*);
    virtual void v21(void*);
    virtual void v22(void*);
    virtual void v23(void*);
    virtual void v24(void*);
    virtual void v25(void*);
    virtual void v26(void*);
    virtual void v27(void*);
    virtual void v28(void*);
    virtual void v29(void*);
    virtual void v30(void*);
    virtual void v31(void*);
    virtual void v32(void*);
    virtual void v33(void*);
    virtual void v34(void*);
    virtual void v35(void*);
    virtual void v36(void*);
    virtual void v37(void*);
    virtual void v38(void*);
    virtual void v39(void*);
    virtual void v40(void*);
    virtual void v41(void*);
    virtual void v42(void*);
    virtual void v43(void*);
    virtual void v44(void*);
    virtual void v45(void*);
    virtual void v46(void*);
    virtual void v47(void*);
    virtual void v48(void*);
    virtual void v49(void*);
    virtual void v50(void*);
    virtual void v51(void*);
    virtual void v52(void*);
    virtual void v53(void*);
    virtual void v54(void*);
    virtual void v55(void*);
    virtual void v56(void*);
    virtual void v57(void*);
    virtual void v58(void*);
    virtual void v59(void*);
    virtual void v60(void*);
    virtual void v61(void*);
    virtual void v62(void*);
    virtual void v63(void*);
    virtual void v64(void*);
    virtual void v65(void*);
    virtual void v66(void*);
    virtual void v67(void*);
    virtual void v68(void*);
    virtual void v69(void*);
    virtual void v70(void*);
    virtual void v71(void*);
    virtual void v72(void*);
    virtual void v73(void*);
    virtual void v74(void*);
    virtual void v75(void*);
    virtual void v76(void*);
    virtual void v77(void*);
    virtual void v78(void*);
};

struct State {
    char pad0[0x3c];
    void* vtable;
    char pad1[0x128];
    unsigned char a, b, c;
    float x, y;
    char seq[0x50];
    char gen[8];
};

extern "C" void* fn_70_5F0C(void* a, void* b, void* c)
{
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x1cc, 0xf);
    if (obj) {
        fn_70_2088(obj, c);
        State* self = (State*)obj;
        self->vtable = lbl_70_data_27A0;
        char* seq = self->seq;
        __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
            seq, seq + 0x20, 1, seq + 0x2c, 1);
        *(void**)seq = lbl_70_data_29E0;
        __ct__14snd3DGeneratorFv(self->gen);
        self->a = 5;
        self->b = 1;
        self->c = 4;
        self->x = lbl_70_rodata_D0[0];
        self->y = lbl_70_rodata_D0[0];
    }
    if (obj) {
        obj->v42(a);
        obj->v78(b);
    }
    return obj;
}
