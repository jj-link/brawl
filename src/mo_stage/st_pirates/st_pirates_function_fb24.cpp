#pragma force_active on
extern "C" {
extern const float lbl_52_rodata_2B0;
extern const float lbl_52_rodata_2B8;

struct Base {
    unsigned char pad[0x3C];
};

struct Object : Base {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38();
    virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62();
    virtual void v63(); virtual void v64(); virtual void v65();
    virtual void setMotionFrame(float, unsigned long);
    virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72();
    virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78();
    virtual void v79(); virtual void v80(); virtual void v81();
    virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90();
    virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(); virtual void v95(); virtual void v96();
    virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102();
    virtual void v103(); virtual void v104(); virtual void v105();
    virtual void v106(); virtual void v107(); virtual void v108();
    virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115();
    virtual void action(int, int, int, float*);

    unsigned char pad40[0x150 - 0x40];
    unsigned char state;
    unsigned char pad151[7];
    float* motionTimer;
    unsigned char pad15C[4];
    unsigned char phase;
    unsigned char pad161[7];
    unsigned char* selector;
    unsigned char selected;
    unsigned char pad16D[0x180 - 0x16D];
    unsigned char kind;
    unsigned char pad181[3];
    float timer;
};

void fn_52_FB24(Object* self, float delta) {
    self->timer -= delta;
    if (self->timer < lbl_52_rodata_2B0)
        self->timer = lbl_52_rodata_2B0;

    switch ((int)self->state) {
    case 0:
        self->action(0, 1, 1, &self->timer);
        self->state = 1;
        // fall through
    case 1:
        if (self->phase == 1) {
            unsigned int val = 9;
            int flag = 1;
            int kind = self->kind;

            switch (kind) {
            case 3:
            case 8: val = 1; break;
            case 4:
            case 6: val = 2; break;
            case 5:
            case 7: val = 0; break;
            default: break;
            }

            unsigned int current = *self->selector;
            if (current != self->selected) {
                unsigned char old_val = (unsigned char)val;
                switch (current) {
                case 1:
                    switch (kind) {
                    case 1: val = 5; break;
                    case 2: val = 7; break;
                    default: break;
                    }
                    break;
                case 2:
                    switch (kind) {
                    case 0: val = 3; break;
                    case 2: val = 8; break;
                    default: break;
                    }
                    break;
                case 3:
                case 5:
                    switch (kind) {
                    case 0: val = 4; break;
                    case 1: val = 6; break;
                    default: break;
                    }
                    break;
                default: break;
                }
                if (val != (unsigned int)old_val) flag = 0;
                self->selected = (unsigned char)current;
            }

            if (val != 9) {
                self->action((int)val, flag, 1, &self->timer);
                self->setMotionFrame(lbl_52_rodata_2B8 - *self->motionTimer, 0);
            }
        }
        break;
    }
}
}
