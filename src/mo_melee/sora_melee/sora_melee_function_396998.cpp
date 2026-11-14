#pragma force_active on
#pragma fp_contract off
#include <types.h>
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
f32 fn_27_192278(void*, unsigned long);
extern char lbl_27_data_17780[];
extern char lbl_27_data_9E50[];
extern char lbl_27_data_69C0[];
extern char lbl_27_data_248[];
extern const f32 lbl_27_rodata_7D88[2];
const f32 lbl_27_rodata_7D88[2] = {0.0f, 0.0f};
}
#define V(n) virtual void v##n();
#define R(b) V(b##0) V(b##1) V(b##2) V(b##3) V(b##4) V(b##5) V(b##6) V(b##7) V(b##8) V(b##9)
struct SoModule42 {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13)
    virtual s32 v14(s32);
    V(15) V(16)
    virtual s32 v17(unsigned long);
    V(18)
    virtual void v19(unsigned long, void*);
    V(20)
    virtual void v21(void*, s32);
    V(22) V(23) V(24) V(25) V(26)
    virtual void v27(s32);
    V(28) V(29) V(30) V(31)
    virtual void v32(s32);
    V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40)
    virtual void v41(s32, s32);
};
struct Pad8 { char pad[8]; };
struct Pad3c { char pad[0x3c]; };
struct DamageInfo { s32 a, b, c; };
struct HitInfo { s32 slot, value, flags, extra; };
struct ModuleAt4 : Pad8 {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35)
    virtual DamageInfo v36(s32, s32);
};
struct ModuleAt38 : Pad8 {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16)
    virtual void v17(s32, f32);
    virtual f32 v18(s32);
};
struct LinkObs : Pad3c {
    R(0) R(1) R(2) R(3)
    virtual s32 v40();
};
struct Report {
    s32 index;
    unsigned char flag;
    char pad1[3];
    s32 w0, w1, w2, w3;
    f32 value;
    unsigned char byte;
    char pad2[3];
};
struct FrameBlock {
    Report report;
    HitInfo hit;
};
struct Task : Pad3c {
    R(0) R(1) R(2) R(3) R(4) R(5) R(6) R(7) R(8) R(9)
    R(10) R(11) R(12) R(13) R(14) R(15) R(16) R(17)
    V(180) V(181) V(182) V(183) V(184) V(185) V(186) V(187)
    virtual void v188(Report*);
};
struct Modules {
    char pad_0[4];
    ModuleAt4* unk4;
    char pad0[0x38 - 0x8];
    ModuleAt38* unk38;
    char pad1[0x64 - 0x3c];
    SoModule42* work;
    char pad2[0xa8 - 0x68];
    SoModule42* itemManage;
};
struct Accesser {
    char pad0[8];
    LinkObs* unk8;
    char pad1[0xd8 - 0xc];
    Modules* unkD8;
};
extern "C" void fn_27_396998(void* unused, Accesser* arg2) {
    DamageInfo dmg;
    FrameBlock fb;
    SoModule42* impl;
    Task* task;
    s32 kind;
    s32 slot;
    Accesser* const self = arg2;
    f32 f29;

    if (self->unkD8->work->v17(0x2200001A) != 0) {
        return;
    }
    if (self->unkD8->work->v17(0x22000013) != 0) {
        SoModule42* search = (SoModule42*)__dynamic_cast(self->unkD8->itemManage, 0,
                                                         lbl_27_data_17780, lbl_27_data_9E50, 1);
        for (s32 i = 3; i < 7; i++) {
            if (search->v14(i) != 0) {
                search->v41(0, i);
            }
        }
        self->unkD8->work->v19(0x22000013, self->unkD8);
    }
    if (self->unkD8->work->v17(0x22000014) == 0) {
        return;
    }
    impl = (SoModule42*)__dynamic_cast(self->unkD8->itemManage, 0,
                                       lbl_27_data_17780, lbl_27_data_9E50, 1);
    task = (Task*)__dynamic_cast(self->unk8, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    kind = (self->unk8->v40() == 0x20) ? 6 : 0x196;
    for (slot = 3; slot < 7; slot++) {
        if (impl->v14(slot) != 0) {
            impl->v21(&fb.hit, slot);
            f32 f30 = self->unkD8->unk38->v18(0);
            f29 = lbl_27_rodata_7D88[0];
            if (fb.hit.flags & 0x20b0) {
                impl->v32(slot);
            } else if (fb.hit.flags & 0x8000) {
                f29 = fn_27_192278(self, 0xfa8);
            } else if (f30 - fn_27_192278(self, 0xfa9) < lbl_27_rodata_7D88[0]) {
                f29 = -f30;
            } else {
                f29 = -fn_27_192278(self, 0xfa9);
            }
            dmg = self->unkD8->unk4->v36(kind, 0);
            fb.report.index = -1;
            fb.report.flag = 0;
            fb.report.w0 = fb.hit.value;
            fb.report.w1 = dmg.a;
            fb.report.w2 = dmg.b;
            fb.report.w3 = dmg.c;
            fb.report.value = lbl_27_rodata_7D88[0];
            fb.report.byte = 0;
            task->v188(&fb.report);
            self->unkD8->unk38->v17(0, f29);
            self->unkD8->itemManage->v27(slot);
        }
    }
    self->unkD8->work->v19(0x22000014, self->unkD8);
}
