#pragma force_active on

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    int index;
    void *data;
    int unk10;
} Node;

typedef struct List {
    Node *head;
    int count;
} List;

extern void *fn_80390044(int size, int type);

int fn_803906BC(List *list, void *data) {
    Node *node;
    int count;
    int ret = -1;

    node = (Node *)fn_80390044(0x14, 4);
    if (node != 0) {
        if (list->head != 0) {
            node->next = list->head->next;
            node->prev = list->head;
            list->head->next->prev = node;
            list->head->next = node;
        } else {
            node->next = node;
            node->prev = node;
            list->head = node;
        }
        count = list->count;
        node->index = count;
        list->count = count + 1;
        node->data = data;
        node->unk10 = -1;
        ret = node->index;
        if (list->count < 0) {
            list->count = 0;
        }
    }
    return ret;
}
