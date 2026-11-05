#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on

struct Object {
    u8 pad[0x14];
    utList incoming;
    utList outgoing;
};
struct Link {
    u8 pad[8];
    utListNode node;
    u32 source;
    Link* self1;
    Object* owner;
    utListNode node2;
    u32 target;
    Link* self2;
    Object* found;
    union {
        u32 flags;
        struct { u32 unused : 31; u32 active : 1; } bits;
    };
};
struct ListEntry : utListNode {
    u32 field8;
    Link* data;
};
struct Event {
    u32 type;
    u8 flag;
};
extern "C" void fn_27_6A9BC(Object*, u32);
extern "C" void fn_27_6AA44(Object*, Object*, Event*, u32);

extern "C" void fn_27_6F5F8(void*, Object* obj) {
    Event e2;
    Event e1;
    while (*(s32*)((u8*)obj + 0x28) != 0) {
        Link* link = ((ListEntry*)obj->outgoing.getNode(0))->data;
        Object* owner = link->owner;
        Object* found = link->found;
        fn_27_6A9BC(owner, (link->flags >> 1) & 0x7f);
        owner->outgoing.remove(&link->node2);
        found->incoming.remove(&link->node);
        link->source = 0;
        link->owner = 0;
        link->self1 = link;
        link->target = 0;
        link->found = 0;
        link->self2 = link;
        link->bits.active = 0;
        u32 flags = link->flags;
        link->flags = (u8)flags;
        e1.type = 0x3d;
        e1.flag = 0;
        fn_27_6AA44(owner, found, &e1, (flags >> 1) & 0x7f);
        flags = (link->flags >> 1) & 0x7f;
        e2.type = 0x3c;
        e2.flag = 0;
        fn_27_6AA44(found, owner, &e2, flags);
    }
}
