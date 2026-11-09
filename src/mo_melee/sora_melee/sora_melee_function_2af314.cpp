#include <types.h>
#pragma force_active on
struct Node { u8 inUse:1; u8 flagRest:7; u8 pad[7]; s16 prev; s16 next; };
class LinkList {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual s32 capacity(); virtual u32 state();
    s32 freeIndex:9; s32 spare:23; s32 count:9; s32 spare2:23; Node nodes[1];
    s32 getFreeIndex() const { return freeIndex; }
};
extern "C" s32 fn_27_2AF314(LinkList* self, s32 index) {
    if (self->state() == 1) return -1;
    if (index < 0) {
        s32 oldFree = self->getFreeIndex();
        s32 next = self->nodes[self->freeIndex].next;
        self->freeIndex = next;
        if (self->freeIndex > 0) self->nodes[self->freeIndex].prev = -1;
        self->count++;
        return oldFree;
    }
    if (index >= self->capacity()) return -1;
    Node& node = self->nodes[index];
    if ((u32)(node.inUse != 0) == 1) return -1;
    s32 next = node.next;
    s32 prev = node.prev;
    if (prev < 0 && next < 0) self->freeIndex = -1;
    else if (prev < 0) {
        self->nodes[next].prev = -1;
        self->freeIndex = node.next;
    } else if (next < 0) {
        self->nodes[prev].next = -1;
    } else {
        self->nodes[prev].next = next;
        self->nodes[next].prev = prev;
    }
    self->count++;
    return index;
}