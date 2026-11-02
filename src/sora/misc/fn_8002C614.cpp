#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct Reader {
    u8 pad0[9];
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u16 unkC;
    u16 unkE;
    s32 unk10;
    u16* unk14;
    u16* unk18;
    u16* unk1C;
};

extern "C" s32 fn_8002C614(void* unused, Reader* arg1, u8* arg2) {
    u16* p;
    u16 w;
    u16 v;
    s32 cnt;

    if (arg1->unk9 == 1) {
        return 0;
    }
    while (arg1->unkE == 0) {
        p = arg1->unk18;
        w = *p;
        switch ((w >> 13) & 7) {
        case 0:
            if (arg1->unk10 == -2) {
                return 1;
            }
            arg1->unk18 = arg1->unk1C;
            if ((((*arg1->unk1C) >> 13) & 7) == 0) {
                return 1;
            }
            break;
        case 1:
            arg1->unkB = 2;
            v = *p & 0x1FFF;
            arg1->unk18 = p + 1;
            arg1->unkE = v;
            break;
        case 2:
            arg1->unkB = 1;
            v = *p & 0x1FFF;
            arg1->unk18 = p + 1;
            arg1->unkE = v;
            break;
        case 3:
            arg1->unkB = 0;
            v = *p & 0x1FFF;
            arg1->unk18 = p + 1;
            arg1->unkE = v;
            break;
        case 4:
            arg1->unkC = w & 0x1FFF;
            arg1->unk18 = p + 1;
            arg1->unk14 = p + 1;
            break;
        case 5:
            arg1->unkC--;
            if (arg1->unkC != 0) {
                arg1->unk18 = arg1->unk14;
            } else {
                arg1->unk18 = p + 1;
            }
            break;
        default:
            break;
        }
    }
    *arg2 = arg1->unkB;
    arg1->unkE--;
    cnt = arg1->unk10;
    if (cnt != -1 && cnt != -2) {
        arg1->unk10 = cnt - 1;
        if (cnt - 1 == 0) {
            return 1;
        }
    }
    return 0;
}
