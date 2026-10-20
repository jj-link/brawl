#pragma force_active on

typedef unsigned char u8;
typedef unsigned long u32;

extern "C" void* __nw__FUlQ25Heaps8HeapType(u32, int);
extern "C" void fn_51_3BAC(void*, void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" const float lbl_51_rodata_120;
extern "C" const float lbl_51_rodata_124;
extern char lbl_51_data_5108;

struct Base0 { char pad[0x3c]; };

struct IGen : Base0 {
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
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void fn1(void*) = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void fn2(void*) = 0;
};

extern "C" void* fn_51_E454(void* a, void* b, void* c) {
    IGen* p = (IGen*)__nw__FUlQ25Heaps8HeapType(0x1d4, 0xf);
    if (p != 0) {
        fn_51_3BAC(p, c);
        *(void**)((char*)p + 0x3c) = (void*)&lbl_51_data_5108;
        __ct__14snd3DGeneratorFv((char*)p + 0x1cc);
        *(u8*)((char*)p + 0x194) = 0;
        *(float*)((char*)p + 0x198) = lbl_51_rodata_120;
        *(float*)((char*)p + 0x19c) = lbl_51_rodata_120;
        *(float*)((char*)p + 0x1a0) = lbl_51_rodata_120;
        *(float*)((char*)p + 0x1a4) = lbl_51_rodata_120;
        *(float*)((char*)p + 0x1a8) = lbl_51_rodata_120;
        *(float*)((char*)p + 0x1ac) = lbl_51_rodata_120;
        *(float*)((char*)p + 0x1b0) = lbl_51_rodata_120;
        *(u8*)((char*)p + 0x1b4) = 0;
        *(float*)((char*)p + 0x1b8) = lbl_51_rodata_124;
        *(float*)((char*)p + 0x1bc) = lbl_51_rodata_124;
        *(float*)((char*)p + 0x1c0) = lbl_51_rodata_124;
        *(float*)((char*)p + 0x1c4) = lbl_51_rodata_124;
        *(u32*)((char*)p + 0x1c8) = 0;
    }
    if (p != 0) {
        p->fn1(a);
        p->fn2(b);
    }
    return p;
}
