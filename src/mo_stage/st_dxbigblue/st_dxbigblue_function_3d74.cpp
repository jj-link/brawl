#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

namespace nw4r {
namespace ut {
class LinkListNode {
public:
    LinkListNode* prev;
    LinkListNode* next;
};

namespace detail {
class LinkListImpl {
public:
    class Iterator {
    public:
        Iterator(void* p) : mNode(p) {}
        void* mNode;
    };

    void Insert(Iterator pos, LinkListNode* node);

    void* head;
    void* tail;
};
} // namespace detail
} // namespace ut
} // namespace nw4r

struct Obj : nw4r::ut::LinkListNode {
    u8 flag;
};

extern "C" {
void fn_81_3D74(void* unused, u8 flag, nw4r::ut::detail::LinkListImpl* list) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0xc, 0x11);
    if (obj) {
        obj->prev = 0;
        obj->next = 0;
    }
    if (obj) {
        obj->flag = flag;
        list->Insert(nw4r::ut::detail::LinkListImpl::Iterator(list->tail), obj);
    }
}
}
