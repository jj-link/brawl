#pragma force_active on
#pragma deadstore off
#include <nw4r/ut/ut_LinkList.h>

struct List : nw4r::ut::detail::LinkListImpl {
    using nw4r::ut::detail::LinkListImpl::Insert;
    using nw4r::ut::detail::LinkListImpl::Erase;
    using nw4r::ut::detail::LinkListImpl::GetEndIter;
    using nw4r::ut::detail::LinkListImpl::GetBeginIter;
};

struct Item {
    int p;
    Item* next;
    int a;
    void (*fn)(void*, int, int);
    int e;
};

struct Cleanup {
    int a, b, c;
    Item* head;
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
void fn_8015C238(void*, int);
void fn_80204B90(void*, int);
void* fn_80204A70(void*, int, int);
void fn_80204D7C(void*, int);
void fn_80204CA8(void*, int);
}

extern "C" void fn_801BFCF8(Self* self, int n) {
    Item* it;
    if (n == 0) {
        if (!self->list.IsEmpty()) {
            nw4r::ut::LinkListNode* end = self->list.GetEndIter().operator->();
            while (!self->list.IsEmpty()) {
                Cleanup* c = (Cleanup*)end->GetPrev();
                if (c) {
                    it = (Item*)((char*)c + 12);
                    while (it != c->head) {
                        it = it->next;
                        if (it && it->fn) it->fn((char*)it + 32, it->a, it->e);
                    }
                    if ((char*)c + 8) fn_8015C238((char*)c + 8, 0);
                }
                self->list.Erase((nw4r::ut::LinkListNode*)c);
            }
        }
        fn_80204B90(self->h, 3);
        void* p = fn_80204A70(self->h, 20, 4);
        if (p) {
            Node* node = (Node*)p;
            if (node) {
                unsigned* w = (unsigned*)node;
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
        }
    } else {
        if (n < (int)self->list.GetSize()) {
            nw4r::ut::LinkListNode* end = self->list.GetEndIter().operator->();
            while (n < (int)self->list.GetSize()) {
                Cleanup* c = (Cleanup*)end->GetPrev();
                if (c) {
                    it = (Item*)((char*)c + 12);
                    while (it != c->head) {
                        it = it->next;
                        if (it && it->fn) it->fn((char*)it + 32, it->a, it->e);
                    }
                    if ((char*)c + 8) fn_8015C238((char*)c + 8, 0);
                }
                self->list.Erase((nw4r::ut::LinkListNode*)c);
            }
        }
        fn_80204D7C(self->h, n);
        fn_80204CA8(self->h, (int)self->list.GetSize());
        void* p = fn_80204A70(self->h, 20, 4);
        if (p) {
            Node* node = (Node*)p;
            if (node) {
                unsigned* w = (unsigned*)node;
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
        }
    }
}
