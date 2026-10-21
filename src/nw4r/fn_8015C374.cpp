#pragma force_active on
namespace nw4r {
namespace ut {
class LinkListNode {
public:
    LinkListNode* next;
    LinkListNode* prev;
};
namespace detail {
class LinkListImpl {
public:
    int count;
    LinkListNode* Erase(LinkListNode* node);
};
}
}
}

namespace nw4r { namespace ut { namespace detail {
LinkListNode* LinkListImpl::Erase(LinkListNode* node) {
    LinkListNode* next = node->next;
    LinkListNode* prev = node->prev;
    next->prev = prev;
    prev->next = next;
    count--;
    node->next = 0;
    node->prev = 0;
    return next;
}
}}}
