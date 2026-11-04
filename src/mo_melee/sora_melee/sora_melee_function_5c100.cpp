#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern const float lbl_27_rodata_7D8;

struct SoBase {
    u32 m_a;
    u32 m_b;
};

class soNullable : public SoBase {
public:
    virtual void isNull();
    virtual void fn_27_5BFA0();
    virtual void fn_27_5C070();
    virtual void fn_27_5C0B4();
    virtual void fn_27_5C100();
    virtual void fn_27_5C250();
    virtual void fn_27_5C5AC();
    virtual void fn_27_5C5E4();
    virtual void fn_27_5C5DC();
    virtual void fn_27_5C5D4();
    virtual void fn_27_5C0C4();
    virtual void fn_27_5C5A4();
    virtual void fn_27_5C59C();
    virtual void fn_27_5C2A8();
    virtual void fn_27_5C33C();
    virtual void fn_27_5C2FC();
    virtual void fn_27_5C390();
    virtual void fn_27_5C5CC();
};

class SoVIface {
public:
    virtual void v0();   virtual void v1();   virtual void v2();   virtual void v3();   virtual void v4();   virtual void v5();
    virtual void v6();   virtual void v7();   virtual void v8();   virtual void v9();   virtual void v10();  virtual void v11();
    virtual void v12();  virtual void v13();  virtual void v14();  virtual void v15();  virtual void v16();  virtual void v17();
    virtual void v18();  virtual void v19();  virtual void v20();  virtual void v21();  virtual void v22();  virtual void v23();
    virtual void v24();  virtual void v25();  virtual void v26();  virtual void v27();  virtual void v28();  virtual void v29();
    virtual void v30();  virtual void v31();  virtual void v32();  virtual void v33();  virtual void v34();  virtual void v35();
    virtual void v36();  virtual void v37();  virtual void v38();  virtual void v39();  virtual void v40();  virtual void v41();
    virtual void v42();  virtual void v43();  virtual void v44();  virtual void v45();  virtual void v46();  virtual void v47();
    virtual void v48();  virtual void v49();  virtual void v50();  virtual void v51();  virtual void v52();  virtual void v53();
    virtual void v54();  virtual void v55();  virtual void v56();  virtual void v57();  virtual void v58();  virtual void v59();
    virtual void v60();  virtual void v61();  virtual void v62();  virtual void v63();  virtual void v64();  virtual void v65();
    virtual void v66();  virtual void v67();  virtual void v68();  virtual void v69();  virtual void v70();  virtual void v71();
    virtual void v72();  virtual void v73();  virtual void v74();  virtual void v75();  virtual void v76();  virtual void v77();
    virtual void v78();  virtual void v79();  virtual void v80();  virtual void v81();  virtual void v82();  virtual void v83();
    virtual void v84();  virtual void v85();  virtual void v86();  virtual void v87();  virtual void v88();  virtual void v89();
    virtual void v90();  virtual void v91();  virtual void v92();  virtual void v93();  virtual void v94();  virtual void v95();
    virtual void v96();  virtual void v97();  virtual void v98();  virtual void v99();
    virtual u32 v100(s32 a, s32 b);
    virtual void v101(); virtual void v102(); virtual void v103(); virtual void v104(); virtual void v105(); virtual void v106();
    virtual void v107(); virtual void v108();
    virtual void v109(float* f, u8* p, s32 n);
};

extern "C" void fn_27_5C100(u8* self, u32 arg1) {
    if (arg1 == 1) {
        u8* a = *(u8**)(self + 0xc);
        u8* b = *(u8**)(a + 0xd8);
        SoVIface* c = (SoVIface*)*(u8**)(b + 0x54);
        if (c->v100(-1, 13) == 1) {
            a = *(u8**)(self + 0xc);
            b = *(u8**)(a + 0xd8);
            c = (SoVIface*)*(u8**)(b + 0x54);
            c->v109((float*)(self + 0x10), self + 0x14, -1);
        } else {
            s32 rate = (s32)g_GameGlobal->getSlowRate();
            s32 var = *(s32*)(self + 0x34) / rate;
            if (var < 1) {
                var = 1;
            }
            s32 t = *(s32*)(self + 0x28);
            if (t > 0) {
                t = t - 1;
                *(s32*)(self + 0x28) = t;
                if (t <= 0) {
                    var = 1;
                    *(s32*)(self + 0x34) = 1;
                    *(s32*)(self + 0x24) = 1;
                }
            }
            s32 m = *(s32*)(self + 0x24) - 1;
            *(s32*)(self + 0x24) = m;
            if (m <= 0) {
                *(s32*)(self + 0x24) = var;
                *(u8*)(self + 0x14) = 0;
            } else {
                *(u8*)(self + 0x14) = 1;
            }
            *(f32*)(self + 0x10) = lbl_27_rodata_7D8 / (f32)var;
        }
    }
    s32 n = *(s32*)(self + 0x30);
    if (n > 0) {
        n = n - 1;
        *(s32*)(self + 0x30) = n;
        if (n <= 0) {
            ((soNullable*)self)->fn_27_5C390();
        }
    }
}
