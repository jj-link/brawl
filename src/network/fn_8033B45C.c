#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_8033AEEC(int);
extern char lbl_80489E48[];
extern char lbl_8059F094[6];
extern char lbl_8059F09C[7];

typedef struct Arg {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} Arg;

void fn_8033B45C(int unused, Arg *arg1) {
    char *base = lbl_80489E48;
    char *var_r30;
    char *var_r29;

    if (arg1->unk4 == 0x603 || arg1->unk4 == 0x901 || arg1->unk4 == 0xB01) {
        fn_80335638(4, base + 0x5A0, arg1->unk4);
        return;
    }
    switch (arg1->unk0) {
    case 0: var_r29 = base + 0x5CC; break;
    case 1: var_r29 = base + 0x5D8; break;
    case 2: var_r29 = base + 0x5E8; break;
    case 3: var_r29 = base + 0x5FC; break;
    case 4: var_r29 = base + 0x610; break;
    default: var_r29 = base + 0x620; break;
    }
    switch (arg1->unk4) {
    case 0x0: var_r30 = base + 0x634; break;
    case 0x1: var_r30 = base + 0x640; break;
    case 0x2: var_r30 = base + 0x64C; break;
    case 0x3: var_r30 = base + 0x660; break;
    case 0x4: var_r30 = base + 0x670; break;
    case 0x5: var_r30 = base + 0x67C; break;
    case 0x6: var_r30 = base + 0x688; break;
    case 0x7: var_r30 = base + 0x6A0; break;
    case 0x100: var_r30 = base + 0x6B8; break;
    case 0x101: var_r30 = base + 0x6C4; break;
    case 0x102: var_r30 = base + 0x6D8; break;
    case 0x103: var_r30 = base + 0x6EC; break;
    case 0x104: var_r30 = base + 0x700; break;
    case 0x105: var_r30 = base + 0x718; break;
    case 0x106: var_r30 = base + 0x730; break;
    case 0x107: var_r30 = base + 0x74C; break;
    case 0x108: var_r30 = base + 0x768; break;
    case 0x200: var_r30 = base + 0x784; break;
    case 0x201: var_r30 = base + 0x790; break;
    case 0x202: var_r30 = base + 0x7A8; break;
    case 0x300: var_r30 = base + 0x7C0; break;
    case 0x301: var_r30 = base + 0x7CC; break;
    case 0x400: var_r30 = base + 0x7E4; break;
    case 0x401: var_r30 = base + 0x7F4; break;
    case 0x402: var_r30 = base + 0x80C; break;
    case 0x500: var_r30 = base + 0x828; break;
    case 0x501: var_r30 = base + 0x838; break;
    case 0x600: var_r30 = base + 0x850; break;
    case 0x601: var_r30 = base + 0x85C; break;
    case 0x602: var_r30 = base + 0x874; break;
    case 0x603: var_r30 = base + 0x888; break;
    case 0x700: var_r30 = base + 0x8A4; break;
    case 0x701: var_r30 = base + 0x8B0; break;
    case 0x702: var_r30 = base + 0x8C4; break;
    case 0x800: var_r30 = base + 0x8D8; break;
    case 0x900: var_r30 = lbl_8059F094; break;
    case 0x901: var_r30 = base + 0x8E8; break;
    case 0xA00: var_r30 = base + 0x8F8; break;
    case 0xA01: var_r30 = base + 0x908; break;
    case 0xB00: var_r30 = base + 0x924; break;
    case 0xB01: var_r30 = base + 0x930; break;
    case 0xC00: var_r30 = base + 0x948; break;
    case 0xC01: var_r30 = base + 0x958; break;
    case 0xD00: var_r30 = base + 0x974; break;
    case 0xD01: var_r30 = base + 0x980; break;
    default: var_r30 = base + 0x99C; break;
    }
    if (arg1->unkC != 0) {
        fn_80335638(2, base + 0x9B4);
    } else {
        fn_80335638(2, lbl_8059F09C);
    }
    fn_80335638(2, base + 0x9C4, var_r29, arg1->unk0);
    fn_80335638(2, base + 0x9D8, var_r30, arg1->unk4);
    fn_80335638(2, base + 0x9F0, arg1->unk8);
    fn_8033AEEC(3);
}
