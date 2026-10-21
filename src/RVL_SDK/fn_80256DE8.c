#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Node Node;
typedef struct Group Group;

struct Node {
    Node *next;
    u16 type;
    u16 flags;
    Node *child;
};

struct Group {
    Node *nodes;
    Group *next;
};

typedef struct Container {
    char pad[8];
    Group *groups;
} Container;

extern u8 fn_8025BE44(int, Node *);

Group *fn_80256DE8(Container *self, int value, Group *start)
{
    Group *group;
    Node *node;
    Node *child;

    if (start == 0)
        group = self->groups;
    else
        group = start->next;

    while (group != 0) {
        node = group->nodes;
        while (node != 0) {
            if (node->type == 1 && ((int)node->flags >> 12) == 6) {
                child = node->child;
                while (child != 0) {
                    if (((int)child->flags >> 12) == 3 &&
                        fn_8025BE44(value, child))
                        return group;
                    child = child->next;
                }
                break;
            }

            if (node->type == 3 && ((int)node->flags >> 12) == 3 &&
                fn_8025BE44(value, node))
                return group;

            node = node->next;
        }
        group = group->next;
    }

    return 0;
}
