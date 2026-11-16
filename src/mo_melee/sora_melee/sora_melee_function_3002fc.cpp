#pragma force_active on
#include <mt/mt_vector.h>
#include <ec/ec_mgr.h>

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
void* fn_27_2FFA0C(void*);
extern char lbl_27_data_248[];
extern char lbl_27_data_80608[];
extern const float lbl_27_rodata_6540;
extern const float lbl_27_rodata_654C;
}

extern ecMgr* g_ecMgr;

class Mod {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int getB(unsigned long);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual float getF(unsigned long, void*);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual int getA();
    virtual void v19();
    virtual void v20();
    virtual void setTwo(int, int);
    virtual void v22();
    virtual void v23();
    virtual float scale();
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
    virtual Vec3f get39(int, float*, int, int);
};

struct Pad8 { int a; int b; };
class Obj4 {
    int pad[2];
public:
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual int getB(unsigned long);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13();
    virtual float getF(unsigned long, void*);
    virtual void v15(); virtual void v16(); virtual void v17();
    virtual int getA();
    virtual void v19(); virtual void v20();
    virtual void setTwo(int, int);
    virtual void v22(); virtual void v23(); virtual float scale();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38();
    virtual Vec3f get39(int, float*, int, int);
};

struct Ctx {
    char pad0[4];
    Obj4* p4;
    char pad8[4];
    Mod* pC;
    Obj4* p10;
    char pad14[0x50];
    Mod* p64;
    char pad68[8];
    Mod* p70;
};

struct Self {
    char pad0[8];
    void* p8;
    char pad1[0xCC];
    Ctx* ctx;
};

struct Anim {
    char pad[0x18];
    float lo;
    float hi;
};

struct Holder {
    char pad[0x34];
    Anim* anim;
};

inline void updatePos(Self* self, ecMgr* mgr, unsigned long handle, Vec3f& w) {
    Vec3f pos = self->ctx->p4->get39(0, &w.m_x, 0, 0);
    mgr->setPos(handle, &pos);
}
inline void updateScale(unsigned long handle, float scale) {
    Vec3f scl;
    scl.m_x = scale;
    scl.m_y = scale;
    scl.m_z = scale;
    g_ecMgr->setScl(handle, &scl);
}

extern "C" void fn_27_3002FC(void*, Self* self) {
    ecMgr* mgr;
    int r29 = self->ctx->p70->getA();
    unsigned long r27 = self->ctx->p64->getB(0x10000006);
    Vec3f w;
    if (self->ctx->p64->getB(0x10000007) == 3) {
        w = Vec3f((r29 == 0) ? lbl_27_rodata_654C : lbl_27_rodata_6540,
                  lbl_27_rodata_6540, lbl_27_rodata_6540);
    } else {
        w = Vec3f((r29 == 0) ? lbl_27_rodata_6540 : 0.0f,
                  lbl_27_rodata_6540, lbl_27_rodata_6540);
    }
    mgr = g_ecMgr;
    updatePos(self, mgr, r27, w);
    Anim* anim = ((Holder*)fn_27_2FFA0C(__dynamic_cast(self->p8, 0x3C, lbl_27_data_80608, lbl_27_data_248, 1)))->anim;
    float f1 = self->ctx->p64->getF(0x11000001, self->ctx);
    float hi = anim->hi;
    float lo = anim->lo;
    float f0 = (hi - lo) * f1;
    float f31 = lo + f0;
    f31 *= self->ctx->pC->scale();
    updateScale(r27, f31);
    switch (r29) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        self->ctx->p10->setTwo(5, 0);
        break;
    }
}
