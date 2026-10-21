#include <types.h>
#pragma force_active on

extern "C" void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
extern "C" void fn_801971D0(void*, void*);
extern "C" void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;

extern "C" void fn_80107E74(u8* self) {
    void* anm = 0;
    void* tmp;
    anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(self + 0x30, 0);
    tmp = anm;
    fn_801971D0(&anm, &tmp);
    fn_8000D6DC(g_gfSceneRoot, &anm);
}
