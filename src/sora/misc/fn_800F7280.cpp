#include <types.h>
#pragma force_active on
#include <gf/gf_archive.h>
#include <ut/ut_relocate.h>

extern const f32 lbl_805A2610;
extern const f32 lbl_805A2614;
extern s32 lbl_805A02F0;
extern char lbl_8059E3F8;

struct sndSystem;
extern sndSystem* g_sndSystem;
extern "C" void playSE__9sndSystemF5SndIDiiii(sndSystem* self, u32 id, s32 a, s32 b, s32 c, s32 d);

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

struct TaskBase {
    u8 pad[0x3c];
};

struct Obj : TaskBase {
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
    virtual void v25(s32 x);

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
    u8 pad414[0x428 - 0x414];
    u8 f428;
    u8 pad429[0x42c - 0x429];
    s32 f42c;
};

struct utRel {
    u8 pad[0x34];
};
extern "C" void __ct__10utRelocateFPUcUl(utRel* self, u8* data, u32 size);
extern "C" void __dt__10utRelocateFv(utRel* self, s32 flag);
extern "C" void* getPublicAddress__10utRelocateCFPCc(utRel* self, const char* name);

extern "C" void fn_800F5EEC(Obj* self, void* addr, s32 arg);

extern "C" void fn_800F7280(Obj* self, s32 arg1) {
    s32 var29 = arg1;
    if (arg1 < 0) {
        var29 = lbl_805A02F0;
        s32 t = var29 + 1;
        lbl_805A02F0 = t;
        if (t >= 0x29) {
            lbl_805A02F0 = 0;
        }
    }

    if (self->f88 != 0) {
        self->v25(1);
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
    self->f42c = -1;
    self->f428 = 0;

    gfArchive* arch = self->f40;
    void* r30 = (void*)&lbl_8059E3F8;
    if (arch == NULL) {
        r30 = 0;
    } else {
        u32 sp8 = 0;
        void* data = arch->getData(Data_Type_Misc, 0x3EF, (int*)&sp8, 0xFFFE);
        if (data != NULL) {
            utRel spC;
            __ct__10utRelocateFPUcUl(&spC, (u8*)data, sp8);
            r30 = getPublicAddress__10utRelocateCFPCc(&spC, (const char*)r30);
            __dt__10utRelocateFv(&spC, -1);
        } else {
            r30 = 0;
        }
    }

    fn_800F5EEC(self, r30, var29);

    char* p = (char*)self;
    s32 i = 0;
    while (i < self->f404) {
        if (self->f42c < 0) {
            s32 v = *(s32*)(p + 0x108);
            if (v != 4 && v != 5) {
                self->f42c = v;
            }
        }
        p += 0xc;
        i++;
    }

    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x18F5, -1, 0, 0, 0x25);
}
