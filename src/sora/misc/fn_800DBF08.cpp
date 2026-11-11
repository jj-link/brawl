#include <types.h>
#include <gf/gf_heap_manager.h>
#include <gm/gm_global.h>
#include <nw4r/g3d/g3d_resfile.h>

#pragma force_active on

extern "C" {
void* fn_801B3440(void*, int, int);
void* fn_801AB6CC(void*, int, int);
void* fn_800DD528(void*);
void fn_800DD6E4(void*, void*, void*, int, int);
void fn_800DDAEC(void*, int);
void fn_800DFAB4(void*, int);
void* fn_800DFCB4(void*, int);
void fn_800E023C(void*, unsigned char, int, void*, void*);
void* fn_800EFBC0(void*);
void fn_800EFD70(void*, void*, void*, int, void*, int);
void* fn_800FE850(void*);
void fn_800FEA90(void*, void*);
void* fn_801048EC(void*);
void fn_80104AA4(void*, void*, int, int, int, int);
void fn_80108D1C(void*);
void* fn_8010890C(void*);
void fn_80108AE0(void*, void*);
void* fn_800FBB18(void*);
void fn_800FBC38(void*, void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);

extern void* g_gfSceneRoot;
extern const int lbl_80408580[];

void fn_800DBF08(char* self, const unsigned char* arg2) {
    void* spC = 0;
    void* sp8;
    char* p;
    int i;

    void* allocator = gfHeapManager::getMEMAllocator(Heaps::InfoInstance);
    *(void**)(self + 0x18) = fn_801B3440(allocator, 0, 2);
    *(void**)(self + 8) = fn_801AB6CC(allocator, 0, 0x20);

    if (!(*(unsigned char*)(self + 0xa8))) {
        *(void**)(self + 0xc) = fn_801AB6CC(allocator, 0, 6);
    }

    if ((unsigned)((arg2[8] >> 2) & 0x3f) == 8) {
        *(void**)(self + 0x10) = fn_801AB6CC(allocator, 0, 1);
    }

    *(void**)(self + 0x14) = fn_801AB6CC(allocator, 0, 6);

    void* obj = operator new(0x1e4, Heaps::InfoInstance);
    if (obj) {
        obj = fn_800DD528(obj);
    }

    *(void**)(self + 0x44) = obj;
    fn_800DD6E4(obj, self + 0x1c, self + 0x20,
                 *(int*)(self + 0x48), lbl_80408580[*(int*)(self + 4)]);

    if (*(int*)(self + 4) == 7 ||
        (unsigned)((arg2[8] >> 2) & 0x3f) == 8) {
        void* x = *(void**)(self + 0x44);
        int a = 2;
        if (*(int*)(self + 4) == 7) {
            a = 1;
        }
        fn_800DDAEC(x, a);
    }

    int count = 0;
    if (arg2[0x99] != 3 && arg2[0x99] != 4) count = 1;
    if (arg2[0xf5] != 3 && arg2[0xf5] != 4) count++;
    if (arg2[0x151] != 3 && arg2[0x151] != 4) count++;
    if (arg2[0x1ad] != 3 && arg2[0x1ad] != 4) count++;
    if (arg2[0x209] != 3 && arg2[0x209] != 4) count++;
    if (arg2[0x265] != 3 && arg2[0x265] != 4) count++;
    if (arg2[0x2c1] != 3 && arg2[0x2c1] != 4) count++;

    fn_800DFAB4(self + 0x1c, count);

    int bits = (arg2[9] >> 2) & 7;
    *(int*)(self + 0xb4) = bits >= 4 ? bits : 4;

    p = self;
    for (i = 0; i < *(int*)(self + 0xb4); i++) {
        void* obj2 = operator new(0x5d8, Heaps::InfoInstance);
        if (obj2) {
            obj2 = fn_800DFCB4(obj2, i);
        }
        unsigned char flags = arg2[9];
        *(void**)(p + 0x4c) = obj2;
        unsigned char value = arg2[0x13];
        fn_800E023C(obj2, (flags >> 5) & 7, value,
                    self + 0x1c, self + 0x24);
        p += 4;
    }

    if (*(int*)(self + 0x30)) {
        void* obj3 = operator new(0x78, Heaps::InfoInstance);
        if (obj3) {
            obj3 = fn_800EFBC0(obj3);
        }
        *(void**)(self + 0x70) = obj3;
        fn_800EFD70(obj3, self + 0x1c, self + 0x30,
                    *(int*)(self + 0x90), self + 0x3c,
                    *(int*)(self + 0xbc));
    }

    if (*(int*)(self + 0x34)) {
        void* obj4 = operator new(0x128, Heaps::InfoInstance);
        if (obj4) {
            obj4 = fn_800FE850(obj4);
        }
        *(void**)(self + 0x74) = obj4;
        fn_800FEA90(obj4, self + 0x34);
    }

    if (*(int*)(self + 0x38)) {
        void* obj5 = operator new(0x304, Heaps::InfoInstance);
        if (obj5) {
            obj5 = fn_801048EC(obj5);
        }
        *(void**)(self + 0x78) = obj5;
        fn_80104AA4(obj5, self + 0x38, *(int*)(self + 0x7c),
                    *(int*)(self + 0x80), *(int*)(self + 0x84),
                    *(int*)(self + 0x88));
    }

    if (*(int*)(self + 0x40)) {
        fn_80108D1C(self + 0x40);
        void* obj6 = fn_8010890C(*(void**)(self + 0x98));
        *(void**)(self + 0x94) = obj6;
        fn_80108AE0(obj6, self + 0x40);
    }

    if (*(unsigned char*)(self + 0xa8)) {
        void* obj7 = operator new(0xd0, Heaps::InfoInstance);
        if (obj7) {
            obj7 = fn_800FBB18(obj7);
        }
        *(void**)(self + 0x8c) = obj7;
        fn_800FBC38(obj7, self + 0x1c, *(int*)(self + 0x90));
    }

    unsigned char* rec =
        (unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap();
    if ((rec[0x28] >> 7) & 1) {
        spC = ((nw4r::g3d::ResFile*)(self + 0x2c))
                  ->GetResAnmScn(0).ptr();
    } else {
        spC = ((nw4r::g3d::ResFile*)(self + 0x28))
                  ->GetResAnmScn(0).ptr();
    }

    sp8 = spC;
    fn_801971D0(&spC, &sp8);
    fn_8000D6DC(g_gfSceneRoot, &spC);
}
}
