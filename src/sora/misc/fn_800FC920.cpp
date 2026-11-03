#include <types.h>
#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_800FD1F8(void*);
void fn_800FD2D0(void*, void*, int);
void fn_800FD510(void*);
void* fn_800FD650(void*, int, int);
void fn_800FD728(void*, void*, int);
void* fn_800FBB18(void*);
void fn_800FBC38(void*, void*, int);
void* fn_800DA15C(int, void*, void*, void*, int, int, int);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;
extern void* lbl_805A030C;
extern int lbl_8059E4D8;

void fn_800FC920(char* self) {
    void* spC = 0;
    void* sp8;
    void* obj = __nw__FUlQ25Heaps8HeapType(0x14, 0x28);
    if (obj != 0) {
        obj = fn_800FD1F8(obj);
    }
    *(void**)(self + 0x18) = obj;
    fn_800FD2D0(obj, self + 8, *(int*)(self + 0x48));
    fn_800FD510(self + 8);
    char* p = self;
    for (int i = 0; i < 7; i++) {
        obj = __nw__FUlQ25Heaps8HeapType(0x20, 0x28);
        if (obj != 0) {
            obj = fn_800FD650(obj, i, 0);
        }
        *(void**)(p + 0x1c) = obj;
        fn_800FD728(obj, self + 8, 1);
        p += 4;
    }
    obj = __nw__FUlQ25Heaps8HeapType(0xd0, 0x28);
    if (obj != 0) {
        obj = fn_800FBB18(obj);
    }
    *(void**)(self + 0x38) = obj;
    fn_800FBC38(obj, self + 8, *(int*)(self + 0x4c));
    *(void**)(self + 0x40) = fn_800DA15C(3, self + 0xc, lbl_805A030C, &lbl_8059E4D8, 0x40, 0x28, 0x2a);
    spC = GetResAnmScn__Q34nw4r3g3d7ResFileFi(self + 0x10, 0);
    sp8 = spC;
    fn_801971D0(&spC, &sp8);
    fn_8000D6DC(g_gfSceneRoot, &spC);
}
}