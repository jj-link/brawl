#include <types.h>
#pragma force_active on

class IA {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0; virtual void v4() = 0;
    virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0; virtual void v9() = 0;
    virtual void v10() = 0; virtual void v11() = 0; virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0;
    virtual void v15() = 0; virtual void v16() = 0;
    virtual s32 v17(u32 a) = 0;
};

class IB {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0; virtual void v4() = 0;
    virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0; virtual void v8() = 0; virtual void v9() = 0;
    virtual void v10() = 0; virtual void v11() = 0; virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0;
    virtual void v15() = 0; virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void v20() = 0; virtual void v21() = 0; virtual void v22() = 0; virtual void v23() = 0; virtual void v24() = 0;
    virtual void v25() = 0; virtual void v26() = 0; virtual void v27() = 0; virtual void v28() = 0; virtual void v29() = 0;
    virtual void v30() = 0; virtual void v31() = 0; virtual void v32() = 0; virtual void v33() = 0; virtual void v34() = 0;
    virtual void v35() = 0; virtual void v36() = 0; virtual void v37() = 0; virtual void v38() = 0; virtual void v39() = 0;
    virtual void v40() = 0; virtual void v41() = 0; virtual void v42() = 0; virtual void v43() = 0; virtual void v44() = 0;
    virtual void v45() = 0; virtual void v46() = 0; virtual void v47() = 0; virtual void v48() = 0; virtual void v49() = 0;
    virtual void v50() = 0;
    virtual float v51(u32 a) = 0;
};

class IC {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0;
    virtual void v3(u32 a, void* b) = 0;
};

extern const float lbl_27_rodata_24A0;

extern "C" void fn_27_1853E8(void* unused, char* obj) {
    IA* a = *(IA**)(*(char**)(obj + 0xd8) + 0x64);
    if (a->v17(0x22000010) == 0) {
        IB* b = *(IB**)(*(char**)(obj + 0xd8) + 0x5c);
        if (b->v51(0) <= lbl_27_rodata_24A0) {
            IC* c = *(IC**)(*(char**)(obj + 0xd8) + 0x70);
            c->v3(0xe, obj);
        }
    } else {
        IC* c = *(IC**)(*(char**)(obj + 0xd8) + 0x70);
        c->v3(0xe, obj);
    }
}
