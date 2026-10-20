#pragma force_active on
struct Node {
    Node* next;
    Node* prev;
};

struct Collision {
    char pad[0x2C];
    unsigned char enabled : 1;
    unsigned char other : 5;
    unsigned char active : 1;
    unsigned char last : 1;
    char padding[3];
    Node node;
};

extern "C" void fn_27_275534(Collision*, void*);
extern "C" char g_grCollisionList[12];

extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
    char*, void**, Node*);

extern "C" Collision* fn_27_2754B4(
    Collision* self, void* data, bool enabled, bool active)
{
    self->enabled = enabled;
    self->active = 0;
    self->node.next = 0;
    self->node.prev = 0;

    fn_27_275534(self, data);

    self->active = active;
    void* it = g_grCollisionList + 4;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
        g_grCollisionList, &it, &self->node);

    return self;
}
