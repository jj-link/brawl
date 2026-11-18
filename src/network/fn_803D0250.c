#include <types.h>
#include <RVLFaceLib/RFL_MiddleDatabase.h>
#include <RVLFaceLib/RFLi_Model.h>
#pragma force_active on
extern int fn_803D4808(int);
extern int fn_803D47A0(int);
extern void fn_803D1188(RFLiCharModelRes*, const RFLiCharInfo*);
extern void fn_803D20DC(RFLiCharInfo*, u8**, int);
extern void fn_801F28F0(void*, void*, u16, u16, u32, u32, u32, u8);
extern void fn_801F2B44(void*, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 lbl_805A49F4, lbl_805A49F8, lbl_805A49FC, lbl_805A4A00;
void fn_803D0250(RFLCharModel* model, RFLiCharInfo* info, void* work, RFLResolution res, u32 exprFlags) {
    RFLiCharModel* model_;
    u32 maskSize;
    u8* maskImages[RFLExp_Max];
    u32 maskRes;
    GXTexObj* exprTexObj;
    u8* image;
    BOOL setExpr;
    f32 maxLod;
    u8 mipmap;
    int i;
    model_ = (RFLiCharModel*)model;
    model_->resolution = res;
    maskSize = fn_803D4808(res);
    maskRes = fn_803D47A0(res);
    model_->res = work;
    exprTexObj = (GXTexObj*)(((u32)((u8*)work + sizeof(RFLiCharModelRes)) + 31) & ~31);
    for (i = 0; i < RFLExp_Max; i++) {
        if (exprFlags & (1 << i)) {
            model_->maskTexObj[i] = exprTexObj;
            exprTexObj++;
        } else {
            model_->maskTexObj[i] = 0;
        }
    }
    image = (u8*)(((u32)exprTexObj + 31) & ~31);
    for (i = 0; i < RFLExp_Max; i++) {
        if (exprFlags & (1 << i)) {
            maskImages[i] = image;
            image += maskSize;
        } else {
            maskImages[i] = 0;
        }
    }
    fn_803D1188(model_->res, info);
    maxLod = lbl_805A49F4;
    setExpr = 0;
    mipmap = 0;
    switch (res) {
    case RFLResolution_64M:
        maxLod = lbl_805A49F8;
        mipmap = 1;
        break;
    case RFLResolution_128M:
        maxLod = lbl_805A49FC;
        mipmap = 1;
        break;
    case RFLResolution_256M:
        maxLod = lbl_805A4A00;
        mipmap = 1;
        break;
    }
    for (i = 0; i < RFLExp_Max; i++) {
        if (model_->maskTexObj[i] != 0) {
            fn_801F28F0(model_->maskTexObj[i], maskImages[i], maskRes, maskRes, 5, 0, 0, mipmap);
            if (mipmap) {
                fn_801F2B44(model_->maskTexObj[i], 5, 1, 0, 0, 0, lbl_805A49F4, maxLod, lbl_805A49F4);
            } else {
                fn_801F2B44(model_->maskTexObj[i], 1, 1, 0, 0, 0, lbl_805A49F4, lbl_805A49F4, lbl_805A49F4);
            }
            if (!setExpr) {
                model_->expression = (RFLExpression)i;
                setExpr = 1;
            }
        }
    }
    fn_803D20DC(info, maskImages, res);
}