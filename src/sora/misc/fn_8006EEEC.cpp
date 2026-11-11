#include <types.h>
#include <nw4r/ut/ut_Color.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual int slot10();
};
namespace ms {
class CharWriter {
public:
 u32 w[8]; s32 state; float f24,f28,f2c,f30,f34; s32 w38,w3c;
 u8 pad40[2], opacity, b43; float f44; Object_vptr_0* font;
};
}
extern "C" {
extern u32 lbl_80497EC8[4];
extern signed char lbl_805A01C0;
extern u8 lbl_805A01C4, lbl_805A01C5, lbl_805A01C6, lbl_805A01C7;
extern u8 lbl_80497EB8[];
extern const float lbl_805A1A70;
void* __dt__Q34nw4r2ut5ColorFv(void*, int);
void __register_global_object(void*, void*, void*);
void fn_8007077C(GXColor*, GXColor*);
void fn_801F3F5C(int,int,int,int,int);
void fn_801F4010(int,int,int);
void fn_801F3AFC(int);
void fn_801F3F20(int,int,int);
void fn_801F3C30(int,int,int,int,int);
void fn_801F3C70(int,int,int,int,int);
void fn_801F3CB0(int,int,int,int,int,int);
void fn_801F3D08(int,int,int,int,int,int);
void fn_801EFB44(int,int,int,int,int);
void fn_801EFB10();
void fn_801EF280(int,int);
}
#define INIT_FOG() \
 if (lbl_805A01C0 == 0) { \
 *(u32*)&lbl_805A01C4 = 0; \
 __register_global_object(&lbl_805A01C4,(void*)__dt__Q34nw4r2ut5ColorFv,lbl_80497EB8); \
 lbl_805A01C0 = 1; } \
 { GXColor color; u8* p = &lbl_805A01C4; \
 color.r = *p++; color.g = lbl_805A01C5; color.b = lbl_805A01C6; color.a = lbl_805A01C7; \
 typedef void (*FogFunction)(GXFogType, const GXColor*, float, float, float, float); \
 ((FogFunction)GXSetFog)(GX_FOG_NONE, &color, lbl_805A1A70, lbl_805A1A70, lbl_805A1A70, lbl_805A1A70); }
#define SETUP() \
 fn_801F3F5C(0,0,1,2,3); fn_801F4010(0,17,0); GXSetNumChans(1); \
 GXSetChanCtrl(GX_COLOR0A0,0,GX_SRC_REG,GX_SRC_VTX,GX_LIGHT_NULL,GX_DF_NONE,GX_AF_NONE); \
 GXSetChanCtrl(GX_COLOR1A1,0,GX_SRC_REG,GX_SRC_REG,GX_LIGHT_NULL,GX_DF_NONE,GX_AF_NONE); \
 GXSetNumTexGens(1); GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,60,0,125); \
 GXSetNumIndStages(0); GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET); \
 GXSetNumTevStages(1); fn_801F3AFC(0); fn_801F3F20(0,0,0); \
 GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0)
#define VERTICES() \
 fn_801EFB44(0,9,1,4,0); fn_801EFB44(0,11,1,5,0); fn_801EFB44(0,13,1,2,15); \
 fn_801EFB10(); fn_801EF280(9,1); fn_801EF280(11,1); fn_801EF280(13,1)
extern "C" void SetupGXWithColorMapping__Q22ms10CharWriterFQ34nw4r2ut5ColorQ34nw4r2ut5Color(ms::CharWriter* self, GXColor* a, GXColor* b) {
 lbl_80497EC8[0]=255; lbl_80497EC8[1]=0;
 if (self->w[0]!=0 || self->w[1]!=0xFFFFFFFF) {
 GXColor first; GXColor second; u8* s=(u8*)self;
 first.r=s[0]; first.g=s[1]; first.b=s[2]; first.a=s[3];
 second.r=s[4]; second.g=s[5]; second.b=s[6]; second.a=s[7];
 fn_8007077C(&first,&second); return;
 }
 if (self->font) {
 switch(self->font->slot10()) {
 case 0: case 1:
 INIT_FOG(); SETUP();
 fn_801F3C30(0,15,15,15,10); fn_801F3C70(0,7,4,5,7);
 fn_801F3CB0(0,0,0,0,1,0); fn_801F3D08(0,0,0,0,1,0); VERTICES(); break;
 case 2: case 3:
 INIT_FOG(); SETUP(); GXSetTevOp(GX_TEVSTAGE0,GX_MODULATE); VERTICES(); break;
 case 4: case 5: case 6:
 INIT_FOG(); SETUP(); GXSetTevOp(GX_TEVSTAGE0,GX_MODULATE); VERTICES(); break;
 default:
 INIT_FOG(); SETUP(); GXSetTevOp(GX_TEVSTAGE0,GX_MODULATE); VERTICES(); break;
 }
 } else { INIT_FOG(); SETUP(); GXSetTevOp(GX_TEVSTAGE0,GX_MODULATE); VERTICES(); }
}