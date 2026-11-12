#include <types.h>
#include <revolution/GX/GXTypes.h>
#include <revolution/MTX.h>
static void __GXSetProjection(void);
static void GXSetProjection(const Mtx44, GXProjectionType);
static void GXGetProjectionv(f32*);
static void GXLoadPosMtxImm(const Mtx,u32);
static void GXLoadPosMtxIndx(u16,u32);
static void GXLoadNrmMtxImm(const Mtx,u32);
static void GXLoadNrmMtxIndx3x3(u16,u32);
static void GXSetCurrentMtx(u32);
static void GXLoadTexMtxImm(const Mtx,u32,GXMtxType);
static void __GXSetViewport(void);
static void GXSetViewportJitter(f32,f32,f32,f32,f32,f32,u32);
static void GXSetViewport(f32,f32,f32,f32,f32,f32);
static void GXGetViewportv(f32*);
static void GXSetZScaleOffset(f32,f32);
static void GXSetScissor(u32,u32,u32,u32);
static void GXGetScissor(u32*,u32*,u32*,u32*);
static void GXSetScissorBoxOffset(u32,u32);
static void GXSetClipMode(GXClipMode);
static void __GXSetMatrixIndex(GXAttr);
#define GXSetProjectionv fn_801F5150
#include "../src/revolution/GX/GXTransform.c"
#pragma force_active on
