#pragma opt_loop_invariants off
#include <types.h>
#include <ut/ut_list.h>
#include <string.h>
#pragma force_active on
struct Str { unsigned int flags; unsigned int unused; char* ptr; };
extern "C" void fn_800146F0(Str*, void*);
extern "C" void fn_80014480(Str*, void*);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80045240(void* self, utList* list, void* key) {
    utListNode* node = list->getNode(0);
    while (node) {
        Str a, b;
        fn_800146F0(&a, *(char**)((char*)node + 0x14) + 0x28);
        fn_800146F0(&b, key);
        unsigned int flag = b.flags >> 31;
        const char* bp;
        const char* ap;
        if (flag == 0) bp = (char*)&b + 1; else bp = b.ptr;
        if ((a.flags >> 31) == 0) ap = (char*)&a + 1; else ap = a.ptr;
        bool equal = strcmp(ap, bp) == 0;
        if (flag) __dl__FPv(b.ptr);
        if (a.flags >> 31) __dl__FPv(a.ptr);
        if (equal) {
            Str c, d;
            fn_80014480(&c, *(char**)((char*)node + 0x14) + 0x28);
            fn_80014480(&d, key);
            flag = d.flags >> 31;
            if (flag == 0) bp = (char*)&d + 1; else bp = d.ptr;
            if ((c.flags >> 31) == 0) ap = (char*)&c + 1; else ap = c.ptr;
            equal = strcmp(ap, bp) == 0;
            if (flag) __dl__FPv(d.ptr);
            if (c.flags >> 31) __dl__FPv(c.ptr);
            if (equal) return node;
        }
        node = node->m_next;
    }
    return 0;
}