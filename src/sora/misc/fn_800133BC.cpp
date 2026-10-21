#pragma force_active on
struct Item {
    Item* next;
    unsigned char pad04[0x18];
    unsigned char flags;
    unsigned char pad1D[0x27];
    virtual void slot0();
    virtual void invoke();
};
struct Node {
    unsigned char pad00[0x11];
    unsigned char flags;
    unsigned char pad12[6];
    Node* children[4];
    int count;
    Item* head;
};
#pragma auto_inline off
extern "C" void fn_800133BC(Node* self) {
    Item* a;
    Item* b;
    Node* child;
    unsigned int i;
    unsigned int j;
    Node* current = self;
    if (current->count != 0) {
        b = current->head;
        a = (Item*)&current->head;
        while (b != a) {
            if ((b->flags >> 6) & 1) b->invoke();
            b = b->next;
        }
    }
    if (!((current->flags >> 7) & 1)) {
        for (i = 0; i < 4; ++i) {
            child = current->children[0];
            if (child->count != 0) {
                a = child->head;
                b = (Item*)&child->head;
                while (a != b) {
                    if ((a->flags >> 6) & 1) a->invoke();
                    a = a->next;
                }
            }
            if (!((child->flags >> 7) & 1)) {
                for (j = 0; j < 4; ++j) {
                    fn_800133BC(child->children[0]);
                    child = (Node*)((char*)child + 4);
                }
            }
            current = (Node*)((char*)current + 4);
        }
    }
}
