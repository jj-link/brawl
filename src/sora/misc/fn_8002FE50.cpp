#include <gf/gf_copyefb.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
unsigned char* fn_801A12A0();
int fn_801F270C(unsigned short, unsigned short, unsigned int, int, int);
void fn_801D76BC(void*, unsigned int);
void fn_801F28F0(void*, void*, unsigned short, unsigned short, unsigned int, unsigned int, unsigned int, unsigned char);
void fn_801F2B44(void*, int, int, int, int, int, float, float, float);
}
void gfCopyEFBMgr::createCopyEFB(int index, Heaps::HeapType heapType) {
    unsigned char* p = (unsigned char*)this + index * 0x34;
    if (*(void**)(p + 0x4) == 0) {
        unsigned char* src = fn_801A12A0();
        unsigned short w = *(unsigned short*)(src + 4);
        *(unsigned short*)(p + 0xC) = w;
        unsigned short h = *(unsigned short*)(src + 6);
        *(unsigned short*)(p + 0xE) = h;
        *(int*)p = 4;
        int type = fn_801F270C(w, h, 4, 0, 0);
        *(int*)(p + 0x8) = type;
        *(void**)(p + 0x4) = gfHeapManager::alloc(heapType, type);
        fn_801D76BC(*(void**)(p + 0x4), *(unsigned int*)(p + 0x8));
        fn_801F28F0(p + 0x10, *(void**)(p + 0x4), *(unsigned short*)(p + 0xC), *(unsigned short*)(p + 0xE), *(unsigned int*)p, 0, 0, 0);
        fn_801F2B44(p + 0x10, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f);
        p[0x30] = 0;
    }
}
extern "C" unsigned char isValid__12gfCopyEFBMgrFi(void* this_, int arg) {
    return *(unsigned char*)((unsigned char*)this_ + arg * 0x34 + 0x30);
}
extern "C" void fn_801F1564(unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" void fn_801F15C8(unsigned short, unsigned short, int, unsigned char);
extern "C" void fn_801F1E60(void*, unsigned char);
void gfCopyEFBMgr::getEFB(int index) {
    gfCopyEFB* p = &m_copyEFBs[index];
    if (p->m_texBuffer) {
        fn_801F1564(0, 0, *(unsigned short*)&p->_12[0], *(unsigned short*)&p->_12[2]);
        fn_801F15C8(*(unsigned short*)&p->_12[0], *(unsigned short*)&p->_12[2], *(int*)&p->_0[0], 0);
        fn_801F1E60(p->m_texBuffer, 0);
        p->m_isValid = true;
    }
}
GXTexObj* gfCopyEFBMgr::getCopyEFBTex(int index) {
    return &m_copyEFBs[index].m_gxTexObj;
}
#include <types.h>
#include <revolution/GX.h>
#include <revolution/GX/GXVert.h>
#include <revolution/MTX/mtx.h>
extern "C" {
void fn_801F3194();
u8* fn_801A12A0();
void fn_801A7550(void*, void*);
void fn_801A7558(void*);
void fn_801A7A5C(void*, float, float, float, float, float, float);
void fn_801A8048(void*);
void fn_801A80CC(void*);
void fn_801A8194(void*);
void fn_801A81B8(void*);
void fn_801F3AFC(int);
void fn_801F2FB0(void*, int);
void fn_801F3D60(int, GXColor*, int, int, int);
void fn_801F3C30(int,int,int,int,int);
void fn_801F3CB0(int,int,int,int,int,int);
void fn_801F3C70(int,int,int,int,int);
void fn_801F3D08(int,int,int,int,int,int);
void fn_801EC158(void*);
void fn_801F51DC(void*, int);
void fn_801EFB10();
void fn_801EF280(int,int);
void fn_801EFB44(int,int,int,int,int);
void fn_801F52E4(int);
}
void gfCopyEFBMgr::drawCopyEFB(int index, GXColor* color) {
    int offset = index * 0x34;
    if (*((u8*)this + offset + 0x30)) {
        fn_801F3194();
        u8* p = (u8*)this + offset;
        GXTexObj tex = *(GXTexObj*)(p + 0x10);
        u16 width = *(u16*)(p + 0xc);
        u16 height = *(u16*)(p + 0xe);
        u8* screen = fn_801A12A0();
        u8 projection[0x110];
        void* context;
        fn_801A7550(&context, projection);
        fn_801A7558(&context);
        fn_801A7A5C(&context, 0.0f, (f32)*(u16*)(screen + 0x10), 0.0f, (f32)*(u16*)(screen + 0xe), 0.0f, 1.0f);
        fn_801A8048(&context);
        fn_801A80CC(&context);
        fn_801A8194(&context);
        fn_801A81B8(&context);
        GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
        GXSetNumTexGens(1);
        GXSetNumChans(0);
        GXSetNumTevStages(1);
        GXSetNumIndStages(0);
        fn_801F3AFC(0);
        fn_801F2FB0(&tex, 0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 60, 0, 125);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXColor c;
        u8 r = color->r;
        u8 g = color->g;
        u8 b = color->b;
        u8 a = color->a;
        c.r = r;
        c.g = g;
        c.b = b;
        c.a = a;
        fn_801F3D60(1, &c, b, g, r);
        fn_801F3C30(0, 2, 15, 15, 8);
        fn_801F3CB0(0, 0, 0, 0, 1, 0);
        fn_801F3C70(0, 7, 7, 7, 1);
        fn_801F3D08(0, 0, 0, 0, 1, 0);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
        Mtx matrix;
        fn_801EC158(&matrix);
        fn_801F51DC(&matrix, 0);
        fn_801EFB10();
        fn_801EF280(9, 1);
        fn_801EF280(13, 1);
        fn_801EFB44(7, 9, 1, 4, 0);
        fn_801EFB44(7, 13, 1, 0, 0);
        fn_801F52E4(0);
        GXBegin(GX_QUADS, GX_VTXFMT7, 4);
        WGPIPE.f = 0.0f;
        WGPIPE.f = 0.0f;
        WGPIPE.f = 0.0f;
        WGPIPE.uc = 0;
        WGPIPE.uc = 0;
        WGPIPE.f = (f32)width;
        WGPIPE.f = 0.0f;
        WGPIPE.f = 0.0f;
        WGPIPE.uc = 1;
        WGPIPE.uc = 0;
        WGPIPE.f = (f32)width;
        WGPIPE.f = (f32)height;
        WGPIPE.f = 0.0f;
        WGPIPE.uc = 1;
        WGPIPE.uc = 1;
        WGPIPE.f = 0.0f;
        WGPIPE.f = (f32)height;
        WGPIPE.f = 0.0f;
        WGPIPE.uc = 0;
        WGPIPE.uc = 1;
    }
}
