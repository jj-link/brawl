#include <types.h>
#pragma force_active on

struct utList {
    void* getNode(u32 index);
};

struct Modules;
struct DataInfo {
    u8 pad[0x8];
    Modules* modules;
};
struct Accessor {
    u8 pad[0x44];
    DataInfo* data;
};
struct Target {
    u8 pad[0x30];
    u32 bits;
};
struct Node {
    Node* next;
    u8 pad[0x8];
    Target* target;
};
struct Owner {
    u8 pad[0x14];
    utList list;
};

extern "C" {
Accessor* fn_27_6F30C(void*);

void* fn_27_6BA10(Owner* self, s32 id) {
    Node* node;
    for (node = (Node*)self->list.getNode(0); node != 0; node = node->next) {
        if (id == (s32)((node->target->bits >> 1) & 0x7F)) {
            return fn_27_6F30C(node)->data->modules;
        }
    }
    return 0;
}
}
