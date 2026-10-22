#include <types.h>
#pragma force_active on

class ModuleA {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
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
    virtual void v52() = 0; virtual void v53() = 0; virtual void v54() = 0; virtual void v55() = 0;
    virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0; virtual void v59() = 0;
    virtual void v60() = 0; virtual void v61() = 0; virtual void v62() = 0; virtual void v63() = 0;
    virtual void v64() = 0; virtual void v65() = 0; virtual void v66() = 0; virtual void v67() = 0;
    virtual void v68() = 0; virtual void v69() = 0; virtual void v70() = 0; virtual void v71() = 0;
    virtual void v72() = 0; virtual void v73() = 0; virtual void v74() = 0; virtual void v75() = 0;
    virtual void v76() = 0; virtual void v77() = 0; virtual void v78() = 0; virtual void v79() = 0;
    virtual void v80() = 0; virtual void v81() = 0; virtual void v82() = 0; virtual void v83() = 0;
    virtual void v84() = 0; virtual void v85() = 0; virtual void v86() = 0; virtual void v87() = 0;
    virtual bool check() = 0;
};

class ModuleC {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void set(s32 a) = 0;
};

class ModuleD {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
    virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
    virtual void v16() = 0; virtual void v17() = 0;
    virtual void set(s32 a) = 0;
};

struct Base10 { int a; int b; };

class ModuleE : public Base10 {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
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
    virtual void v52() = 0; virtual void v53() = 0; virtual void v54() = 0; virtual void v55() = 0;
    virtual void v56() = 0; virtual void v57() = 0; virtual void v58() = 0; virtual void v59() = 0;
    virtual void v60() = 0; virtual void v61() = 0; virtual void v62() = 0; virtual void v63() = 0;
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
    virtual void v108() = 0; virtual void v109() = 0; virtual void v110() = 0; virtual void v111() = 0;
    virtual s32 check(int a) = 0;
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

extern "C" void fn_122_1AF04(Fighter*);
extern "C" void fn_122_1B000(Fighter*);

extern "C" s32 fn_122_1A8D0(void* unused, Fighter* self, s32 arg2) {
    ModuleA* a = self->accesser->obj54;
    if (a->check() == true) {
        fn_122_1AF04(self);
    }
    ModuleC* c = self->accesser->objC;
    c->set(arg2);
    ModuleE* e = self->accesser->obj10;
    if (e->check(0) == 0) {
        return 0;
    }
    ModuleD* d = self->accesser->obj64;
    d->set(0x22000000);
    fn_122_1B000(self);
    return 1;
}
