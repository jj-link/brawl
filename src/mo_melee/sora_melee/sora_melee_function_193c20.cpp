#pragma force_active on

struct Vec {
    float x, y, z;
};

struct Box {
    float f[14];
};

class PVt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec v4();
    virtual void v5(Vec*);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(unsigned int);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
};

class MVt {
public:
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
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66();
    virtual Vec v67();
};

struct Pad8 {
    char pad[8];
};

class GMod : public Pad8 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(int);
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual Vec v35(int);
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100();
    virtual void v101(Box*, Box*, int);
    virtual void v102(); virtual void v103(); virtual void v104();
    virtual void v105(int, int, int);
    virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113();
    virtual void v114(); virtual void v115(); virtual void v116(); virtual void v117();
    virtual void v118();
    virtual void v119(int);
};

struct Pad3c {
    char pad[0x3c];
};

class S08Vt : public Pad3c {
public:
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
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
};

struct Mid {
    char pad[8];
    MVt* m;
    PVt* p;
    GMod* g;
};

struct Owner {
    char pad[8];
    S08Vt* s;
    char pad2[0xcc];
    Mid* mid;
};

extern "C" void fn_27_193C20(Owner* self, unsigned int arg) {
    Box b1, b2;

    self->mid->p->v10(arg);
    self->mid->p->v19();

    const Vec& delta = self->mid->m->v67();
    const Vec& ptmp = self->mid->p->v4();
    Vec& pos = const_cast<Vec&>(ptmp);

    self->mid->g->v101(&b1, &b2, 0);
    float diff = b2.f[3] - b2.f[5];
    pos.y = pos.y + (diff + delta.y);
    self->mid->p->v5(&pos);

    self->mid->g->v105(5, 1, 0);
    self->mid->g->v11(1);
    self->mid->g->v119(0);

    pos = self->mid->g->v35(0);
    self->mid->p->v5(&pos);
    self->s->v43();

    if (arg == 1) {
        self->mid->g->v105(3, 1, 0);
    }
}
