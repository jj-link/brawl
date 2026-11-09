#pragma force_active on
typedef unsigned char u8;

struct GroundBase {
    unsigned char pad0[0x3c];
};

struct Ground : GroundBase {
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
    virtual void setVisible(bool);
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
    virtual float getMotionFrame(unsigned long);
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

    unsigned char pad40[0x4c - 0x40];
    void* unk4C;
    unsigned char pad50[0x6c - 0x50];
    unsigned char flags6C;
    unsigned char pad6d[0x16c - 0x6d];
    u8* unk16C;
    unsigned char pad170[0x194 - 0x170];
    u8* unk194;
};

extern "C" void setEnableCollisionStatus__6GroundFb(Ground*, bool);
extern "C" void fn_8011097C(void*);
extern float lbl_51_rodata_1C0;

extern "C" void fn_51_11594(Ground* self) {
    if (self->unk194 != 0) {
        u8* p = self->unk16C;
        if (p != 0) {
            switch (*p) {
            case 0:
                if (((static_cast<unsigned int>(self->flags6C) >> 7) & 1) == 1)
                    self->setVisible(false);
                if (((static_cast<unsigned int>(self->flags6C) >> 5) & 1) == 1)
                    setEnableCollisionStatus__6GroundFb(self, false);
                self->v127();
                break;
            case 1:
                if (((static_cast<unsigned int>(self->flags6C) >> 7) & 1) == 0)
                    self->setVisible(true);
                break;
            }
            if (self->getMotionFrame(0) > lbl_51_rodata_1C0) {
                if (((static_cast<unsigned int>(self->flags6C) >> 5) & 1) == 0) {
                    setEnableCollisionStatus__6GroundFb(self, true);
                    if (self->unk4C != 0)
                        fn_8011097C(self->unk4C);
                    if (self->unk194[0] == 0)
                        self->unk194[0] = 1;
                    if (self->unk194[1] == 0)
                        self->unk194[1] = 1;
                    self->v126();
                }
            } else {
                if (((static_cast<unsigned int>(self->flags6C) >> 5) & 1) == 1) {
                    setEnableCollisionStatus__6GroundFb(self, false);
                    if (self->unk194[0] == 1)
                        self->unk194[0] = 0;
                    if (self->unk194[1] == 1)
                        self->unk194[1] = 0;
                    self->v127();
                }
            }
        }
    }
}
