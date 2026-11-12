#pragma force_active on
#include <nw4r/ut/ut_LinkList.h>

struct List : nw4r::ut::detail::LinkListImpl {
    using nw4r::ut::detail::LinkListImpl::Insert;
    using nw4r::ut::detail::LinkListImpl::GetEndIter;
};

struct Node {
    nw4r::ut::LinkListNode node;
    List list;
};

struct Head {
    unsigned prev;
    unsigned next;
};

struct Self {
    void* h;
    List list;
};

extern "C" {
int fn_80204CA8(void*, int);
void* fn_80204A70(void*, int, int);
void fn_80204D7C(void*, int);
}

extern "C" int fn_801BFC2C(Self* self) {
    int ok;
    if (fn_80204CA8(self->h, (int)self->list.GetSize()) == 0) {
        return -1;
    }
    void* p = fn_80204A70(self->h, 0x14, 4);
    if (!p) {
        ok = 0;
    } else {
        Node* node = (Node*)p;
        if (p) {
            unsigned* w = (unsigned*)p;
            Head* hd = (Head*)(w + 3);
            unsigned tail = (unsigned)hd;
            w[0] = 0;
            w[1] = 0;
            hd->prev = 0;
            hd->next = 0;
            w[2] = 0;
            hd->prev = tail;
            hd->next = tail;
        }
        self->list.Insert(self->list.GetEndIter(), &node->node);
        ok = 1;
    }
    if (ok == 0) {
        fn_80204D7C(self->h, 0);
        return -1;
    }
    return self->list.GetSize() - 1;
}