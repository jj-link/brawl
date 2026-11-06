#pragma force_active on
struct Class_804207E4_base {
    Class_804207E4_base* next;
    unsigned char pad04[0x18];
    unsigned char flags;
    unsigned char pad1D[0x27];
};
class Class_804207E4 : public Class_804207E4_base {
public:
    virtual void fn_80011148();
    virtual void fn_80011170();
};
struct Node {
    unsigned char pad00[0x11];
    unsigned char flags;
    unsigned char pad12[6];
    Node* children[4];
    int count;
    Class_804207E4* head;
};
struct Root {
    unsigned char pad00[0x51];
    unsigned char flags;
    unsigned char pad52[6];
    Node* children[4];
    int count;
    Class_804207E4* head;
    unsigned char pad70[5];
    unsigned char active;
};
extern "C" void fn_800133BC(Node*);
#pragma auto_inline off
extern "C" void fn_800128EC(Root* self) {
    Class_804207E4* a;
    Class_804207E4* b;
    unsigned int i;
    Node* child;
    unsigned int j;
    Root* current = self;
    if (current->active != 0) {
        if (current->count != 0) {
            b = current->head;
            a = (Class_804207E4*)&current->head;
            while (b != a) {
                if ((b->flags >> 6) & 1) b->fn_80011170();
                b = (Class_804207E4*)b->next;
            }
        }
        if (!((current->flags >> 7) & 1)) {
            for (i = 0; i < 4; ++i) {
                child = current->children[0];
                if (child->count != 0) {
                    a = child->head;
                    b = (Class_804207E4*)&child->head;
                    while (a != b) {
                        if ((a->flags >> 6) & 1) a->fn_80011170();
                        a = (Class_804207E4*)a->next;
                    }
                }
                if (!((child->flags >> 7) & 1)) {
                    for (j = 0; j < 4; ++j) {
                        fn_800133BC(child->children[0]);
                        child = (Node*)((char*)child + 4);
                    }
                }
                current = (Root*)((char*)current + 4);
            }
        }
    }
}