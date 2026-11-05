#include <cstring>
#pragma force_active on

struct Node {
    Node* next;       // 0x0
    Node* prev;       // 0x4
    char name[0x80];  // 0x8 - 0x87
    int value;        // 0x88
};

struct List {
    char pad[0x28];
    Node sentinel;
};

extern "C" int fn_8018C00C(List* list, const char* name) {
    Node* node = list->sentinel.next;
    Node* end = &list->sentinel;
    while (node != end) {
        if (strcmp(name, node->name) == 0)
            return node->value;
        node = node->next;
    }
    return 0;
}