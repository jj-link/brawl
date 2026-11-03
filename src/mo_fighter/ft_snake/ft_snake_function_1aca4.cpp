#include <types.h>
#pragma force_active on

struct Pair {
    s32 x;
    s32 y;
};

class ModuleA {
public:
    virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
    virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
    virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void v20() = 0; virtual void v21() = 0; virtual void v22() = 0; virtual void v23() = 0;
    virtual void v24() = 0; virtual void v25() = 0; virtual void v26() = 0; virtual void v27() = 0;
    virtual void v28() = 0; virtual void v29() = 0; virtual void v30() = 0; virtual void v31() = 0;
    virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0; virtual void v35() = 0;
    virtual void v36() = 0; virtual void v37() = 0; virtual void v38() = 0; virtual void v39() = 0;
    virtual void v40() = 0; virtual void v41() = 0; virtual void v42() = 0; virtual void v43() = 0;
    virtual void v44() = 0; virtual void v45() = 0; virtual void v46() = 0; virtual void v47() = 0;
    virtual void v48() = 0; virtual void v49() = 0; virtual void v50() = 0; virtual void v51() = 0;
    virtual void v52() = 0; virtual void v53() = 0;
    virtual u32 v54(s32 a) = 0; virtual Pair v55(s32 a) = 0;
    virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0; virtual void v59() = 0;
    virtual void v60() = 0; virtual void v61() = 0; virtual void v62() = 0; virtual void v63() = 0;
    virtual void v64() = 0; virtual void v65() = 0; virtual void v66() = 0; virtual void v67() = 0;
    virtual void v68() = 0; virtual void v69() = 0; virtual void v70() = 0; virtual void v71() = 0;
    virtual void v72() = 0; virtual void v73() = 0; virtual void v74() = 0; virtual void v75() = 0;
    virtual void v76() = 0; virtual void v77() = 0; virtual void v78() = 0; virtual void v79() = 0;
    virtual void v80() = 0; virtual void v81() = 0; virtual void v82() = 0; virtual void v83() = 0;
    virtual void v84() = 0; virtual void v85() = 0; virtual void v86() = 0; virtual void v87() = 0;
    virtual void v88() = 0; virtual void v89(s32 a) = 0;
    virtual bool check() = 0;
};

class ModuleC {
public:
    virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0;
    virtual void set(s32 a) = 0;
};

class ModuleD {
public:
    virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
    virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
    virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void set(s32 a) = 0;
};

struct Base10 { int a; int b; };

class ModuleE : public Base10 {
public:
    virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
    virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13(s32 a) = 0; virtual void v14() = 0; virtual void v15() = 0;
    virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void v20() = 0; virtual void v21(s32 a, s32 b) = 0; virtual void v22() = 0; virtual void v23() = 0;
    virtual void v24() = 0; virtual void v25() = 0; virtual void v26() = 0; virtual void v27() = 0;
    virtual void v28() = 0; virtual void v29() = 0; virtual void v30() = 0; virtual void v31() = 0;
    virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0; virtual void v35() = 0;
    virtual void v36() = 0; virtual void v37() = 0; virtual void v38() = 0; virtual void v39() = 0;
    virtual void v40() = 0; virtual void v41() = 0; virtual void v42() = 0; virtual void v43() = 0;
    virtual void v44() = 0; virtual void v45() = 0; virtual void v46() = 0; virtual void v47() = 0;
    virtual void v48() = 0; virtual void v49() = 0; virtual void v50() = 0; virtual void v51() = 0;
    virtual void v52() = 0; virtual void v53() = 0; virtual void v54() = 0; virtual void v55() = 0;
    virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0; virtual void v59() = 0;
    virtual void v60() = 0; virtual void v61() = 0; virtual void v62() = 0; virtual s32 v63(s32 a) = 0;
    virtual void v64() = 0; virtual void v65() = 0; virtual void v66() = 0; virtual void v67() = 0;
    virtual void v68() = 0; virtual void v69() = 0; virtual void v70() = 0; virtual void v71() = 0;
    virtual void v72() = 0; virtual void v73() = 0; virtual void v74() = 0; virtual void v75() = 0;
    virtual void v76() = 0; virtual void v77() = 0; virtual void v78() = 0; virtual void v79() = 0;
    virtual void v80() = 0; virtual void v81() = 0; virtual void v82() = 0; virtual void v83() = 0;
    virtual void v84() = 0; virtual void v85() = 0; virtual void v86() = 0; virtual void v87() = 0;
    virtual void v88() = 0; virtual void v89() = 0; virtual void v90() = 0; virtual void v91() = 0;
    virtual void v92() = 0; virtual void v93() = 0; virtual void v94() = 0; virtual void v95() = 0;
    virtual void v96() = 0; virtual void v97() = 0; virtual void v98() = 0; virtual void v99() = 0;
    virtual void v100() = 0; virtual void v101() = 0; virtual void v102() = 0; virtual void v103() = 0;
    virtual void v104() = 0; virtual void v105() = 0; virtual void v106() = 0; virtual void v107() = 0;
    virtual void v108() = 0; virtual void v109(Pair* p, s32 b) = 0;
    virtual void v110() = 0; virtual void v111() = 0; virtual void v112() = 0; virtual void v113() = 0;
    virtual void v114() = 0; virtual void v115() = 0; virtual void v116(s32 a, s32 b) = 0; virtual void v117() = 0;
    virtual void v118() = 0; virtual void v119() = 0; virtual void v120() = 0; virtual void v121(s32 a) = 0;
};

struct Accesser {
    char pad_00[0xc];
    ModuleC* objC;
    ModuleE* obj10;
    char pad_14[0x40];
    ModuleA* obj54;
    char pad_58[0xc];
    ModuleD* obj64;
};

struct Fighter {
    char pad_00[0xd8];
    Accesser* accesser;
};

extern "C" void fn_122_1B000(Fighter*);

extern "C" s32 fn_122_1ACA4(void* unused, Fighter* self, s32 arg2) {
    if (self->accesser->obj54->check() == true) {
        self->accesser->obj54->v89(1);
    }
    self->accesser->obj10->v21(5, 0);
    self->accesser->objC->set(arg2);
    if (self->accesser->obj54->v54(3) == 1) {
        Pair v;
        v = self->accesser->obj54->v55(3);
        self->accesser->obj10->v109(&v, 0);
    }
    self->accesser->obj10->v13(1);
    self->accesser->obj10->v121(0);
    s32 t = self->accesser->obj10->v63(0);
    if (t == 0) {
        return 0;
    }
    self->accesser->obj10->v116(t, 0);
    fn_122_1B000(self);
    self->accesser->obj64->set(0x22000000);
    return 1;
}
