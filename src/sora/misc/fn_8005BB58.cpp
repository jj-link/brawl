#pragma force_active on
typedef unsigned char u8;

namespace nw4r {
namespace ut {

struct LinkListNode {
    LinkListNode* next;
    LinkListNode* prev;
};

namespace detail {

struct LinkListImpl {
    struct Iterator {
        LinkListNode* node;

        Iterator(LinkListNode* p) : node(p) {}
    };

    unsigned int count;
    LinkListNode node;

    void Insert(Iterator it, LinkListNode* p);

    void PushBack(LinkListNode* p) {
        Insert(Iterator(&node), p);
    }
};

}
}
}

struct Node : nw4r::ut::LinkListNode {
    char pad[6];
    u8 index;
};

struct Manager {
    char pad[0x108];
    nw4r::ut::detail::LinkListImpl lists[256];
};

extern "C" void fn_8005BB58(Manager* self, Node* node) {
    self->lists[node->index].PushBack(node);
}
