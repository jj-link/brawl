#include <math.h>
#include <revolution/GX.h>
#pragma force_active on
extern GXVtxDescList lbl_804DEDA8[];
extern GXVtxAttrFmtList lbl_804DEE80[];
extern void fn_801EF8CC(GXAttr, GXAttrType *);
extern void fn_801EFA80(GXVtxDescList *);
extern void fn_801F0194(GXVtxFmt, GXVtxAttrFmtList *);
extern void fn_801EFB10(void);
extern void fn_801EF280(GXAttr, GXAttrType);
extern void fn_801EFB44(GXVtxFmt, GXAttr, GXCompCnt, GXCompType, u8);
extern void fn_801EF4E4(GXVtxDescList *);
extern void fn_801EFCE4(GXVtxFmt, GXVtxAttrFmtList *);

/* 2*pi plus the pool's 4-byte zero tail (8 bytes at 0x805A38C8). Defined after
   the function so it lands after the int->float conversion doubles in .sdata2. */
extern const f32 lbl_805A38C8[2];

void fn_801F4980(u32 stacks, u32 sectors) {
    GXAttrType tex0, tex0_copy;
    f32 radius = 1.0f;
    f32 stackStep, sectorStep;
    f32 stackAngle, stackAngleNext;
    f32 now_xy, next_xy;
    f32 now_z, next_z;
    f32 sectorAngle;
    f32 cosv, sinv;
    int i, j;

    /* Two discarded signed conversions: the first makes the signed int->float
       bias constant get pooled ahead of the unsigned one; the second keeps the
       compiler's alternating conversion scratch slots in their original phase. */
    (f32)(int)sectors;
    (f32)(int)stacks;

    stackStep = 3.1415927f / stacks;
    sectorStep = lbl_805A38C8[0] / sectors;

    fn_801EF8CC(GX_VA_TEX0, &tex0);
    fn_801EFA80(lbl_804DEDA8);
    fn_801F0194(GX_VTXFMT3, lbl_804DEE80);
    fn_801EFB10();
    fn_801EF280(GX_VA_POS, GX_DIRECT);
    fn_801EF280(GX_VA_NRM, GX_DIRECT);
    fn_801EFB44(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    fn_801EFB44(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    if (tex0 != GX_NONE) {
        fn_801EF280(GX_VA_TEX0, GX_DIRECT);
        fn_801EFB44(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    }
    for (i = 0; i < (int)stacks; i++) {
        stackAngle = i * stackStep;
        stackAngleNext = stackAngle + stackStep;
        now_xy = radius * sinf(stackAngle);
        next_xy = radius * sinf(stackAngleNext);
        now_z = radius * cosf(stackAngle);
        next_z = radius * cosf(stackAngleNext);
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT3, (sectors + 1) * 2);
        tex0_copy = tex0;
        for (j = 0; j <= (int)sectors; j++) {
            sectorAngle = j * sectorStep;
            cosv = cosf(sectorAngle);
            sinv = sinf(sectorAngle);
            GXPosition3f32(cosv * next_xy, sinv * next_xy, next_z);
            GXPosition3f32(cosv * next_xy / radius, sinv * next_xy / radius, next_z / radius);
            if (tex0_copy != GX_NONE)
                GXTexCoord2f32((f32)j / sectors, (f32)(i + 1) / stacks);
            GXPosition3f32(cosv * now_xy, sinv * now_xy, now_z);
            GXPosition3f32(cosv * now_xy / radius, sinv * now_xy / radius, now_z / radius);
            if (tex0_copy != GX_NONE)
                GXTexCoord2f32((f32)j / sectors, (f32)i / stacks);
        }
    }
    fn_801EF4E4(lbl_804DEDA8);
    fn_801EFCE4(GX_VTXFMT3, lbl_804DEE80);
}

const f32 lbl_805A38C8[2] = { 6.2831855f, 0.0f };
