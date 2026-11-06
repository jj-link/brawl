#pragma force_active on

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    int key;
    void *data;
} Node;

typedef struct Entry {
    int pad;
    int state;
} Entry;

extern Entry *fn_803970CC(int, void *);
extern void fn_80391888(int, void *);
extern void fn_803900A0(void *);
extern void fn_803974A4(int, Entry *);

int fn_80390788(Node **arg0, int arg1, int arg2) {
    Node *found = 0;
    Node *head = *arg0;
    Node *cur;
    Entry *entry;
    int result = 0;

    if (head != 0) {
        if (head->key == arg2) {
            found = head;
        } else {
            cur = head->next;
            while (cur != head) {
                if (cur->key == arg2) {
                    found = cur;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    if (found != 0) {
        if (head != head->prev) {
            found->prev->next = found->next;
            found->next->prev = found->prev;
            if (*arg0 == found) {
                *arg0 = found->next;
            }
        } else {
            *arg0 = 0;
        }
        entry = fn_803970CC(arg1, found->data);
        fn_80391888(arg1, found->data);
        fn_803900A0(found);
        if (entry != 0) {
            entry->state = 8;
            fn_803974A4(arg1, entry);
        }
        result = 1;
    }
    return result;
}
