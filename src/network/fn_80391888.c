#pragma force_active on

typedef struct Node { struct Node *next; } Node;
typedef struct Entry { unsigned char pad[0x10]; void *field10; } Entry;
typedef struct Object { unsigned char pad[0x24]; void *field24; void *field28; void *field2C; Node *field30; Node *field34; } Object;

extern Entry *fn_803970CC(int);
extern void fn_803900A0(void *);

static inline void freeList(Node *list)
{
    while (list != 0) {
        Node *node = list->next;
        if (list != node) {
            Node *next = node->next;
            fn_803900A0(node);
            list->next = next;
        } else {
            fn_803900A0(list);
            list = 0;
        }
    }
}

int fn_80391888(int arg0, Object *obj)
{
    Entry *entry;

    entry = fn_803970CC(arg0);
    if (entry != 0) entry->field10 = 0;
    freeList(obj->field30);
    freeList(obj->field34);
    fn_803900A0(obj->field24);
    fn_803900A0(obj->field28);
    fn_803900A0(obj);
    return 1;
}
