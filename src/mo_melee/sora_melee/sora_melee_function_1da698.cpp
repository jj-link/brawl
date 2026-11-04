#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Result34 {
    char pad[0x28];
    u32 field28;
};

struct Inner64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 v4(u32);
};

struct Inner54 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual Result34* v11(u32);
    virtual void v12();
    virtual void v13();
    virtual void v14();
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
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75(u32, u32, u32, u32, u32);
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99(u32, u32, u32);
};

struct Inner {
    char pad[0x54];
    Inner54* obj54;
    char pad2[0xC];
    Inner64* obj64;
};

struct Mid {
    char pad[0xd8];
    Inner* inner;
};

struct BC {
    u32 f0;
    u32 f4;
    u32 f8;
};

struct Obj {
    char pad[0x60];
    Mid* mid;
    char pad2[0x58];
    BC* bc;
};

extern "C" void fn_27_1DA698(Obj* obj, u32 arg1, u32 arg2, u32 arg3) {
    u32 r28 = arg2;
    u32 r29 = arg3;
    u32 r30 = arg1;

    if (r30 == 0xFFFFFFFF) {
        r30 = obj->mid->inner->obj64->v4(0x10000000);
        if (r30 == 0xFFFFFFFF) return;
    }

    Result34* res = obj->mid->inner->obj54->v11(3);
    if (res == 0 || r30 != res->field28) return;

    if (r28 == 0xFFFFFFFF) {
        r28 = obj->bc->f8;
        if (r28 == 0xFFFFFFFF) return;
    }
    if (r29 == 0xFFFFFFFF) {
        r29 = obj->bc->f4;
        if (r29 == 0xFFFFFFFF) return;
    }

    obj->mid->inner->obj54->v75(3, r29, r28, 3, 1);
    obj->mid->inner->obj54->v99(3, 2, 1);
    obj->mid->inner->obj54->v99(3, 8, 1);
    obj->mid->inner->obj54->v99(3, 3, 1);
    obj->mid->inner->obj54->v99(3, 0xE, 1);
}