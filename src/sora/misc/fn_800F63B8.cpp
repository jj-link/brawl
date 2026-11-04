#include <types.h>
#include <gf/gf_archive.h>
#include <ut/ut_relocate.h>
#pragma force_active on

extern s32 lbl_805A02E8;
extern char lbl_8059E3F8;
extern const f32 lbl_805A2610;
extern const f32 lbl_805A2614;

extern "C" void fn_800F5EEC(void* self, void* addr, s32 arg);

struct VtB {
    virtual ~VtB();
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void method11(void* x, void* y);
    u8 pad[0xe0];
    void* f_e4;
};

struct Ptr9C {
    u8 pad[0x10];
    void* val;
};

struct gfTask_base {
    char pad[0x3c];
};

class gfTask : public gfTask_base {
public:
    virtual void fn_800F6520();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_800F6280();
    virtual void fn_800F63B8(s32 arg1);
    virtual void fn_800F5A58();
    virtual void fn_800F5AEC(s32 arg1);

    gfArchive* f40;
    u8 pad44[0x88 - 0x44];
    s32 f88;
    s32 f8c;
    VtB* p90;
    u8 pad94[0x9c - 0x94];
    Ptr9C* p9c;
    u8 flagA0;
    u8 padA1[0x404 - 0xa1];
    s32 f404;
    s32 f408;
    f32 f40c;
    f32 f410;
};

extern "C" void fn_800F63B8(gfTask* self, s32 arg1) {
    s32 var30 = arg1;
    if (arg1 < 0) {
        var30 = lbl_805A02E8;
        s32 t = var30 + 1;
        lbl_805A02E8 = t;
        if (t >= 0xF) {
            lbl_805A02E8 = 0;
        }
    }
    if (self->f88 != 0) {
        self->fn_800F5AEC(1);
    }
    self->f88 = 1;
    self->f8c = 0;
    if (self->flagA0 == 0) {
        VtB* o = self->p90;
        o->method11(o->f_e4, self->p9c->val);
        self->flagA0 = 1;
    }
    self->f404 = 0;
    self->f408 = -1;
    self->f410 = lbl_805A2610;
    self->f40c = lbl_805A2614;

    gfArchive* arch = self->f40;
    void* r31 = (void*)&lbl_8059E3F8;
    if (arch == NULL) {
        r31 = NULL;
    } else {
        u32 sp8 = 0;
        void* data = arch->getData(Data_Type_Misc, 0x76, (int*)&sp8, 0xFFFE);
        if (data != NULL) {
            utRelocate spC((u8*)data, sp8);
            r31 = spC.getPublicAddress((const char*)r31);
        } else {
            r31 = NULL;
        }
    }
    fn_800F5EEC(self, r31, var30);
}
