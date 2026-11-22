#include <types.h>
#pragma force_active on

struct Obj {
    Obj* next;      // 0x00
    u8 pad04[0x10];
    Obj* unk14;     // 0x14
    Obj* children[4]; // 0x18
    void* unk28;    // 0x28
    Obj* unk2C;     // 0x2C
};

struct Node {
    Node* next;
    u8 pad04[0x18];
    u8 flag : 1;
};

extern "C" void fn_80010F78(Node* a, Node* b);
extern "C" void fn_800110CC(Node* ctx, Obj* node);
extern "C" void fn_80012094(void* arg0, Node* arg1, Obj* arg2);

extern "C" void fn_80011F0C(void* arg0, Obj* arg1) {
    u32 i;
    Node* n;
    Obj* node;
    Obj* it;
    Obj* cursor;
    cursor = arg1;
    for (i = 0; i < 4; i++) {
        if (cursor->children[0] != NULL) {
            fn_80011F0C(arg0, cursor->children[0]);
        }
        cursor = (Obj*)((char*)cursor + 4);
    }
    if (arg1->unk28 != NULL) {
        for (n = (Node*)arg1->unk2C; n != (Node*)&arg1->unk2C; n = n->next) {
            if (n->flag) {
                it = (Obj*)n->next;
                node = (Obj*)&arg1->unk2C;
                for (; it != node; it = it->next) {
                    if (((Node*)it)->flag) {
                        fn_80010F78(n, (Node*)it);
                    }
                }
                it = arg1->unk14;
                if (it != NULL) {
                    for (node = it->unk2C; node != NULL; node = node->next) {
                        fn_800110CC(n, node);
                    }
                    it = it->unk14;
                    if (it != NULL) {
                        for (node = it->unk2C; node != NULL; node = node->next) {
                            fn_800110CC(n, node);
                        }
                        it = it->unk14;
                        if (it != NULL) {
                            for (node = it->unk2C; node != NULL; node = node->next) {
                                fn_800110CC(n, node);
                            }
                            it = it->unk14;
                            if (it != NULL) {
                                for (node = it->unk2C; node != NULL; node = node->next) {
                                    fn_800110CC(n, node);
                                }
                                if (it->unk14 != NULL) {
                                    fn_80012094(arg0, n, it->unk14);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
