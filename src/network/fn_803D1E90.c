#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct FooHeader {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u8 pad8[0x14];
    u32 unk1C;
} FooHeader;

extern void fn_801F28F0(void *, void *, u16, u16, u8, u8, u8, u8);
extern void fn_801F2B44(void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void *fn_803CD284();
extern void fn_803CD298(void *ptr);
extern void fn_803CDEDC(s32, s32);
extern void fn_803CE048(s32, s32, void *);
extern void *memcpy(void *, const void *, u32);
extern f32 lbl_805A49F4;

void fn_803D1E90(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    FooHeader *hdr;
    s32 size;

    fn_803CDEDC(arg1, arg2);
    hdr = fn_803CD284();
    fn_803CE048(arg1, arg2, hdr);
    switch (arg1) {
    case 0:
        size = hdr->unk4 * hdr->unk2 * 2;
        break;
    case 1:
    case 2:
        size = (hdr->unk4 * hdr->unk2) / 2;
        break;
    case 3:
        size = hdr->unk4 * hdr->unk2;
        break;
    }
    memcpy(arg3, (u8 *)hdr + hdr->unk1C, size);
    fn_801F28F0(arg0, arg3, hdr->unk2, hdr->unk4, hdr->unk0, hdr->unk6, hdr->unk7, 0);
    fn_801F2B44(arg0, 1, 1, 0, 0, 0, lbl_805A49F4, lbl_805A49F4, lbl_805A49F4);
    fn_803CD298(hdr);
}
