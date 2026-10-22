#pragma force_active on
extern "C" {
extern void* g_sndSystem;
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern const float lbl_52_rodata_2F8[];
}

struct Object {
    unsigned char pad0[0x3C];
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
    virtual void v27(int);
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
    virtual Object* v40();
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
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116(int, int, int, void*);

    unsigned char pad40[0x84 - 0x40];
    float result_value;
    unsigned char pad88[0x150 - 0x88];
    unsigned char state;
    unsigned char pad151[3];
    float value;
    unsigned char pad158[0x16C - 0x158];
    unsigned char* data;
    unsigned char pad170[4];
    unsigned char buffer[8];
};

extern "C" void fn_52_115C0(Object* self, float f) {
    Object* result = self->v40();
    if (result) {
        self->value -= f;
        if (self->value < lbl_52_rodata_2F8[0])
            self->value = lbl_52_rodata_2F8[0];

        switch (self->state) {
        case 0:
            self->v116(1, 1, 0, 0);
            self->v27(0);
            self->state = 1;
            break;
        case 1:
            if (*self->data == 0) {
                self->v116(0, 1, 0, self->buffer);
                self->v27(1);
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1BAB, 0, 0, 0, -1);
                self->value = result->result_value;
                self->state = 4;
            }
            break;
        case 4:
            if (lbl_52_rodata_2F8[0] == self->value) {
                *self->data = 2;
                self->state = 0;
            }
            break;
        }
    }
}
