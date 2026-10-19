#include <types.h>
#pragma force_active on

struct Node {
    u32 kind;
    u8 pad[0x14];
    Node* next;
    Node* prev;
};

struct Entry {
    u8 pad[0x10];
    void* mdl;
};

struct Owner {
    u8 pad0[0x138];
    Entry* entries[32];
    u8 pad1[0x58c - 0x138 - 32 * 4];
    Node* freeList;
    Node* activeList;
    s32 count;
};

extern "C" {
s32 fn_34_1454(Owner* self, Node* node);
void fn_34_1318(Owner* self, Node* node);
s32 randi__Fl(s32);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* root, s32 layer, void* mdl);
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void* root, void* mdl);
extern void* g_gfSceneRoot;
}

extern "C" void fn_34_11A0(Owner* self) {
    Node* sel;
    Node* node = self->activeList;
    while (node != 0) {
        Node* next = node->next;
        if (fn_34_1454(self, node) == 0) {
            Node* n = node->next;
            Node* prev = node->prev;
            if (prev != 0) {
                prev->next = n;
            } else {
                self->activeList = n;
            }
            if (n != 0) {
                n->prev = prev;
            }
            if (self->freeList != 0) {
                self->freeList->prev = node;
            }
            node->prev = 0;
            node->next = self->freeList;
            self->freeList = node;
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, self->entries[node->kind]->mdl);
        }
        node = next;
    }

    if (self->count > 0) {
        if (randi__Fl(1) == 0) {
            sel = self->freeList;
            if (sel != 0) {
                Node* n = sel->next;
                Node* prev = sel->prev;
                if (prev != 0) {
                    prev->next = n;
                } else {
                    self->freeList = n;
                }
                if (n != 0) {
                    n->prev = prev;
                }
                if (self->activeList != 0) {
                    self->activeList->prev = sel;
                }
                sel->prev = 0;
                sel->next = self->activeList;
                self->activeList = sel;
                fn_34_1318(self, sel);
                add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, self->entries[sel->kind]->mdl);
                self->count = self->count - 1;
            }
        }
    }
}
