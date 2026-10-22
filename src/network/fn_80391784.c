#pragma force_active on
typedef struct Node { struct Node *next; } Node;
typedef struct Entry { unsigned char pad[0x10]; void *field10; void *field14; } Entry;
typedef struct Object { unsigned char pad[0x24]; void *field24; void *field28; void *field2C; Node *field30; Node *field34; } Object;
extern int fn_80397580(void *);
extern Entry *fn_803970CC(int, Object *);
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

void fn_80391784(void *arg0, Object *obj)
{
    int context;
    Entry *entry;

    context = fn_80397580(arg0);
    entry = fn_803970CC(context, obj);
    if (entry != 0) entry->field14 = 0;
    fn_803900A0(obj->field2C);
    entry = fn_803970CC(context, obj);
    if (entry != 0) entry->field10 = 0;
    freeList(obj->field30);
    freeList(obj->field34);
    fn_803900A0(obj->field24);
    fn_803900A0(obj->field28);
    fn_803900A0(obj);
}
