#include <types.h>
#pragma force_active on

struct Obj {
    Obj* next;      // 0x00
    u8 pad04[0x10];
    Obj* unk14;     // 0x14
    u8 pad18[0x14];
    Obj* unk2C;     // 0x2C
};

extern "C" void fn_800110CC(void* ctx, Obj* node);
extern "C" Obj* fn_800121A8(Obj* node);

extern "C" void fn_80012094(void* arg0, void* arg1, Obj* arg2) {
    Obj* node;
    Obj* it;

    for (it = arg2->unk2C; it != NULL; it = it->next) {
        fn_800110CC(arg1, it);
    }
    node = arg2->unk14;
    if (node != NULL) {
        for (it = node->unk2C; it != NULL; it = it->next) {
            fn_800110CC(arg1, it);
        }
        node = node->unk14;
        if (node != NULL) {
            for (it = fn_800121A8(node); it != NULL; it = it->next) {
                fn_800110CC(arg1, it);
            }
            node = node->unk14;
            if (node != NULL) {
                for (it = fn_800121A8(node); it != NULL; it = it->next) {
                    fn_800110CC(arg1, it);
                }
                node = node->unk14;
                if (node != NULL) {
                    fn_80012094(arg0, arg1, node);
                }
            }
        }
    }
}
