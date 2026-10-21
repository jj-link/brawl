#pragma force_active on
namespace nw4r {
namespace ut {
struct LinkListNode {
    LinkListNode* prev;
    LinkListNode* next;
};

namespace detail {
struct LinkListImpl {
    struct Iterator {
        LinkListNode* node;
    };

    int m_size;

    LinkListNode* Insert(Iterator it, LinkListNode* node);
};

LinkListNode* LinkListImpl::Insert(Iterator it, LinkListNode* node) {
    LinkListNode* pos = it.node;
    LinkListNode* next = pos->next;
    node->prev = pos;
    node->next = next;
    pos->next = node;
    next->prev = node;
    m_size = m_size + 1;
    return node;
}
} // namespace detail
} // namespace ut
} // namespace nw4r
