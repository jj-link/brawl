#pragma force_active on
#define NULL ((void *)0)

typedef struct Node {
    struct Node *next;
    struct Node *prev;
} Node;

Node *fn_803904B8(Node **arg0) {
    Node *temp_r5;
    Node *temp_r4;

    temp_r5 = *arg0;
    if (temp_r5 != NULL) {
        temp_r4 = temp_r5->next;
        if (temp_r5 != temp_r4) {
            temp_r4->prev = temp_r5->prev;
            temp_r5->prev->next = temp_r5->next;
            *arg0 = temp_r5->prev;
        } else {
            *arg0 = NULL;
        }
    }
    return temp_r5;
}
