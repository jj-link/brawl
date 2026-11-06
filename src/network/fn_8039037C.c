#pragma force_active on
typedef struct Node {
    struct Node *prev;
    struct Node *next;
    signed char *key;
    void *value;
    int field10;
    int field14;
} Node;

extern void *fn_80390044(int, int);
extern void fn_803900E4(void *, int);
extern int fn_80392CD4(signed char *, signed char *);
extern int fn_803F861C(const char *, ...);
extern char lbl_804915B0[];

int fn_8039037C(Node **head, void *context, signed char *key, void *value)
{
    int found;
    Node *node;
    node = *head;
    found = 0;
    if (node != 0) {
        if (fn_80392CD4(key, node->key) != 0) {
            node = node->next;
            while (node != *head) {
                if (fn_80392CD4(key, node->key) == 0) {
                    found = 1;
                    break;
                }
                node = node->next;
            }
        } else {
            found = 1;
        }
    }
    if (found != 0) {
        node->value = value;
    } else {
        node = fn_80390044(0x18, 4);
        if (node == 0) {
            fn_803F861C(lbl_804915B0);
            fn_803900E4(context, 1);
            return 0;
        }
        node->key = key;
        node->value = value;
        node->field10 = 0;
        node->field14 = 0;
        if (*head != 0) {
            node->prev = (*head)->prev;
            node->next = *head;
            (*head)->prev->next = node;
            (*head)->prev = node;
        } else {
            node->next = node;
            node->prev = node;
            *head = node;
        }
    }
    return 1;
}
