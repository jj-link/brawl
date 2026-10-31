#pragma force_active on
struct Prefix {
    char pad0[0x3c];
};

struct State {
    virtual void v0();
    virtual signed char getFlag();
    virtual signed char getType();
};

struct Object : Prefix {
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
    virtual unsigned int check43();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v47();
    virtual int check49(signed char);
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
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void action140(int);

    char pad1[0x20];
    int field_0x60;
    char pad2[0x40];
    unsigned char field_0xa4;
};

extern "C" int fn_27_6270(void*, void*, int, int);
extern "C" void fn_27_1DA698(void*, int, int, int);
extern "C" void fn_27_8CF84(void*, int);
extern "C" void fn_27_8D1B0(void*, int, int);

extern "C" int fn_27_1DA24C(Object* self, State* state, int arg2, int arg3) {
    if (self->check49(state->getFlag()) == 0) {
        return 0;
    }

    if (state->getType() <= 4 || state->getType() >= 0xB) {
        return fn_27_6270(self, state, arg2, arg3);
    }

    switch (state->getType()) {
    case 5:
        self->action140(0);
        return 1;
    case 7:
        fn_27_1DA698(self, -1, -1, -1);
        return 1;
    case 8:
        fn_27_8CF84((char*)self + 0x88, self->field_0x60);
        if (self->check43() == 1U) {
            self->action140(0);
        }
        return 1;
    case 9:
        fn_27_8D1B0((char*)self + 0x88, -1, self->field_0x60);
        return 1;
    case 10:
        self->field_0xa4 |= 0x10;
        return 1;
    default:
        return 0;
    }
}
