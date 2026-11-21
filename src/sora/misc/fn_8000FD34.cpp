#include <types.h>
#include <gf/gf_copyefb.h>
#include <mt/mt_matrix.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern "C" {
u8* fn_80023AC8(); void fn_801A7550(void*,void*); void fn_801A7558(void*);
void fn_801A7A5C(void*,float,float,float,float,float,float); void fn_801A7ABC(void*,float,float,float,float);
void fn_801A8048(void*); void fn_801A80CC(void*); void fn_801A8194(void*); void fn_801A81B8(void*);
void fn_801F2FB0(GXTexObj*,int); void fn_801F3AFC(int); void fn_801F256C(int,GXColor*); void fn_801F2494(int,GXColor*);
void fn_801F55EC(int); void fn_801F51DC(void*,unsigned int); void fn_801EFB10(); void fn_801EF280(int,int);
void fn_801EFB44(int,int,int,int,int); void fn_801F52E4(int);
extern float lbl_805A1324,lbl_805A1328,lbl_805A132C,lbl_805A1330,lbl_805A1364;
}
extern "C" void fn_8000FD34(int arg) {
u8 buffer[0x110]; Matrix matrix(true); u32 context;
u8* mgr=fn_80023AC8();
int width, height;
width=*(u16*)(mgr+0x34);
height=*(u16*)(mgr+0x36);
fn_801A7550(&context,buffer); fn_801A7558(&context);
fn_801A7A5C(&context,lbl_805A1324,(float)height,lbl_805A1324,(float)width,lbl_805A1364,lbl_805A1328);
fn_801A7ABC(&context,lbl_805A1324,lbl_805A1324,(float)width,(float)height);
fn_801A8048(&context);fn_801A80CC(&context);fn_801A8194(&context);fn_801A81B8(&context);
GXTexObj* tex=gfCopyEFBMgr::getInstance()->getCopyEFBTex(0);
GXSetAlphaCompare((GXCompare)7,0,(GXAlphaOp)0,(GXCompare)7,0); fn_801F2FB0(tex,0);
GXSetTexCoordGen2((GXTexCoordID)0,(GXTexGenType)1,(GXTexGenSrc)4,60,0,125);
GXSetNumTexGens(1); GXSetTevOp((GXTevStageID)0,(GXTevMode)3);
GXSetTevOrder((GXTevStageID)0,(GXTexCoordID)0,(GXTexMapID)0,(GXChannelID)4);
GXSetNumTevStages(1);GXSetNumIndStages(0);fn_801F3AFC(0);
GXSetChanCtrl((GXChannelID)4,0,(GXColorSrc)0,(GXColorSrc)0,(GXLightID)0,(GXDiffuseFn)0,(GXAttnFn)2);
GXSetChanCtrl((GXChannelID)5,0,(GXColorSrc)0,(GXColorSrc)0,(GXLightID)0,(GXDiffuseFn)0,(GXAttnFn)2);
GXColor white;
u32 source1 = 0xFFFFFFFF;
white.r = ((GXColor*)&source1)->r; white.g = ((GXColor*)&source1)->g; white.b = ((GXColor*)&source1)->b; white.a = ((GXColor*)&source1)->a;
fn_801F256C(4, &white);
GXColor white2;
u32 source2 = 0xFFFFFFFF;
white2.r = ((GXColor*)&source2)->r; white2.g = ((GXColor*)&source2)->g; white2.b = ((GXColor*)&source2)->b; white2.a = ((GXColor*)&source2)->a;
fn_801F2494(4, &white2);
GXSetNumChans(0);GXSetZCompLoc(0);GXSetZMode(0,(GXCompare)7,1);fn_801F55EC(1);
GXSetBlendMode((GXBlendMode)0,(GXBlendFactor)0,(GXBlendFactor)0,(GXLogicOp)0);
matrix.setIdentity();fn_801F51DC(&matrix,0);fn_801EFB10();fn_801EF280(9,1);fn_801EF280(13,1);
fn_801EFB44(0,9,1,4,0);fn_801EFB44(0,13,1,4,0);
float h=(float)height;float w=(float)width;fn_801F52E4(0);GXBegin((GXPrimitive)0x80,(GXVtxFmt)0,4);
if(arg==1){
WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1330;WGPIPE.f=lbl_805A1324;
WGPIPE.f=w;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A1324;
WGPIPE.f=w;WGPIPE.f=h;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A1330;
WGPIPE.f=lbl_805A1324;WGPIPE.f=h;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1330;WGPIPE.f=lbl_805A1330;
return;
}
WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A1330;
WGPIPE.f=w;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1330;WGPIPE.f=lbl_805A1330;
WGPIPE.f=w;WGPIPE.f=h;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1330;WGPIPE.f=lbl_805A1324;
WGPIPE.f=lbl_805A1324;WGPIPE.f=h;WGPIPE.f=lbl_805A132C;WGPIPE.f=lbl_805A1324;WGPIPE.f=lbl_805A1324;
}