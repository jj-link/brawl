#pragma force_active on
#pragma peephole off

struct Node {
    Node* first;
    Node* next;
};

struct Owner {
    char padding[0x40];
    Node* list;
};

extern "C" void fn_41_2B358(Owner* owner, Node* node) {
    Node** link = &owner->list->next;
    Node** nextLink;
    goto visit;
    for (;;) {
        link = nextLink;
    visit:
        Node* current = *link;
        if (!current) break;
        nextLink = &current->next;
    }
    *link = node;
}
