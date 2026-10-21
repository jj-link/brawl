#include <types.h>
#pragma force_active on

struct FooNode {
    void *m0;
    u8 pad4[4];
    void *m8;
    void *mC;
};

extern "C" {
void fn_801CA7E8(void **p) {
    FooNode *n;
    if (*p != 0) {
        n = (FooNode *)*p;
        if (n->m8 == (void *)p) {
            n->m8 = 0;
        }
        n = (FooNode *)*p;
        if (n->mC == (void *)p) {
            n->mC = 0;
        }
    }
    if (*p != 0) {
        *p = 0;
    }
}
}
