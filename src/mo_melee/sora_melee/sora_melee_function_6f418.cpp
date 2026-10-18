#pragma force_active on
typedef unsigned int u32;

struct Node {
    Node* next;
    Node* prev;
    void* data;
};

struct utListNode {
    utListNode* next;
    utListNode* prev;
};

struct utList {
    Node* getNode(unsigned long);
    void addTail(utListNode*);
};

struct Info {
    char pad[0x28];
    u32 id;
};

struct Event {
    u32 type;
    unsigned char flag;
};

struct Object {
    char pad[0x20];
    utList list;
};

struct Link {
    char pad[8];
    utListNode node;
    u32 source;
    u32 unknown14;
    Object* owner;
    utListNode node2;
    u32 target;
    u32 unknown28;
    void* found;
    u32 flags;
};

extern "C" Info* fn_27_6A5D4(void*);
extern "C" void fn_27_6AA44(void*, void*, Event*, u32);

extern "C" bool fn_27_6F418(utList* list, Object* obj, u32 id, Link* link) {
    Node* n = list->getNode(0);
    void* found;

    while (n) {
        if (id == fn_27_6A5D4(n->data)->id) {
            found = n->data;
            goto done;
        }
        n = n->next;
    }
    found = 0;

done:
    if (found) {
        link->source = fn_27_6A5D4(obj)->id;
        link->owner = obj;
        link->target = id;
        link->found = found;
        link->flags |= 1;
        obj->list.addTail(&link->node2);
        ((utList*)((char*)found + 0x14))->addTail(&link->node);

        u32 flags = (link->flags >> 1) & 0x7f;
        Event e;
        e.type = 0x3b;
        e.flag = 0;
        fn_27_6AA44(found, obj, &e, flags);
        return true;
    }
    return false;
}
