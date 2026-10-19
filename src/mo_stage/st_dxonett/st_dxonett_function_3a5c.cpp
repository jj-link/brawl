#pragma force_active on
struct OnettBase {
    char _00[0x3c];
};

struct OnettData {
    char _00[0x18];
    float m_src[3];
    char _24[0x54 - 0x24];
    float m_dst[3];
};

class OnettObj : public OnettBase {
public:
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
    virtual int v42();
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
    virtual void v98(int, int);
    virtual void v99(int, int);
    virtual void v100(int);
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

    char _40[0x150 - 0x40];
    unsigned char m_state;
    char _151[0x158 - 0x151];
    OnettData* m_data;
    unsigned char* m_p15c;
    unsigned char* m_p160;
    char _164[0x165 - 0x164];
    unsigned char m_flag165;
};

extern "C" void fn_78_3A5C(OnettObj* self) {
    if (self->v42() == 0) {
        return;
    }
    switch (self->m_state) {
    case 0:
        self->v99(0, 0);
        self->v100(0);
        self->m_flag165 = 0;
        self->m_state = 1;
        // fall through
    case 1:
        if (*self->m_p15c != 4) {
            self->m_state = 3;
        } else {
            OnettData* d = self->m_data;
            d->m_dst[0] = d->m_src[0];
            d->m_dst[1] = d->m_src[1];
            d->m_dst[2] = d->m_src[2];
        }
        break;
    case 2:
        break;
    case 3:
        if (*self->m_p15c == 4) {
            self->v99(0, 0);
            self->v100(0);
            self->m_flag165 = 0;
            *self->m_p160 = 2;
            self->m_state = 1;
        } else if (self->m_flag165 == 0) {
            self->v98(0, 0);
            self->v119();
        }
        break;
    }
}
