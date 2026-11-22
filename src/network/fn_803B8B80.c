#pragma force_active on
typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    char pad0[4];
    u8 *unk4;
    u8 *unk8;
    char padC[0xC];
    u32 unk18;
} Buf;

typedef struct {
    u16 unk0;
    char pad2[0xA];
    u32 unkC;
    char pad10[8];
    u16 unk18;
    char pad1a[6];
    u8 unk20;
    u8 pad21;
    u8 unk22;
    char pad23[5];
    u32 unk28;
    char pad2c[8];
    s32 unk34;
    char pad38[0x1600 - 0x38];
    u32 unk1600;
    char pad1604[0x1870 - 0x1604];
    s32 unk1870;
    char pad1874[0x1890 - 0x1874];
    s32 (*unk1890)(s32);
} Ctx;

extern int fn_803AFC80(Buf *);
extern s32 fn_803AFEDC(Ctx *, u32, Buf **);
extern s32 fn_803B6F80(Ctx *, Buf *);

#define LOADSEC(SEC, CNT)                                                   \
    {                                                                       \
        s32 r_;                                                             \
        r_ = fn_803B6F80(arg0, buf);                                        \
        if (r_ != 0) return r_;                                             \
        CNT = 1;                                                            \
        if (arg0->unk18 & 0x80) CNT = arg0->unk18 & 7;                      \
        do {                                                                \
            ret = fn_803AFEDC(arg0, SEC, arg3);                             \
            if (ret == 0x1000 && arg0->unk1890 != 0) {                      \
                s32 s_ = arg0->unk1890(arg0->unk1870);                      \
                if (s_ == 0) continue;                                      \
                if (s_ == 1 && arg0->unk22 >= 2 && CNT < arg0->unk22) {     \
                    CNT++;                                                  \
                    sector += arg0->unkC;                                   \
                    continue;                                               \
                }                                                           \
            }                                                               \
            if (ret != 0) return ret;                                       \
        } while (ret != 0);                                                 \
    }

s32 fn_803B8B80(Ctx *arg0, u32 arg1, u32 arg2, Buf **arg3)
{
    s32 ret;
    u32 sector;
    u16 pos;
    u32 cnt;
    u32 cnt2;
    Buf *buf;
    u16 off;
    u32 next;
    u32 base;
    u16 size2;
    u32 next2;
    u32 base2;
    u16 size3;
    u8 shift;
    u16 size;

    ret = 0;
    if (arg0 == 0) {
        return 0xA;
    }
    if ((arg1 < 2 || arg1 >= (u32)(arg0->unk34 + 2)) && arg1 != 0 && arg1 != 1) {
        return 0xE;
    }
    shift = arg0->unk20;
    off = (u16)(arg1 + ((u16)arg1 >> 1));
    buf = *arg3;
    sector = (u16)(arg0->unk28 + ((u32)off >> shift));
    size = arg0->unk0;
    pos = off & (size - 1);
    if (buf->unk18 > sector || buf->unk18 + arg0->unk1600 <= sector) {
        LOADSEC(sector, cnt)
    } else if (sector != buf->unk18 + ((s32)(buf->unk8 - buf->unk4) >> shift)) {
        buf->unk8 = buf->unk8 + size;
    }
    if (arg1 & 1) {
        (*arg3)->unk8[pos] = ((*arg3)->unk8[pos] & 0xF) | ((arg2 << 4) & 0xF0);
        fn_803AFC80(*arg3);
        size2 = arg0->unk0;
        if (pos == (u32)(size2 - 1)) {
            buf = *arg3;
            next = sector + 1;
            base = buf->unk18;
            if (base > next || base + arg0->unk1600 <= next) {
                LOADSEC(sector + 1, arg1)
                fn_803AFC80(*arg3);
            } else if (next != base + ((s32)(buf->unk8 - buf->unk4) >> arg0->unk20)) {
                buf->unk8 = buf->unk8 + size2;
                fn_803AFC80(*arg3);
            }
            (*arg3)->unk8[0] = (u8)(arg2 >> 4);
        } else {
            (*arg3)->unk8[pos + 1] = (u8)(arg2 >> 4);
        }
    } else {
        (*arg3)->unk8[pos] = arg2;
        fn_803AFC80(*arg3);
        size3 = arg0->unk0;
        if (pos == (u32)(size3 - 1)) {
            buf = *arg3;
            next2 = sector + 1;
            base2 = buf->unk18;
            if (base2 > next2 || base2 + arg0->unk1600 <= next2) {
                LOADSEC(sector + 1, arg1)
                fn_803AFC80(*arg3);
            } else if (next2 != base2 + ((s32)(buf->unk8 - buf->unk4) >> arg0->unk20)) {
                buf->unk8 = buf->unk8 + size3;
                fn_803AFC80(*arg3);
            }
            (*arg3)->unk8[0] = ((*arg3)->unk8[0] & 0xF0) | (u8)(arg2 >> 8);
        } else {
            u8 *p = (u8 *)((u32)pos + (u32)(*arg3)->unk8);
            p[1] = (u8)(arg2 >> 8) | (p[1] & 0xF0);
        }
    }
    return ret;
}
