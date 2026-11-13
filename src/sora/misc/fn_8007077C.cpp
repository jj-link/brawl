#include <types.h>
#include <nw4r/ut/ut_Color.h>
#pragma force_active on
extern "C" {
extern signed char lbl_805A01C0;
extern u8 lbl_805A01C4, lbl_805A01C5, lbl_805A01C6, lbl_805A01C7;
extern u8 lbl_80497EB8[];
extern const float lbl_805A1A70;
void* __dt__Q34nw4r2ut5ColorFv(void*, int);
void __register_global_object(void*, void*, void*);
void fn_801F3F5C(int,int,int,int,int);
void fn_801F4010(int,int,int);
void fn_801F3AFC(int);
void fn_801F3F20(int,int,int);
void fn_801F3C30(int,int,int,int,int);
void fn_801F3C70(int,int,int,int,int);
void fn_801F3CB0(int,int,int,int,int,int);
void fn_801F3D08(int,int,int,int,int,int);
void fn_801F3D60(int, GXColor*);
void fn_801EFB44(int,int,int,int,int);
void fn_801EFB10();
void fn_801EF280(int,int);

void fn_8007077C(GXColor* a, GXColor* b) {
 GXColor ca; GXColor cb; GXColor color;
 if (lbl_805A01C0 == 0) {
 *(u32*)&lbl_805A01C4 = 0;
 __register_global_object(&lbl_805A01C4,(void*)__dt__Q34nw4r2ut5ColorFv,lbl_80497EB8);
 lbl_805A01C0 = 1; }
 { u8* p = &lbl_805A01C4;
 color.r = *p++; color.g = lbl_805A01C5; color.b = lbl_805A01C6; color.a = lbl_805A01C7;
 typedef void (*FogFunction)(GXFogType, const GXColor*, float, float, float, float);
 ((FogFunction)GXSetFog)(GX_FOG_NONE, &color, lbl_805A1A70, lbl_805A1A70, lbl_805A1A70, lbl_805A1A70); }
 fn_801F3F5C(0,0,1,2,3); fn_801F4010(0,17,0); GXSetNumChans(1);
 GXSetChanCtrl(GX_COLOR0A0,0,GX_SRC_REG,GX_SRC_VTX,GX_LIGHT_NULL,GX_DF_NONE,GX_AF_NONE);
 GXSetChanCtrl(GX_COLOR1A1,0,GX_SRC_REG,GX_SRC_REG,GX_LIGHT_NULL,GX_DF_NONE,GX_AF_NONE);
 GXSetNumTexGens(1); GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,60,0,125);
 GXSetNumIndStages(0); GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
 GXSetNumTevStages(2); fn_801F3AFC(0); fn_801F3AFC(1); fn_801F3F20(0,0,0); fn_801F3F20(1,0,0);
 GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
 { u8 t3,t2,t1,t0; u8* p = (u8*)a; t0=*p++; t1=*p++; t2=*p++; t3=*p; ca.r=t0; ca.g=t1; ca.b=t2; ca.a=t3; fn_801F3D60(1,&ca); }
 { u8 t3,t2,t1,t0; u8* p = (u8*)b; t0=*p++; t1=*p++; t2=*p++; t3=*p; cb.r=t0; cb.g=t1; cb.b=t2; cb.a=t3; fn_801F3D60(2,&cb); }
 fn_801F3C30(0,2,4,8,15); fn_801F3C70(0,1,2,4,7);
 fn_801F3CB0(0,0,0,0,1,0); fn_801F3D08(0,0,0,0,1,0);
 GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
 fn_801F3C30(1,15,0,10,15); fn_801F3C70(1,7,0,5,7);
 fn_801F3CB0(1,0,0,0,1,0); fn_801F3D08(1,0,0,0,1,0);
 fn_801EFB44(0,9,1,4,0); fn_801EFB44(0,11,1,5,0); fn_801EFB44(0,13,1,2,15);
 fn_801EFB10(); fn_801EF280(9,1); fn_801EF280(11,1); fn_801EF280(13,1);
}
}
