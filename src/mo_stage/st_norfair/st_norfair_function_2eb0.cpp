#pragma force_active on
extern "C" const float lbl_54_rodata_68[];

struct Params {
    char pad[0x5C];
    float value;
};

struct Object {
    unsigned char pad[0x3c];
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
    virtual Params* getParams();
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
    virtual void setFrame(int, float);
    virtual float getFrame(int);
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
    virtual void v116(int, int, int, void*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char* ptrA;
    unsigned char* ptrB;
    float unk160;
    float unk164;
    float unk168;
};

extern "C" void fn_54_2EB0(Object* self, float delta) {
    const float* c = lbl_54_rodata_68;
    Params* p = self->getParams();
    if (p) {
        self->timer -= delta;
        if (self->timer < c[0])
            self->timer = c[0];

        switch (self->state) {
        case 0:
            self->v116(0, 0, 1, 0);
            if (*(float*)((char*)self + 0x64) < c[0])
                *(float*)((char*)self + 0x64) *= c[1];
            self->state = 1;
            break;
        case 1:
            if (*self->ptrA == 4 && *self->ptrB == 0) {
                self->v116(1, 0, 1, &self->unk168);
                if (*(float*)((char*)self + 0x64) < c[0])
                    *(float*)((char*)self + 0x64) *= c[1];
                self->state = 12;
            }
            break;
        case 12:
            self->state = 7;
            break;
        case 7:
            if (*self->ptrA != 4) {
                self->timer = p->value;
                self->state = 9;
            }
            break;
        case 9:
            if (c[0] == self->timer) {
                self->v116(1, 1, 1, &self->unk168);
                self->setFrame(0, self->unk168 - c[2]);
                self->unk164 = self->unk168;
                if (*(float*)((char*)self + 0x64) > c[0])
                    *(float*)((char*)self + 0x64) *= c[1];
                self->state = 10;
            }
            break;
        case 10:
            if (self->getFrame(0) > self->unk164) {
                self->v116(0, 0, 1, 0);
                if (*(float*)((char*)self + 0x64) < c[0])
                    *(float*)((char*)self + 0x64) *= c[1];
                self->state = 1;
            } else {
                self->unk164 = self->getFrame(0);
            }
            break;
        }
    }
}
