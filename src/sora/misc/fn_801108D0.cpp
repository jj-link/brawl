#include <types.h>
#pragma force_active on

extern "C" {
void fn_80110A40(void* p);
void fn_80112D64(void* a, void* b);
void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);
void free__13gfHeapManagerFPv(void*);
extern void* lbl_805A0360;
extern char g_grCollisionList[];
}

struct Obj {
    char pad[0x10];
    void* m10;
    void* m14;
    void* m18;
    char pad2[0x11];
    u8 m2D;
};

extern "C" Obj* fn_801108D0(Obj* p, s32 flags) {
    if (p != nullptr) {
        p->m2D |= 8;
        fn_80110A40(p);
        fn_80112D64(lbl_805A0360, p);
        Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(g_grCollisionList, (char*)p + 0x30);
        free__13gfHeapManagerFPv(p->m10);
        p->m10 = nullptr;
        free__13gfHeapManagerFPv(p->m14);
        p->m14 = nullptr;
        free__13gfHeapManagerFPv(p->m18);
        p->m18 = nullptr;
        if (flags > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
