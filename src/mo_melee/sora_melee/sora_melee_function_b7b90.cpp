#pragma force_active on
#pragma fp_contract off

struct V2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Words { int x, y; };
union Pair { Words bits; V2 vec; };

struct Modules;

class Obj {
public:
    virtual unsigned int v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual Vec3 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual double v11();
    virtual void v12();
    virtual float v13(Modules*);
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54();
    virtual int v55(int, int);
    virtual void v56();
    virtual Words get(int, int);
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
    virtual void v110();
    virtual float v111();
};

struct Pad8 { int a, b; };

class Obj8 : public Pad8 {
public:
    virtual unsigned int v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual Vec3 v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual float v11();
    virtual void v12();
    virtual float v13(Modules*);
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54();
    virtual int v55(int, int);
    virtual void v56();
    virtual Words get(int, int);
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
    virtual void v110();
    virtual float v111();
};

struct Modules {
    char pad0[0xc];
    Obj* d;
    Obj8* c;
    Obj* b;
    char pad1[0xb0 - 0x18];
    Obj* a;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Self {
    void* vtbl;
    char pad[4];
    V2 pos;
    float z;
};

extern const float lbl_27_rodata_E58;
extern "C" Pair fn_27_899AC(V2*, Pair*);

extern "C" void fn_27_B7B90(Self* self, Accesser* accesser) {
    V2 out;
    Pair p1;
    Pair p2;
    if (accesser->modules->a->v0() == 1U) {
        self->pos.x = lbl_27_rodata_E58;
        self->pos.y = lbl_27_rodata_E58;
        self->z = lbl_27_rodata_E58;
        return;
    }
    out.x = ((Obj8*)accesser->modules->a)->v11();
    out.y = lbl_27_rodata_E58;
    if (lbl_27_rodata_E58 != out.x * out.x + lbl_27_rodata_E58 * lbl_27_rodata_E58) {
        if (accesser->modules->b->v3() == 0) {
            if (accesser->modules->c->v55(8, 0) != 0) {
                p1.bits = accesser->modules->c->get(8, 0);
                p2.bits = p1.bits;
                out = fn_27_899AC(&out, &p2).vec;
            }
        }
    }
    const Vec3& t = accesser->modules->d->v4();
    self->pos = out;
    Obj8* c = accesser->modules->c;
    float fa = ((Obj8*)accesser->modules->a)->v13(accesser->modules);
    float fc = c->v111();
    self->z = (fc + fa) - t.z;
}
