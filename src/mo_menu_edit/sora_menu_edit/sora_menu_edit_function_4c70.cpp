#include <nw4r/g3d/g3d_resfile.h>
#include <gf/gf_keep_fb.h>
#pragma force_active on
extern void* g_gfSceneRoot;
extern gfKeepFrameBuffer* lbl_805A0008;
extern "C" void fn_801971D0(void*, void*);
extern "C" void fn_8000D07C(void*, int);
extern "C" void fn_8000D2E0(void*, void*, int);
extern "C" void fn_8000D6DC(void*, void*);
extern "C" void fn_5_B43C(void*);

extern "C" void fn_5_4C70(void* self) {
    *(int*)((char*)self + 0x40) = 13;
    *(int*)((char*)self + 0x44) = 0;
    nw4r::g3d::ResAnmScn anm;
    void* root = g_gfSceneRoot;
    anm = ((nw4r::g3d::ResFile*)((char*)self + 0x7d69c))->GetResAnmScn(0);
    nw4r::g3d::ResAnmScn temp = anm;
    fn_801971D0(&anm, &temp);
    fn_8000D07C(root, 1);
    fn_8000D2E0(root, &anm, 0x2a);
    fn_8000D6DC(root, &anm);
    fn_5_B43C(self);
    lbl_805A0008->endKeepScreen();
}