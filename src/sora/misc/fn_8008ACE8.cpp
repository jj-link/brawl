#include <types.h>
#pragma force_active on

extern "C" void fn_8008B00C(void* p, int arg);
extern "C" void __dl__FPv(void* p);

struct Node {
    void* m0;
    void* m4;
};

extern "C" Node* fn_8008ACE8(Node* p, s32 flags) {
    if (p != nullptr) {
        fn_8008B00C(p->m0, 1);
        p->m0 = nullptr;
        fn_8008B00C(p->m4, 1);
        p->m4 = nullptr;
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
