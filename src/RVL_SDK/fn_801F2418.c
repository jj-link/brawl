#include <types.h>
#include <revolution/GX/GXTypes.h>
struct _GXLightObj;
static void GXInitLightAttn(struct _GXLightObj*, f32, f32, f32, f32, f32, f32);
static void GXInitLightAttnA(struct _GXLightObj*, f32, f32, f32);
static void GXInitLightAttnK(struct _GXLightObj*, f32, f32, f32);
static void GXInitLightSpot(struct _GXLightObj*, f32, GXSpotFn);
static void GXInitLightDistAttn(struct _GXLightObj*, f32, f32, GXDistAttnFn);
static void GXInitLightPos(struct _GXLightObj*, f32, f32, f32);
static void GXGetLightPos(const struct _GXLightObj*, f32*, f32*, f32*);
static void GXInitLightDir(struct _GXLightObj*, f32, f32, f32);
static void GXGetLightDir(const struct _GXLightObj*, f32*, f32*, f32*);
static void GXInitSpecularDir(struct _GXLightObj*, f32, f32, f32);
static void GXInitLightColor(struct _GXLightObj*, GXColor);
static void GXLoadLightObjIndx(u16, GXLightID);
static void GXSetChanAmbColor(GXChannelID, GXColor);
static void GXSetChanMatColor(GXChannelID, GXColor);
static void GXSetNumChans(u8);
static void GXSetChanCtrl(GXChannelID, GXBool, GXColorSrc, GXColorSrc, GXLightID, GXDiffuseFn, GXAttnFn);
#define GXLoadLightObjImm fn_801F2418
#include "../src/revolution/GX/GXLight.c"
#pragma force_active on
