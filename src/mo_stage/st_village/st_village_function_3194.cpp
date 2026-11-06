#include <types.h>
#include <ft/ft_manager.h>
#include <gm/gm_global.h>
#include <mt/mt_prng.h>

#pragma force_active on

struct Base {
    char pad[0x3c];
};

class Self : public Base {
public:
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
    virtual void v27();
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
    virtual void v98();
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
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128(int state, int a, int b, void* p);
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual int v140(int id, void* out);

    char pad40[0x114];
    float f154;
    char pad158[0x4C];
    u8* p1A4;
    char pad1A8[8];
    s32 i1B0;
    u32 u1B4;
    u32 u1B8;
    u8 b1BC;
    char pad1BD[3];
    u8 arr1C0[4];
};

struct OwnerPad {
    char pad[0xc];
};

class OwnerLike : public OwnerPad {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual float f3();
};

extern "C" const float lbl_70_rodata_48[];

extern "C" void fn_70_3194(Self* self) {
    const float* k = lbl_70_rodata_48;
    float sp8[3];
    u32 state = 5;

    if (self->i1B0 != -1) {
        u8* mm = (u8*)g_GameGlobal->m_modeMelee;
        if (mm == 0) {
            return;
        }
        u8* rr = (u8*)g_GameGlobal->m_resultInfo;
        if (rr == 0) {
            return;
        }
        u8 idx = mm[self->i1B0 * 0x5c + 0x9b];
        u8* e = rr + idx * 0x2ac;

        if (*(u32*)(e + 0x34) > self->u1B4) {
            state = 2;
            self->f154 = k[4];
        } else {
            u32 sum = *(u32*)(e + 0x38) + *(u16*)(e + 0x3c);
            if (sum > self->u1B8) {
                state = 4;
                self->f154 = k[5];
            }
        }

        if (k[0] == self->f154) {
            int id = g_ftManager->getEntryId(self->i1B0);
            float v;
            if (g_ftManager->isValidEntryId(id) == 0) {
                v = k[0];
            } else {
                v = ((OwnerLike*)g_ftManager->getOwner(id))->f3();
            }

            if (v > k[6] && randf() < k[7]) {
                state = 3;
                self->f154 = k[8];
            } else if (randf() < k[9]) {
                self->i1B0 = -1;
                state = 10;
                self->f154 = k[8];
            } else {
                u8 b = self->b1BC;
                if (b == 6) {
                    if (randf() < k[7]) {
                        state = 7;
                        self->f154 = k[8];
                    } else {
                        state = 0;
                        self->f154 = k[10];
                    }
                } else if (b == 7) {
                    state = 6;
                    self->f154 = k[10];
                } else {
                    float r = randf();
                    if (r < k[11]) {
                        state = 5;
                        self->f154 = k[8];
                    } else if (r < k[12]) {
                        state = 6;
                        self->f154 = k[2];
                    } else {
                        state = 0;
                        self->f154 = k[10];
                    }
                }
            }
        }

        self->u1B4 = *(u32*)(e + 0x34);
        self->u1B8 = *(u32*)(e + 0x38) + *(u16*)(e + 0x3c);
    } else {
        self->f154 = k[10];
        self->i1B0 = -1;
        state = 10;
    }

    if (state != 5) {
        if (((u8*)((u32)self->p1A4 + state))[8] == 1) {
            self->v128(state, 1, 0, self->arr1C0);
        }
        if (state == 10 && self->i1B0 == -1) {
            s32 val = (s32)(k[13] * randf());
            self->i1B0 = val;
            if (self->v140(val, sp8) == 0) {
                self->i1B0 = -1;
            }
        }
    }
}
