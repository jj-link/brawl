#include <types.h>
#pragma force_active on

extern "C" {
struct Rodata { float f[10]; };
extern const Rodata lbl_68_rodata_208;
extern void* g_ftManager;
void* memset(void*, int, unsigned long);
int fn_27_10B224(void*, void*, void*, void*, int, float, float, float, float);
}

struct F2 { float a; char pad[8]; float b; };

struct Obj {
    char pad[0x3c];
    char vtable[4];
    char pad2[0x128];
    F2* p168;
    float* vec16c;
    unsigned char* b170;
    unsigned char* b174;
    char pad3[0x40];
    float f1b8, f1bc, f1c0, f1c4;
};

struct Ground {
    char pad[0x3c];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual void v112();
    virtual void fn_68_13888(int, char*, unsigned char*);
};

extern "C" void fn_68_13234(void* self, float dt) {
    Obj* o = (Obj*)self;
    Ground* g = (Ground*)self;
    const Rodata* rd = &lbl_68_rodata_208;

    if (o->f1b8 > rd->f[2]) o->f1b8 = o->f1b8 - dt;
    if (o->f1bc > rd->f[2]) o->f1bc = o->f1bc - dt;
    if (o->f1c0 > rd->f[2]) o->f1c0 = o->f1c0 - dt;
    if (o->f1c4 > rd->f[2]) o->f1c4 = o->f1c4 - dt;

    if (o->f1b8 > rd->f[2]) o->vec16c[0] = o->vec16c[0] + dt; else o->vec16c[0] = rd->f[2];
    if (o->f1bc > rd->f[2]) o->vec16c[1] = o->vec16c[1] + dt; else o->vec16c[1] = rd->f[2];
    if (o->f1c0 > rd->f[2]) o->vec16c[2] = o->vec16c[2] + dt; else o->vec16c[2] = rd->f[2];
    if (o->f1c4 > rd->f[2]) o->vec16c[3] = o->vec16c[3] + dt; else o->vec16c[3] = rd->f[2];

    if (!*o->b174) {
        F2* v = o->p168;
        float zero = rd->f[2];
        float delta = v->b - v->a;
        float twentyfive = rd->f[3];
        unsigned char sp8;
        float sp10[4];
        char sp20[0x24];
        char sp44[0x6c];

        memset(sp20, 0, 0x24);
        memset(sp44, 0, 0x6c);
        {
            float half = rd->f[5];
            float c = rd->f[4];
            float hd = half * delta;
            float h25 = half * twentyfive;
            sp8 = 0;
            sp10[0] = zero - hd;
            sp10[1] = zero + hd;
            sp10[2] = c + h25;
            sp10[3] = c - h25;
            int res = fn_27_10B224(g_ftManager, sp10, sp20, sp44, 1, sp10[2], sp10[1], sp10[0], c);
            if (res > 0) {
                o->f1b8 = rd->f[6];
                g->fn_68_13888(res, sp44, &sp8);
                if (sp8 == 1) *o->b170 = 1; else *o->b170 = 0;
            }
        }

        memset(sp20, 0, 0x24);
        memset(sp44, 0, 0x6c);
        {
            float half = rd->f[5];
            float c = rd->f[7];
            float hd = half * delta;
            float h25 = half * twentyfive;
            sp8 = 0;
            sp10[0] = zero - hd;
            sp10[1] = zero + hd;
            sp10[2] = c + h25;
            sp10[3] = c - h25;
            int res = fn_27_10B224(g_ftManager, sp10, sp20, sp44, 1, sp10[2], sp10[1], sp10[0], c);
            if (res > 0) {
                o->f1bc = rd->f[6];
                g->fn_68_13888(res, sp44, &sp8);
                if (sp8 == 1) *o->b170 = 1; else *o->b170 = 0;
            }
        }

        memset(sp20, 0, 0x24);
        memset(sp44, 0, 0x6c);
        {
            float half = rd->f[5];
            float c = rd->f[8];
            float hd = half * delta;
            float h25 = half * twentyfive;
            sp8 = 0;
            sp10[0] = zero - hd;
            sp10[1] = zero + hd;
            sp10[2] = c + h25;
            sp10[3] = c - h25;
            int res = fn_27_10B224(g_ftManager, sp10, sp20, sp44, 1, sp10[2], sp10[1], sp10[0], c);
            if (res > 0) {
                o->f1c0 = rd->f[6];
                g->fn_68_13888(res, sp44, &sp8);
                if (sp8 == 1) *o->b170 = 1; else *o->b170 = 0;
            }
        }

        memset(sp20, 0, 0x24);
        memset(sp44, 0, 0x6c);
        {
            float half = rd->f[5];
            float c = rd->f[9];
            float hd = half * delta;
            float h25 = half * twentyfive;
            sp8 = 0;
            sp10[0] = zero - hd;
            sp10[1] = zero + hd;
            sp10[2] = c + h25;
            sp10[3] = c - h25;
            int res = fn_27_10B224(g_ftManager, sp10, sp20, sp44, 1, sp10[2], sp10[1], sp10[0], c);
            if (res > 0) {
                o->f1c4 = rd->f[6];
                g->fn_68_13888(res, sp44, &sp8);
                if (sp8 == 1) *o->b170 = 1; else *o->b170 = 0;
            }
        }
    }
}
