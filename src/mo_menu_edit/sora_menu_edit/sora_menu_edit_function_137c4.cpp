#include <snd/snd_system.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" void fn_800BA2E8();

struct Data {
    char pad0[0x17C];
    MuObject* obj;
    char pad180[0x1B54 - 0x180];
    unsigned int flags;
    char pad1B58[0x1BFC - 0x1B58];
    unsigned int state;
    char pad1C00[0x1CED - 0x1C00];
    unsigned char b1CED;
    char pad1CEE[0x1D40 - 0x1CEE];
    unsigned int d1D40;
    unsigned int d1D44;
    unsigned int d1D48;
    int counter;
};

struct Self {
    char pad0[0x3C];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42();
    virtual void atB4(int);
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57();
    virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73();
    virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77();
    virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
    virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85();
    virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93();
    virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97();
    virtual void v98(); virtual void v99(); virtual void v100(); virtual void v101();
    virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105();
    virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113();
    virtual void v114(); virtual void v115(); virtual void v116();
    virtual int at1D4();

    char pad40[0x168];
    unsigned int flags;
    Data* data;
};

extern "C" void fn_5_137C4(Self* self) {
    if ((self->flags & 4) || self->data->b1CED != 0) {
        self->atB4(*(unsigned int*)((char*)self->data->obj + 0x10));
        self->data->state = 0;
        return;
    }
    if (self->flags & 2) {
        fn_800BA2E8();
        switch (self->data->counter) {
        case 0:
            if (self->at1D4()) {
                return;
            }
            self->data->d1D40 = 0;
            self->data->state = 4;
            break;
        case 1:
            self->data->d1D40 = 1;
            self->data->d1D44 = 4;
            self->data->d1D48 = 0x18;
            self->data->state = 0x19;
            break;
        }
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
    } else {
        unsigned int f = self->data->flags;
        Data* data = ((Data* const*)&self->data)[0];
        int cur = data->counter;
        int next = cur;
        if (f & 1) {
            int t = cur - 1;
            next = t > 0 ? t : 0;
        } else if (f & 2) {
            int t = cur + 1;
            next = 1;
            if (t < 1) {
                next = t;
            }
        }
        if (next != cur) {
            data->counter = next;
            self->data->obj->setFrameNode((float)next);
            g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        }
    }
}
