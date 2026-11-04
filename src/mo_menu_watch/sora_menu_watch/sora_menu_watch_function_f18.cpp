#include <types.h>
#pragma force_active on

struct WatchNode {
    s32 index;
    u8 pad0[0x14];
    WatchNode* next;
    WatchNode* prev;
};

struct WatchEntry {
    u8 pad0[0x10];
    void* obj;
};

struct WatchSub {
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11(void* a, void* b) = 0;
    virtual void vf12() = 0;
    virtual void vf13(void* a) = 0;
    u8 pad0[0xE0];
    void* fieldE4;
};

struct WatchOwner {
    u8 pad0[0x4C];
    WatchEntry* entries[85];
    WatchSub* sub;
    u8 pad1[0xD3C - 0x1A4];
    WatchNode* listA;
    WatchNode* listB;
    s32 count;
};

extern "C" {
s32 fn_15_11F4(WatchOwner* self, WatchNode* node);
void fn_15_10B0(WatchOwner* self, WatchNode* node);
s32 randi__Fl(s32);
}

extern "C" void fn_15_F18(WatchOwner* self) {
    WatchNode* sel = 0;
    WatchNode* node = self->listB;
    while (node != 0) {
        WatchNode* next = node->next;
        if (fn_15_11F4(self, node) == 0) {
            WatchNode* n = node->next;
            WatchNode* prev = node->prev;
            if (prev != 0) {
                prev->next = n;
            } else {
                self->listB = n;
            }
            if (n != 0) {
                n->prev = prev;
            }
            if (self->listA != 0) {
                self->listA->prev = node;
            }
            node->prev = 0;
            node->next = self->listA;
            self->listA = node;
            self->sub->vf13(self->entries[node->index]->obj);
        }
        node = next;
    }
    if (self->count > 0) {
        if (randi__Fl(1) == 0) {
            sel = self->listA;
            if (sel != 0) {
                WatchNode* n = sel->next;
                WatchNode* prev = sel->prev;
                if (prev != 0) {
                    prev->next = n;
                } else {
                    self->listA = n;
                }
                if (n != 0) {
                    n->prev = prev;
                }
                if (self->listB != 0) {
                    self->listB->prev = sel;
                }
                sel->prev = 0;
                sel->next = self->listB;
                self->listB = sel;
                fn_15_10B0(self, sel);
                self->sub->vf11(self->sub->fieldE4, self->entries[sel->index]->obj);
                self->count = self->count - 1;
            }
        }
    }
}
