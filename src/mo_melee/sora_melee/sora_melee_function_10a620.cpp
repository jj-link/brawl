#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1190D0(void*);
extern "C" void* getEntity__14ftEntryManagerFUl(void*, u32);

class Fighter {
public:
    void* pad[0xF];
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual s32 isActive() = 0;
};

extern "C" s32 isFighterActivate__9ftManagerFii(void* self, u32 arg0, s32 arg1) {
    Fighter* p;
    if (fn_27_1190D0(*(void**)((char*)self + 0x154)) == 0) {
        p = 0;
    } else if (arg1 != -1) {
        char* entry = (char*)getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), arg0);
        p = *(Fighter**)(entry + (arg1 << 3) + 0x34);
    } else {
        char* entry = (char*)getEntity__14ftEntryManagerFUl(*(void**)((char*)self + 0x154), arg0);
        u8 n = *(u8*)(entry + 0xa);
        p = *(Fighter**)(entry + (n << 3) + 0x34);
    }
    s32 result = 0;
    if (p != 0) {
        if (p->isActive() != 0) {
            result = 1;
        }
    }
    return result;
}
