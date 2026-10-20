#include <types.h>
#pragma force_active on

extern "C" {
    extern const float lbl_27_rodata_26CC;
    extern const float lbl_27_rodata_26EC;
}

class fn27Target {
public:
    virtual ~fn27Target();
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void target(u32 a, s32 b, u32 c, s32 d);
};

extern "C" void fn_27_196384(u8* self, float f) {
    s32 n = (s32)(lbl_27_rodata_26EC + lbl_27_rodata_26CC * f);
    if (n >= 1) {
        fn27Target* obj = *(fn27Target**)(*(u8**)(self + 0xd8) + 0x5c);
        obj->target(0xb, n, 1, -1);
    }
}
