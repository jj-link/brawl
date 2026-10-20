#pragma force_active on
struct Base {
    unsigned char pad0[0x3c];
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
    virtual void setVisible(bool);
    virtual void v28(); virtual void v29(); virtual void v30();
    virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60();
    virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66();
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
    virtual void setMotion(int, int, bool, float*);

    unsigned char pad40[0x2c];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char pad6d[0xe3];
    unsigned char state;
    unsigned char pad151[3];
    float timer;
    unsigned char* selector;
    unsigned char selected;
    unsigned char pad15d[3];
    unsigned char* phase;
    unsigned char pad164[0x1c];
    float motionTimer;
};

extern "C" {
extern const float lbl_61_rodata_F8;
void setEnableCollisionStatus__6GroundFb(void*, bool);

void fn_61_6550(Object* self, float delta) {
    self->timer -= delta;
    if (self->timer < lbl_61_rodata_F8)
        self->timer = lbl_61_rodata_F8;

    self->motionTimer -= delta;
    if (self->motionTimer < lbl_61_rodata_F8)
        self->motionTimer = lbl_61_rodata_F8;

    switch (self->state) {
    case 0:
        self->setMotion(2, 0, true, 0);
        self->setVisible(false);
        setEnableCollisionStatus__6GroundFb(self, false);
        self->state = 1;
        break;

    case 1:
        if (self->selected == *self->selector && *self->phase == 1) {
            self->setMotion(1, 0, true, &self->motionTimer);
            self->state = 6;
        }
        break;

    case 6:
        if (!self->enabled) {
            self->setVisible(true);
            setEnableCollisionStatus__6GroundFb(self, true);
        }
        if (lbl_61_rodata_F8 == self->motionTimer)
            self->state = 7;
        break;

    case 7:
        switch (*self->phase) {
        case 3:
        case 4:
            self->setMotion(0, 0, true, &self->motionTimer);
            self->state = 8;
            break;
        }
        break;

    case 8:
        if (lbl_61_rodata_F8 == self->motionTimer)
            self->state = 0;
        break;
    }
}
}
