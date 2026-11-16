#include <types.h>
#include <RVLFaceLib/RFL_MiddleDatabase.h>
#include <RVLFaceLib/RFLi_Model.h>
#include <revolution/OS/OSCache.h>
#include <stddef.h>
#pragma force_active on

extern void fn_803D18A8(RFLiShapeRes*);
extern void fn_803D1E90(GXTexObj*, RFLiPartsShpTex, u16, void*);

extern const f32 lbl_805A49F8, lbl_805A49FC, lbl_805A4A04, lbl_805A4A08;
extern const f32 lbl_805A4A0C, lbl_805A4A10, lbl_805A4A14;

#define NUM_VTX_POS(size) ((size) / VTX_POS_SIZE)
#define NUM_VTX_NRM(size) ((size) / VTX_NRM_SIZE)
#define NUM_VTX_TXC(size) ((size) / VTX_TXC_SIZE)
#define ALIGN32(x) (((x) + 31) & ~31)

void fn_803D1188(RFLiCharModelRes* res, const RFLiCharInfo* info) {
    Vec noseTrans;
    Vec beardTrans;
    Vec hairTrans;

    {
        RFLiShapeRes arg;
        arg.part = RFLiPartsShp_Faceline;
        arg.file = info->faceline.type;
        arg.vtxPosBuf = res->faceVtxPos;
        arg.vtxNrmBuf = res->faceVtxNrm;
        arg.vtxTxcBuf = res->faceVtxTxc;
        arg.dlBuf = res->faceDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->faceVtxPos));
        arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->faceVtxNrm));
        arg.vtxTxcBufSize = NUM_VTX_TXC(sizeof(res->faceVtxTxc));
        arg.dlBufSize = sizeof(res->faceDl);
        arg.noseTrans = &noseTrans;
        arg.beardTrans = &beardTrans;
        arg.hairTrans = &hairTrans;
        arg.flipX = FALSE;
        arg.transform = FALSE;
        fn_803D18A8(&arg);
        res->faceDlSize = arg.dlSize;
    }
    {
        RFLiShapeRes arg;
        arg.part = RFLiPartsShp_Cap;
        arg.file = info->hair.type;
        arg.vtxPosBuf = res->capVtxPos;
        arg.vtxNrmBuf = res->capVtxNrm;
        arg.vtxTxcBuf = res->capVtxTxc;
        arg.dlBuf = res->capDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->capVtxPos));
        arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->capVtxNrm));
        arg.vtxTxcBufSize = NUM_VTX_TXC(sizeof(res->capVtxTxc));
        arg.dlBufSize = sizeof(res->capDl);
        arg.flipX = info->hair.flip;
        arg.transform = TRUE;
        arg.posScale = lbl_805A49F8;
        arg.posTrans = &hairTrans;
        fn_803D18A8(&arg);
        res->capDlSize = arg.dlSize;
        res->hairVtxPos = (s16*)((u8*)res->capVtxPos +
                                 (arg.numVtxPos * 4 - arg.numVtxPos) * 2);
        res->hairVtxNrm = (s16*)((u8*)res->capVtxNrm +
                                 (arg.numVtxNrm * 4 - arg.numVtxNrm) * 2);
        res->hairDl = res->noseDl + ALIGN32(arg.dlSize) +
                      offsetof(RFLiCharModelRes, capDl);
    }
    {
        RFLiShapeRes arg;
        arg.part = RFLiPartsShp_Hair;
        arg.file = info->hair.type;
        arg.vtxPosBuf = res->hairVtxPos;
        arg.vtxNrmBuf = res->hairVtxNrm;
        arg.dlBuf = res->hairDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->capVtxPos)) -
            (((u32)res->hairVtxPos - (u32)res->capVtxPos) / VTX_COORD_SIZE) /
                VTX_COORDS_IN_POS;
        arg.vtxNrmBufSize = NUM_VTX_POS(sizeof(res->capVtxNrm)) -
            (((u32)res->hairVtxNrm - (u32)res->capVtxNrm) / VTX_COORD_SIZE) /
                VTX_COORDS_IN_NRM;
        arg.dlBufSize = sizeof(res->capDl) -
                        ((u32)res->hairDl - (u32)res->capDl);
        arg.flipX = info->hair.flip;
        arg.transform = TRUE;
        arg.posScale = lbl_805A49F8;
        arg.posTrans = &hairTrans;
        fn_803D18A8(&arg);
        res->hairDlSize = arg.dlSize;
        res->foreheadVtxPos = (s16*)((u8*)res->hairVtxPos +
                                     (arg.numVtxPos * 4 - arg.numVtxPos) * 2);
        res->foreheadVtxNrm = res->hairVtxNrm + arg.numVtxNrm * 3;
        res->foreheadDl = res->hairDl + ALIGN32(arg.dlSize);
        res->flipHair = info->hair.flip;
    }
    {
        RFLiShapeRes arg;
        arg.part = RFLiPartsShp_Forehead;
        arg.file = info->hair.type;
        arg.vtxPosBuf = res->foreheadVtxPos;
        arg.vtxNrmBuf = res->foreheadVtxNrm;
        arg.dlBuf = res->foreheadDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->capVtxPos)) -
            (((u32)res->foreheadVtxPos - (u32)res->capVtxPos) / VTX_COORD_SIZE) /
                VTX_COORDS_IN_POS;
        arg.vtxNrmBufSize = NUM_VTX_POS(sizeof(res->capVtxNrm)) -
            (((u32)res->foreheadVtxNrm - (u32)res->capVtxNrm) / VTX_COORD_SIZE) /
                VTX_COORDS_IN_NRM;
        arg.dlBufSize = sizeof(res->capDl) -
                        ((u32)res->foreheadDl - (u32)res->capDl);
        arg.flipX = info->hair.flip;
        arg.transform = TRUE;
        arg.posScale = lbl_805A49F8;
        arg.posTrans = &hairTrans;
        fn_803D18A8(&arg);
        res->foreheadDlSize = arg.dlSize;
    }
    {
        RFLiShapeRes arg;
        arg.part = RFLiPartsShp_Beard;
        arg.file = info->beard.type;
        arg.vtxPosBuf = res->beardVtxPos;
        arg.vtxNrmBuf = res->beardVtxNrm;
        arg.dlBuf = res->beardDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->beardVtxPos));
        arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->beardVtxNrm));
        arg.dlBufSize = sizeof(res->beardDl);
        arg.flipX = FALSE;
        arg.transform = TRUE;
        arg.posScale = lbl_805A49F8;
        arg.posTrans = &beardTrans;
        fn_803D18A8(&arg);
        res->beardDlSize = arg.dlSize;
    }
    {
        f32 scale;
        Vec trans;
        {
            RFLiShapeRes arg;
            scale = lbl_805A4A04 + lbl_805A4A08 * info->nose.scale;
            trans.x = noseTrans.x;
            trans.y = +noseTrans.y + lbl_805A4A0C * (info->nose.y - 8);
            trans.z = noseTrans.z;
            arg.part = RFLiPartsShp_Nose;
            arg.file = info->nose.type;
            arg.vtxPosBuf = res->noseVtxPos;
            arg.vtxNrmBuf = res->noseVtxNrm;
            arg.dlBuf = res->noseDl;
            arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->noseVtxPos));
            arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->noseVtxNrm));
            arg.dlBufSize = sizeof(res->noseDl);
            arg.flipX = FALSE;
            arg.transform = TRUE;
            arg.posScale = scale;
            arg.posTrans = &trans;
            fn_803D18A8(&arg);
            res->noseDlSize = arg.dlSize;
        }
        {
            RFLiShapeRes arg;
            arg.part = RFLiPartsShp_Noseline;
            arg.file = info->nose.type;
            arg.vtxPosBuf = res->noselineVtxPos;
            arg.vtxNrmBuf = res->noselineVtxNrm;
            arg.vtxTxcBuf = res->noselineVtxTxc;
            arg.dlBuf = res->noselineDl;
            arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->noselineVtxPos));
            arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->noselineVtxNrm));
            arg.vtxTxcBufSize = NUM_VTX_TXC(sizeof(res->noselineVtxTxc));
            arg.dlBufSize = sizeof(res->noselineDl);
            arg.flipX = FALSE;
            arg.transform = TRUE;
            arg.posScale = scale;
            arg.posTrans = &trans;
            fn_803D18A8(&arg);
            res->noselineDlSize = arg.dlSize;
        }
    }
    {
        RFLiShapeRes arg;
        arg.part = RFLiPartsShp_Mask;
        arg.file = info->faceline.type;
        arg.vtxPosBuf = res->maskVtxPos;
        arg.vtxNrmBuf = res->maskVtxNrm;
        arg.vtxTxcBuf = res->maskVtxTxc;
        arg.dlBuf = res->maskDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->maskVtxPos));
        arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->maskVtxNrm));
        arg.vtxTxcBufSize = NUM_VTX_TXC(sizeof(res->maskVtxTxc));
        arg.dlBufSize = sizeof(res->maskDl);
        arg.flipX = FALSE;
        arg.transform = FALSE;
        fn_803D18A8(&arg);
        res->maskDlSize = arg.dlSize;
    }
    {
        RFLiShapeRes arg;
        f32 scale;
        Vec trans;
        scale = lbl_805A4A10 * info->glass.scale + lbl_805A4A04;
        trans.x = noseTrans.x;
        trans.y = lbl_805A4A14 + noseTrans.y + lbl_805A4A0C * (info->glass.y - 11);
        trans.z = lbl_805A49FC + noseTrans.z;
        arg.part = RFLiPartsShp_Glass;
        arg.file = 0;
        arg.vtxPosBuf = res->glassesVtxPos;
        arg.vtxNrmBuf = res->glassesVtxNrm;
        arg.vtxTxcBuf = res->glassesVtxTxc;
        arg.dlBuf = res->glassesDl;
        arg.vtxPosBufSize = NUM_VTX_POS(sizeof(res->glassesVtxPos));
        arg.vtxNrmBufSize = NUM_VTX_NRM(sizeof(res->glassesVtxNrm));
        arg.vtxTxcBufSize = NUM_VTX_TXC(sizeof(res->glassesVtxTxc));
        arg.dlBufSize = sizeof(res->glassesDl);
        arg.flipX = FALSE;
        arg.transform = TRUE;
        arg.posScale = scale;
        arg.posTrans = &trans;
        fn_803D18A8(&arg);
        res->glassesDlSize = arg.dlSize;
    }
    fn_803D1E90(&res->faceTexObj, RFLiPartsShpTex_Face,
                   info->faceline.texture, res->faceTex);
    if (res->capDlSize > 0) {
        fn_803D1E90(&res->capTexObj, RFLiPartsShpTex_Cap, info->hair.type,
                       res->capTex);
    }
    if (res->noselineDlSize > 0) {
        fn_803D1E90(&res->noseTexObj, RFLiPartsShpTex_Noseline,
                       info->nose.type, res->noseTex);
    }
    fn_803D1E90(&res->glassesTexObj, RFLiPartsShpTex_Glass, info->glass.type,
                   res->glassesTex);
    res->facelineColor = info->faceline.color;
    res->hairColor = info->hair.color;
    res->beardColor = info->beard.color;
    res->glassesColor = info->glass.color;
    res->favoriteColor = info->personal.color;
    DCFlushRange(res, sizeof(RFLiCharModelRes));
}
