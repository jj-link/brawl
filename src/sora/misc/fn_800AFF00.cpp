#include <types.h>
#pragma force_active on

struct FnLink {
    FnLink* next;
    FnLink* prev;
    s32 a;
    s32 b;
    u8 c;
};

struct FnFoo {
    char unk0[0x58];
    FnLink links[16];
    FnLink* head;
    s32 x;
    s32 y;
};

static inline FnLink* node(FnFoo* p, s32 i) {
    return (FnLink*)((char*)p + (u32)i * 0x14 + 0x58);
}

static inline void initLink(FnFoo* base, FnLink* l, s32 i) {
    l->a = 0;
    l->b = -1;
    l->c = 0;
    if (i < 15)
        l->next = node(base, i + 1);
    else
        l->next = 0;
    if (i > 0)
        l->prev = node(base, i - 1);
    else
        l->prev = 0;
}

extern "C" void fn_800AFF00(FnFoo* p) {
    for (s32 i = 0; i < 16; i++) {
        initLink(p, &p->links[i], i);
    }
    p->head = &p->links[0];
    p->x = 0;
    p->y = 0;
}
