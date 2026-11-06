#pragma force_active on
typedef struct Node {
    struct Node *next;   /* 0x00 */
    struct Node *prev;   /* 0x04 */
    int unk08;           /* 0x08 */
    int key;             /* 0x0C */
    unsigned char pad10[6];
    unsigned char flag;  /* 0x16 */
} Node;

typedef struct List {
    Node *head;   /* 0x00 */
    Node *tail;   /* 0x04 */
    int sum;      /* 0x08 */
} List;

void fn_80230104(List *list, Node *node) {
    Node *cur;
    int key;

    if (node->key < 0) {
        return;
    }
    if (node->key >= list->sum) {
        if (list->head == 0) {
            list->head = node;
        } else {
            if (list->tail != 0) {
                list->tail->next = node;
            }
            node->prev = list->tail;
        }
        node->next = 0;
        list->tail = node;
        key = node->key;
        node->key = key - list->sum;
        list->sum = key;
    } else {
        cur = list->head;
        while (node->key > cur->key) {
            if (cur->key > 0) {
                node->key -= cur->key;
            }
            cur = cur->next;
        }
        if (cur == list->head) {
            node->next = list->head;
            list->head->prev = node;
            list->head = node;
        } else {
            cur->prev->next = node;
            node->prev = cur->prev;
            cur->prev = node;
            node->next = cur;
        }
        cur->key = cur->key - node->key;
    }
    node->flag = 1;
}
