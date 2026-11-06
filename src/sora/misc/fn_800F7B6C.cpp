#include <types.h>
#include <gf/gf_archive.h>
#include <ut/ut_relocate.h>
#pragma force_active on

extern char lbl_8059E3F8;

extern "C" void fn_800F5EEC(void* self, void* addr, s32 arg);

struct gfTask_base {
    char pad[0x3c];
};

class gfTask : public gfTask_base {
public:
    virtual void fn_800F7454();
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
    virtual void fn_800F7168();
    virtual void fn_800F7280();
    virtual void fn_800F5A58();
    virtual void fn_800F7450();
    virtual void fn_800F5C60();
    virtual void fn_800F7CAC();
    virtual void fn_800F5CBC();
    virtual void fn_800F7538();
    virtual void fn_800F7650();
    virtual void fn_800F7768();

    gfArchive* f40;
    u8 pad44[0x88 - 0x44];
    s32 f88;
    s32 f8c;
    u8 pad90[0xf4 - 0x90];
    s32 ff4;
    u8 padf8[0x428 - 0xf8];
    u8 f428;
    u8 pad429[0x42c - 0x429];
    s32 f42c;
};

extern "C" void fn_800F7B6C(gfTask* self) {
    void* r31;
    s32 var5;

    self->f428 = 1;
    self->ff4 = -1;

    gfArchive* arch = self->f40;
    r31 = (void*)&lbl_8059E3F8;
    if (arch == NULL) {
        r31 = NULL;
    } else {
        u32 sp8 = 0;
        void* data = arch->getData(Data_Type_Misc, 0x3EF, (int*)&sp8, 0xFFFE);
        if (data != NULL) {
            utRelocate spC((u8*)data, sp8);
            r31 = spC.getPublicAddress((const char*)r31);
        } else {
            r31 = NULL;
        }
    }

    var5 = -1;
    switch (self->f42c) {
    case 0:
        var5 = 0xD;
        break;
    case 1:
        var5 = 0x26;
        break;
    case 2:
        var5 = 0x1A;
        break;
    case 3:
        var5 = 0x28;
        break;
    }
    if (var5 >= 0) {
        fn_800F5EEC(self, r31, var5);
        self->f88 = 3;
        self->f8c = 0;
        self->fn_800F7768();
    }
}
