#include <types.h>
#pragma force_active on

typedef struct SearchNode SearchNode;
struct SearchNode {
    SearchNode* next;
    u16 kind;
    u16 flags;
    union {
        SearchNode* children;
        u16 value;
    } data;
};

typedef struct SearchEntry SearchEntry;
struct SearchEntry {
    SearchNode* nodes;
    SearchEntry* next;
};

typedef struct SearchRoot {
    u8 pad[8];
    SearchEntry* first;
} SearchRoot;

SearchEntry* fn_80256D1C(SearchRoot* root, u32 value, SearchEntry* previous)
{
    SearchEntry* entry;
    SearchNode* node;

    if (previous == 0) {
        entry = root->first;
    } else {
        entry = previous->next;
    }

    for (; entry != 0; entry = entry->next) {
        for (node = entry->nodes; node != 0; node = node->next) {
            if (node->kind == 1 && (node->flags >> 12) == 6) {
                for (node = node->data.children; node != 0; node = node->next) {
                    if ((node->flags >> 12) == 3 &&
                        (node->flags & 0xFFF) == 2 &&
                        node->data.value == value) {
                        return entry;
                    }
                }
                break;
            } else if (node->kind == 3 &&
                       (node->flags >> 12) == 3 &&
                       (node->flags & 0xFFF) == 2 &&
                       node->data.value == value) {
                return entry;
            }
        }
    }
    return 0;
}
