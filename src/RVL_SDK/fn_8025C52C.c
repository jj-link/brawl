#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    u8 id;
    u8 dc;
    u8 ac;
    u8 pad;
    s16 pred;
} Comp;

typedef struct {
    u8 pad0[0x680];
    Comp comp[3];
    u16 unk692;
    u16 pad694;
    s16 unk696;
    u8 pad698[4];
    u8 *ptr;
    u8 pad6a0[8];
    u8 mask;
} Ctx;

extern Ctx *lbl_805A0D44;

s32 fn_8025C52C(void) {
    int dc;
    int ac;
    u8 i;
    int j;

    lbl_805A0D44->ptr += 2;
    if (*lbl_805A0D44->ptr++ != 3) {
        return 12;
    }
    i = 0;
    for (j = 0; j < 3; j++, i++) {
        u8 b;
        lbl_805A0D44->ptr++;
        b = *lbl_805A0D44->ptr++;
        dc = b >> 4;
        ac = b & 0xF;
        lbl_805A0D44->comp[i].dc = dc;
        lbl_805A0D44->comp[i].ac = ac;
        if (!(lbl_805A0D44->mask & (1 << dc))) {
            return 15;
        }
        if (!(lbl_805A0D44->mask & (1 << (ac + 1)))) {
            return 15;
        }
    }
    lbl_805A0D44->ptr += 3;
    lbl_805A0D44->unk696 = (lbl_805A0D44->unk692 + 15) / 16;
    lbl_805A0D44->comp[0].pred = 0;
    lbl_805A0D44->comp[1].pred = 0;
    lbl_805A0D44->comp[2].pred = 0;
    return 0;
}
