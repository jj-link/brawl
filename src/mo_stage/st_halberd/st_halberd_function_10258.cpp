#pragma force_active on

#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <ef/ef_id.h>
#include <ec/ec_mgr.h>
#include <types.h>

extern "C" void stopSE__14snd3DGeneratorFll(void*, s32, s32);
extern "C" void playSE__14snd3DGeneratorF5SndIDiii(void*, s32, s32, s32, s32);
extern "C" void fn_27_1F299C(void* mgr, s32 index);
extern "C" void cmReqQuake__FiP5Vec3f(s32 kind, const Vec3f* pos);
extern "C" void* g_aiMgr;
extern "C" const float lbl_57_rodata_300;
extern "C" const float lbl_57_rodata_35C;

class HalberdPad {
public:
    char pad[0x3c];
};

struct HalberdFlags {
    unsigned int kind : 3;
    unsigned int rest : 29;
};

class Halberd : public HalberdPad {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(unsigned long);
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98(unsigned long);
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118(unsigned long);
    char pad_40[0x154 - 0x40];
    float m_154;
    char pad_158[0x15c - 0x158];
    s8* m_15c;
    char pad_160[0x1c4 - 0x160];
    Vec3f m_1c4;
    char pad_1d0[0x1ec - 0x1d0];
    HalberdFlags m_1ec;
    char pad_1f0[0x268 - 0x1f0];
    snd3DGenerator m_268;
    s32 m_270;
    s32 m_274;
};

extern "C" void fn_57_10258(Halberd* self) {
    *self->m_15c = 0x11;
    self->v98(0);
    self->v118(1);
    s32 se = self->m_270;
    self->m_154 = lbl_57_rodata_35C;
    if (se != -1) {
        stopSE__14snd3DGeneratorFll(&self->m_268, se, 0);
    }
    self->m_270 = -1;
    g_ecMgr->setEffect(ef_ptc_stg_halberd_herohero, &self->m_1c4);
    playSE__14snd3DGeneratorF5SndIDiii(&self->m_268, 0x51, 0, 0, -1);
    Vec3f pos(lbl_57_rodata_300, lbl_57_rodata_300, lbl_57_rodata_300);
    cmReqQuake__FiP5Vec3f(5, &pos);
    s32 j = self->m_274;
    self->m_1ec.kind = 1;
    if (j != -1) {
        fn_27_1F299C(g_aiMgr, j);
        self->m_274 = -1;
    }
    self->v27(0);
}
