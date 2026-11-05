#include <types.h>
#pragma force_active on

extern char lbl_8049DEDC[];
extern const float lbl_805A1E84;
extern "C" void fn_8009F278(void*, float);

extern "C" void fn_800A27A8() {
    void* node = *(void**)(lbl_8049DEDC + 4);
    void* end = lbl_8049DEDC + 4;
    while (node != end) {
        if ((*(unsigned int*)((char*)node + 8) >> 16) & 1) {
            fn_8009F278(node, lbl_805A1E84);
        }
        node = *(void**)node;
    }
}
