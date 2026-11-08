#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on
struct Object { u8 pad[0x14]; utList incoming; utList outgoing; };
struct Link {
    u8 pad[8]; utListNode node; u32 source; Link* self1; Object* owner;
    utListNode node2; u32 target; Link* self2; Object* found;
    union { u32 flags; struct { u32 unused : 31; u32 active : 1; } bits; };
};
struct ListEntry : utListNode { u32 field8; Link* data; };
struct HeadEntry : utListNode { u32 field8; u32 fieldc; Object* data; };
struct Info { u8 pad[0x28]; u32 id; };
struct Event { u32 type; u8 flag; };
extern "C" Info* fn_27_6A5D4(void*);
extern "C" void fn_27_6A9BC(Object*, u32);
extern "C" void fn_27_6AA44(Object*, Object*, Event*, u32);
extern "C" void fn_27_6F6E8(void*, Object* obj) {
    ListEntry* node;
    u32 id;
    Object* owner;
    Object* found;
    Link* link;
    Event e1;
    Event e2;
    while (*(s32*)((u8*)obj + 0x1c) != 0) {
        HeadEntry* head = (HeadEntry*)obj->incoming.getNode(0);
        id = fn_27_6A5D4(obj)->id;
        node = (ListEntry*)head->data->outgoing.getNode(0);
        while (node) {
            link = node->data;
            if (link->target == id) {
                owner = link->owner;
                found = link->found;
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
            node = (ListEntry*)node->m_next;
        }
    }
}