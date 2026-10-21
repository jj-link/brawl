#pragma force_active on

typedef int s32;
typedef unsigned char u8;

struct muSelCharPlayerArea {
    char pad0[0x1B4];
    s32 unk1B4;
    s32 unk1B8;
    s32 unk1BC;
    s32 unk1C0;
    u8 unk1C4;
    char pad1[0x23];
    s32 unk1E8;
    s32 unk1EC;
    s32 unk1F0;
};

extern "C" u8 lbl_10_rodata_568[];

extern "C" s32 isTeamBattle__19muSelCharPlayerAreaFv(muSelCharPlayerArea*);
extern "C" void setCharPic__19muSelCharPlayerAreaFiiibii(
    muSelCharPlayerArea*, s32, s32, s32, s32, s32, s32);

extern "C" void fn_10_12140(muSelCharPlayerArea* arg0, s32 arg1) {
    s32 r31;
    s32 r30;
    s32 sel;
    u8* tbl;

    tbl = lbl_10_rodata_568;
    sel = arg0->unk1B8;
    arg0->unk1F0 = arg1;

    if (sel == 0x1B) {
        switch (sel) {
        case 0xE:
            tbl = (u8*)((unsigned int)tbl + 0x18);
            sel = tbl[arg0->unk1E8];
            break;
        case 3:
            tbl = (u8*)((unsigned int)tbl + 0x1C);
            sel = tbl[arg0->unk1EC];
            break;
        case 0x1B:
            tbl = (u8*)((unsigned int)tbl + 0x20);
            sel = tbl[arg1];
            break;
        }

        r31 = arg0->unk1BC;
        r30 = arg0->unk1B4;
        setCharPic__19muSelCharPlayerAreaFiiibii(
            arg0, sel, r30, r31,
            isTeamBattle__19muSelCharPlayerAreaFv(arg0),
            arg0->unk1C0, arg0->unk1C4);
    }
}
