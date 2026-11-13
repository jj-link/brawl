#include <types.h>
#include <gf/gf_shutdown_manager.h>
#pragma force_active on

struct FnSub {
    char pad0[0x20];
    f32 unk20;
    f32 unk24;
    char pad1[0x36];
    s8 unk5E;
    char pad2[0x1];
    void* unk60;
    char pad3[0x8];
    f32 unk6C;
    f32 unk70;
};

struct FnSlot {
    FnSub* unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
};

struct FnObj {
    char pad0[0x50];
    FnSlot slots[4];
    char pad1[0xC];
    s32 unk9C;
    char pad2[0x10];
};

struct FnB0 {
    u32 top : 4;
    u32 rest : 28;
};

struct FnB1 {
    u8 p0 : 1;
    u8 p1 : 1;
    u8 p2 : 1;
    u8 p3 : 1;
    u8 p4 : 4;
};

struct FnMgrHdr {
    char pad0[0x74];
    u8 hi : 4;
    u8 flag : 1;
    u8 lo : 3;
};

extern "C" {
int fn_8003798C(void);
int fn_8021A024(int, s32*);
void fn_80227728(int, void*, int);
void fn_80228138(int);
int fn_800365B0(void*, void*);
int fn_8026F6C4(void*);
int fn_8026F834(void);
void fn_8026F924(void);
void fn_8026F958(void);
u8* fn_80023AC8(void);
extern char lbl_804955D8[];
extern f32 lbl_805A1678;
extern f32 lbl_805A16A0;
extern f32 lbl_805A16A4;
extern f32 lbl_805A16C0;
}

extern "C" void fn_80037244(FnObj* self) {
    s32 r29b;
    if (fn_8003798C() != 0) {
        f32 f31;
        f32 f30;
        f32 f29;
        f32 f28;
        char* cur;
        FnSlot* slot;
        s32 i;
        f30 = lbl_805A16A0;
        f31 = lbl_805A16A4;
        cur = lbl_804955D8;
        f28 = lbl_805A16C0;
        slot = self->slots;
        f29 = lbl_805A1678;
        for (i = 0; i < 4; i++) {
            s32 sp8;
            s32 r29 = fn_8021A024(i, &sp8);
            fn_80227728(i, cur, 0x10);
            slot->unkC = sp8;
            switch (r29) {
            case 0:
            case -2:
            case -3:
            case -4:
            case -7:
                slot->unk0 = (FnSub*)cur;
                break;
            default:
                slot->unk0 = 0;
                break;
            }
            FnSub* sub = slot->unk0;
            if (sub != 0) {
                s32 r3_2 = fn_800365B0(sub->unk60, &slot->unk4);
                FnSub* s4 = slot->unk0;
                f32 b = s4->unk70 / f28;
                f32 a = s4->unk6C / f28;
                s32 var_r0;
                if (f29 == a && f29 == b) {
                    var_r0 = 0;
                } else {
                    f32 x = slot->unk4 + a;
                    slot->unk4 = x;
                    slot->unk8 = slot->unk8 - b;
                    if (x > f30) {
                        x = f30;
                    } else if (x < f31) {
                        x = f31;
                    }
                    slot->unk4 = x;
                    f32 y = slot->unk8;
                    if (y > f30) {
                        y = f30;
                    } else if (y < f31) {
                        y = f31;
                    }
                    slot->unk8 = y;
                    var_r0 = 1;
                }
                if ((r3_2 | var_r0) == 0) {
                    FnSub* s5 = slot->unk0;
                    if (s5->unk5E > 0) {
                        slot->unk4 = s5->unk20;
                        slot->unk8 = slot->unk0->unk24;
                    }
                }
            }
            cur += 0x840;
            slot++;
        }
        if (fn_8026F6C4(self->slots) >= 0) {
            s32 three = 3;
            ((FnB1*)((char*)self + 0xB1))->p3 = 0;
            ((FnB0*)((char*)self + 0xB0))->top = three;
            fn_8026F924();
            self->unk9C = 4;
            r29b = ((FnB1*)((char*)self + 0xB1))->p1;
            FnMgrHdr* mh = (FnMgrHdr*)fn_80023AC8();
            mh->flag = r29b;
            fn_80228138(0);
            fn_80228138(1);
            fn_80228138(2);
            fn_80228138(3);
            gfShutdownManager* mgr = &g_gfShutdownManager;
            int st = fn_8026F834();
            switch (st) {
            case 0:
                break;
            case 1:
                mgr->enterReturnToWiiMenuProcess();
                break;
            case 2:
                mgr->enterRestartProcess();
                break;
            case 3:
                break;
            }
        }
        fn_8026F958();
    }
}