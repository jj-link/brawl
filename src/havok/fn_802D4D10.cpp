#include <types.h>
#pragma force_active on

extern "C" {

extern char lbl_804873E8[];

struct S {
    void* p;
    char pad[8];
} __attribute__((aligned(16)));

void* fn_802D4D10(int a, void* b) {
    S s;
    if (&s.p != 0) {
        s.p = lbl_804873E8;
    }
    return s.p;
}

}
