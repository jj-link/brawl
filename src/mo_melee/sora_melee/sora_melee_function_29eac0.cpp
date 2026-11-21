#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
float getParamFloat__8BaseItemFUl(void*, unsigned long);

extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_46C8[];
}

class ObjA {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15();
    virtual int call48();
};

class ObjB {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50();
    virtual float callD4(int);
};

class ObjC {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11();
    virtual float call38(int, void*);
    virtual void call3C(int, float);
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual int call4C(int);
    virtual void call50(int);
    virtual void call54(int);
};

class ObjD {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6();
    virtual void call24(float);
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int call4C();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual int call5C();
};

class ObjE {
public:
    char pad[0x3C];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69();
    virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83(); virtual void v84();
    virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89();
    virtual void v90(); virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94();
    virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104();
    virtual void v105(); virtual void v106(); virtual void v107(); virtual void v108(); virtual void v109();
    virtual void v110(); virtual void v111(); virtual void v112(); virtual void v113(); virtual void v114();
    virtual void v115(); virtual void v116(); virtual void v117(); virtual void v118(); virtual void v119();
    virtual void v120(); virtual void v121(); virtual void v122(); virtual void v123(); virtual void v124();
    virtual void v125(); virtual void v126(); virtual void v127(); virtual void v128(); virtual void v129();
    virtual void v130(); virtual void v131(); virtual void v132();
    virtual void call21C(int, int);
};

struct InnerObj {
    char pad0[8];
    ObjD* m8;
    char pad10[0x50];
    ObjB* m5C;
    char pad60[4];
    ObjC* m64;
};

struct OuterObj {
    char pad[0xD8];
    InnerObj* mD8;
};

struct Obj1A4 {
    char pad[0x70];
    ObjA* m70;
};

struct Self : ObjE {
    char pad40[0x20];
    OuterObj* m60;
    char pad64[0x140];
    Obj1A4* m1A4;
};

extern "C" int fn_27_29EAC0(void*, Self* arg) {
    ObjC* c;
    const float* k = lbl_27_rodata_46C8;
    Self* self = (Self*)arg;
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }

    if (fn_27_5BEA8(lbl_27_bss_F0) == 0) {
        return 1;
    }

    if (self->m1A4->m70->call48() != 0xA) {
        return 1;
    }

    float fB = self->m60->mD8->m5C->callD4(0);
    c = self->m60->mD8->m64;
    float f1 = c->call38(0x11000003, self->m60->mD8);

    if (k[5] != f1 && (f1 - fB) > k[35]) {
        if (c->call4C(0x12000003) == 0) {
            c->call50(0x12000003);
            self->call21C(6, 0);
            ObjD* d = self->m60->mD8->m8;
            d->call24(getParamFloat__8BaseItemFUl(self, 0x2486));
        }
    } else if (c->call4C(0x12000003) != 0) {
        if (self->m60->mD8->m8->call5C() == 6) {
            if (self->m60->mD8->m8->call4C() != 0) {
                c->call54(0x12000003);
                self->call21C(4, 0);
                self->m60->mD8->m8->call24(k[0]);
            }
        }
    }

    c->call3C(0x11000003, fB);
    return 1;
}
