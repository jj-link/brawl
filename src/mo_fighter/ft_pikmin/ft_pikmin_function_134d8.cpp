#pragma force_active on

class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual void fn_113_1C074();
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054();
    virtual void fn_113_1C04C(int, int, int);
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C();
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual void fn_113_1C014(int, int);
    virtual unsigned int fn_113_1C004(unsigned int);
    virtual void fn_113_1BFF4();
    virtual void fn_113_1BFE4(unsigned int);
};

class Class_14 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int count();
};

struct TargetBase {
    char padding[0x3c];
};

class Target : public TargetBase {
public:
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
    virtual void v75();
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
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void action(int);
};

class TargetList {
public:
    virtual void v0();
    virtual void v1();
    virtual Target** get(int);
    virtual int size();
};

extern "C" {
TargetList* fn_113_24550(void*);
void fn_113_255CC(void*, bool, int, bool);
void fn_113_25120(void*, void*, int);
void fn_113_24D68(void*, void*, int);
void fn_113_10DD0(void*);
}

extern "C" void fn_113_134D8(void* self, void* accesser) {
    if ((*(Class_7FE8**)((char*)*(char**)((char*)accesser + 0xd8) + 0x64))->fn_113_1C004(0x22000013) == 1) {
        (*(Class_7FE8**)((char*)*(char**)((char*)accesser + 0xd8) + 0x64))->fn_113_1BFE4(0x22000013);
        TargetList* list = fn_113_24550(*(void**)((char*)self + 4));
        if (list->size() > 0) {
            (*(Class_7FE8**)((char*)*(char**)((char*)accesser + 0xd8) + 0x84))->fn_113_1C04C(2, 1, 0);
            for (int i = 0; i < list->size(); ++i) {
                (*list->get(i))->action(0x2f);
            }
            fn_113_255CC(*(void**)((char*)self + 4), true, 1, true);
        }
    } else if ((*(Class_7FE8**)((char*)*(char**)((char*)accesser + 0xd8) + 0x64))->fn_113_1C004(0x22000014) == 1) {
        (*(Class_7FE8**)((char*)*(char**)((char*)accesser + 0xd8) + 0x64))->fn_113_1BFE4(0x22000014);
        int kind = 8;
        if ((*(Class_14**)((char*)*(char**)((char*)accesser + 0xd8) + 0x14))->count() == 0) {
            kind = 0xA;
        }
        TargetList* list = fn_113_24550(*(void**)((char*)self + 4));
        int n = list->size();
        if (n > 0) {
            for (int i = 0; i < n; ++i) {
                Target* t = *list->get(i);
                fn_113_25120(*(void**)((char*)self + 4), t, 0x12000004);
                fn_113_24D68(*(void**)((char*)self + 4), t, kind);
            }
            fn_113_10DD0(*(void**)((char*)accesser + 8));
        }
        (*(Class_7FE8**)((char*)*(char**)((char*)accesser + 0xd8) + 0x84))->fn_113_1C014(2, 0);
    }
}
