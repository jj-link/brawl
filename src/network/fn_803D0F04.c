#include <revolution/GX.h>
#pragma force_active on
typedef struct { unsigned char r,g,b,a; } Color;
typedef struct { char pad[0x60]; int index; char pad64[4]; unsigned char *data; void *textures[1]; } Context;
typedef struct { int unk0,coord,map,unkC,mode,color,unk18,matrix; unsigned char cull; } Arg;
extern Color lbl_8041ADB8[];
void fn_801F3C70(int,int,int,int,int);
void fn_801F3F20(int,int,int);
void fn_801F51DC(const void*,unsigned int);
void fn_801F5258(const void*,unsigned int);
void fn_801F52E4(int);
void fn_801F3C30(int,int,int,int,int);
void fn_801F2FB0(void*,int);
void fn_801F0208(int,const void*,unsigned int);
void fn_801F4EAC(void*,unsigned short);
void fn_801F3E24(int,Color*);
void fn_803D0F04(const Context *ctx, const Arg *arg) {
    unsigned char *p = ctx->data;
    Color color;
    GXSetTevOrder(0,arg->coord,arg->map,255);
    fn_801F3C70(0,7,7,7,4);
    fn_801F3F20(0,arg->mode,arg->mode);
    fn_801F51DC(ctx,arg->matrix);
    fn_801F5258((char*)ctx+0x30,arg->matrix);
    fn_801F52E4(arg->matrix);
    GXSetTexCoordGen2(arg->coord,1,4,60,0,125);
    fn_801F3C30(0,15,15,15,8);
    { int cull = 2; if (arg->cull) cull = 1; GXSetCullMode(cull); }
    fn_801F2FB0(ctx->textures[ctx->index],arg->map);
    fn_801F0208(9,p+0x7a9a,6);
    fn_801F0208(10,p+0x7caa,6);
    fn_801F0208(13,p+0x7eae,4);
    fn_801F4EAC(p+0xac0,*(unsigned short*)(p+0x8242));
    if (*(unsigned short*)(p+0x8240)) {
        fn_801F3C30(0,15,15,15,15);
        fn_801F2FB0(p+0x81dc,arg->map);
        fn_801F0208(9,p+0x7a4e,6);
        fn_801F0208(10,p+0x7a72,6);
        fn_801F0208(13,p+0x7a7e,4);
        fn_801F4EAC(p+0xa60,*(unsigned short*)(p+0x8240));
    }
    if (*(unsigned short*)(p+0x8244)) {
        int id = arg->color;
        color = lbl_8041ADB8[p[0x8249]];
        fn_801F3E24(id,&color);
        GXSetCullMode(0);
        fn_801F3C30(0,15,14,8,15);
        fn_801F2FB0(p+0x81fc,arg->map);
        fn_801F0208(9,p+0x816e,6);
        fn_801F0208(10,p+0x8186,6);
        fn_801F0208(13,p+0x818c,4);
        fn_801F4EAC(p+0xe40,*(unsigned short*)(p+0x8244));
    }
}