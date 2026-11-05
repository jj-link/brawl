#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct SnakeObject {
    char pad[0x60];
    char* accesser;
};

struct Obj0 {
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(Vec3f*);
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(Vec3f*, int);
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(int);
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82();
    virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88();
    virtual void v89(int);
    virtual int v90();
    virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98();
    virtual void v99(); virtual void v100();
    virtual void v101(int, int, int);
};

struct Pad8 {
    char pad[8];
};

struct Obj8 : Pad8 {
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41();
    virtual void v42(int, Matrix*, int);
    virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50();
    virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82();
    virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90();
    virtual void v91(); virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95(); virtual void v96(); virtual void v97(); virtual void v98();
    virtual void v99(); virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
    virtual void v107(); virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111(); virtual void v112();
    virtual float v113();
};

struct Pad3c {
    char pad[0x3c];
};

struct SelfVirt : Pad3c {
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
};

static inline char* getObj(SnakeObject* self, int off) {
    char* m = *(char**)(*(char**)((char*)self + 0x60) + 0xd8);
    return *(char**)(m + off);
}

extern "C" {
extern float lbl_122_rodata_FC;
Vec3f* fn_122_D580(Vec3f*, float, float, float);

void fn_122_1D380(SnakeObject* self) {
    if (((Obj0*)getObj(self, 0x54))->v90()) {
        ((Obj0*)getObj(self, 0x0c))->v34(-1);

        Matrix mat(true);
        ((Obj8*)getObj(self, 0x04))->v42(3, &mat, 0);

        ((Obj0*)getObj(self, 0x54))->v89(1);
        ((Obj0*)getObj(self, 0x54))->v101(3, 0xc, 0);

        Vec3f pos;
        float z = mat(2, 3);
        float y = mat(1, 3);
        float x = mat(0, 3);
        pos.m_x = x;
        pos.m_y = y;
        pos.m_z = z;
        pos.m_z = ((Obj8*)getObj(self, 0x10))->v113();

        ((Obj0*)getObj(self, 0x0c))->v7(&pos);

        Vec3f rot;
        mat.getRotate(&rot);

        Vec3f tmp;
        fn_122_D580(&tmp, lbl_122_rodata_FC * rot.m_x, lbl_122_rodata_FC * rot.m_y, lbl_122_rodata_FC * rot.m_z);
        rot.m_x = tmp.m_x;
        rot.m_y = tmp.m_y;
        rot.m_z = tmp.m_z;

        ((Obj0*)getObj(self, 0x0c))->v17(&rot, 0);

        ((SelfVirt*)self)->v45();
    }
}
}
