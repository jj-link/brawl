#include <types.h>
#pragma force_active on

struct Link {
    Link* next;
};

class Item {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual s32 f14(s32 a, s32 b);
    Link link;
};

struct Owner {
    char pad0[0x14];
    Link head;
    char pad1[0x28 - 0x14 - sizeof(Link)];
    void* unk28;
};

extern "C" s32 fn_8018C114(void* p, s32 key);

extern "C" s32 fn_80182BEC(Owner* self, s32 a, s32 b) {
    if (self->unk28 != 0) {
        if (fn_8018C114((char*)self->unk28 + 0x44, a) != 0) {
            return (s32)self->unk28;
        }
    }
    if (b != 0) {
        Link* node = self->head.next;
        Link* head = &self->head;
        while (node != head) {
            Item* item = (Item*)((char*)node - 4);
            s32 r = item->f14(a, 1);
            if (r != 0) {
                return r;
            }
            node = node->next;
        }
    }
    return 0;
}
