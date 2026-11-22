#include <types.h>
#include <string.h>
#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXVert.h>
#pragma force_active on

typedef struct { u8 uOff, fOff, rOff, pad; int uRev, fRev, rRev; } RFLiCoordinateData;
typedef struct { float x, y, z; } Vec;
typedef struct {
    u32 part;
    u16 file, padding06;
    int transform, flipX;
    s16 *vtxPosBuf, *vtxNrmBuf, *vtxTxcBuf;
    void *dlBuf;
    u8 padding20[6];
    u16 dlBufSize, numVtxPos, numVtxNrm, numVtxTxc, dlSize;
    float posScale;
    Vec *posTrans, *noseTrans, *beardTrans, *hairTrans;
} RFLiShapeRes;

extern RFLiCoordinateData lbl_80492FC8;
extern f32 lbl_805A4A28;
extern int fn_803CE16C(u32, u16);
extern void *fn_803CD284(int);
extern void fn_803CE2D8(u32, u16, void *);
extern void fn_803CD298(void *);
extern void fn_801D76BC(void *, u32);
extern void fn_801F4D50(void *, u32);
extern u16 fn_801F4E00(void);

static inline void transform(s16 *to, const s16 *from)
{
    to[lbl_80492FC8.rOff] = lbl_80492FC8.rRev ? -from[0] : from[0];
    to[lbl_80492FC8.uOff] = lbl_80492FC8.uRev ? -from[1] : from[1];
    to[lbl_80492FC8.fOff] = lbl_80492FC8.fRev ? -from[2] : from[2];
}

void fn_803D18A8(RFLiShapeRes *shape)
{
    BOOL skipTxc;
    void *res;
    u8 *ptr8;
    s16 *ptr16;
    u32 fileSize;

    skipTxc = 0;
    if (*(u32 *)shape <= 5 && ((1 << *(u32 *)shape) & 0x2b))
        skipTxc = 1;
    fileSize = fn_803CE16C(shape->part, shape->file);
    res = fn_803CD284(fileSize);
    fn_803CE2D8(shape->part, shape->file, res);
    ptr8 = (u8 *)res + 4;
    if ((s32)shape->part == 2) {
        memcpy(shape->noseTrans, ptr8, 12);
        ptr8 += 12;
        memcpy(shape->beardTrans, ptr8, 12);
        ptr8 += 12;
        memcpy(shape->hairTrans, ptr8, 12);
        ptr8 += 12;
    }
    if (*(u16 *)ptr8 == 0) {
        shape->numVtxPos = 0;
        shape->numVtxNrm = 0;
        shape->numVtxTxc = 0;
        shape->dlSize = 0;
        fn_803CD298(res);
        return;
    }
    shape->numVtxPos = *(u16 *)ptr8;
    ptr8 += 2;
    {
        u32 byteSize;
        int i;
        ptr16 = (s16 *)ptr8;
        byteSize = shape->numVtxPos * 6;
        if (shape->transform) {
            s32 s, tx, ty, tz;
            s = lbl_805A4A28 * shape->posScale;
            tx = lbl_805A4A28 * shape->posTrans->x;
            ty = lbl_805A4A28 * shape->posTrans->y;
            tz = lbl_805A4A28 * shape->posTrans->z;
            for (i = 0; i < shape->numVtxPos; i++) {
                s16 temp[3];
                if (shape->flipX)
                    temp[0] = ((-ptr16[0] * s) >> 8) + tx;
                else
                    temp[0] = ((ptr16[0] * s) >> 8) + tx;
                temp[1] = ((ptr16[1] * s) >> 8) + ty;
                temp[2] = ((ptr16[2] * s) >> 8) + tz;
                transform(&shape->vtxPosBuf[i * 3], temp);
                ptr16 += 3;
            }
        } else if (shape->flipX) {
            for (i = 0; i < shape->numVtxPos; i++) {
                s16 temp[3];
                temp[0] = -ptr16[0];
                temp[1] = ptr16[1];
                temp[2] = ptr16[2];
                transform(&shape->vtxPosBuf[i * 3], temp);
                ptr16 += 3;
            }
        } else {
            for (i = 0; i < shape->numVtxPos; i++) {
                transform(&shape->vtxPosBuf[i * 3], ptr16);
                ptr16 += 3;
            }
        }
        ptr8 += byteSize;
    }
    shape->numVtxNrm = *(u16 *)ptr8;
    ptr8 += 2;
    {
        int i;
        u32 byteSize;
        ptr16 = (s16 *)ptr8;
        byteSize = shape->numVtxNrm * 6;
        if (shape->flipX) {
            for (i = 0; i < shape->numVtxNrm; i++) {
                s16 temp[3];
                temp[0] = -ptr16[0];
                temp[1] = ptr16[1];
                temp[2] = ptr16[2];
                transform(&shape->vtxNrmBuf[i * 3], temp);
                ptr16 += 3;
            }
        } else {
            for (i = 0; i < shape->numVtxNrm; i++) {
                transform(&shape->vtxNrmBuf[i * 3], ptr16);
                ptr16 += 3;
            }
        }
        ptr8 += byteSize;
    }
    {
        u32 byteSize;
        if (skipTxc) {
            shape->numVtxTxc = 0;
        } else {
            shape->numVtxTxc = *(u16 *)ptr8;
            ptr8 += 2;
            byteSize = shape->numVtxTxc * 4;
            memcpy(shape->vtxTxcBuf, ptr8, byteSize);
            ptr8 += byteSize;
        }
    }
    {
        int i;
        s32 primitiveNum;
        primitiveNum = *ptr8++;
        fn_801D76BC(shape->dlBuf, shape->dlBufSize);
        fn_801F4D50(shape->dlBuf, shape->dlBufSize);
        for (i = 0; i < primitiveNum; i++) {
            int j;
            u16 vtxNum;
            GXPrimitive prim;
            vtxNum = *ptr8++;
            prim = (GXPrimitive)*ptr8++;
            GXBegin(prim, GX_VTXFMT0, vtxNum);
            for (j = 0; j < vtxNum; j++) {
                GXPosition1x8(*ptr8++);
                GXNormal1x8(*ptr8++);
                if (!skipTxc)
                    GXTexCoord1x8(*ptr8++);
            }
        }
    }
    shape->dlSize = fn_801F4E00();
    fn_803CD298(res);
}
