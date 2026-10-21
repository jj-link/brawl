#pragma force_active on
struct Vec3f {
    float x, y, z;
};

extern "C" void fn_27_2704CC(void*);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, Vec3f*);

enum SndID {
    sound = 0x1c91
};

struct snd3DGenerator {
    int playSE(SndID, int, int, int);
    void setPos(Vec3f*);
};

struct Base {
    char pad[0x3c];
};

struct Object : Base {
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
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void target(void*);

    char pad40[0x16c];
    Vec3f* position;
    char pad1b0[0x10];
    snd3DGenerator generator;
};

extern "C" void fn_63_16A54(Object* self, unsigned int* msg) {
    int type = (int)msg[0];
    if (type == 0x33)
        return;
    if (type <= 0x16 || type >= 0x1a)
        return;

    switch (type) {
    case 0x17:
        self->target((char*)msg + 8);
        fn_27_2704CC(self);
        self->generator.playSE(sound, 0, 0, -1);
        self->generator.setPos(self->position);
        break;
    }
}
