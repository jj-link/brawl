#pragma force_active on
typedef unsigned int u32;

extern "C" {
void remove__6utListFP10utListNode(void*, void*);
void addTail__6utListFP10utListNode(void*, void*);
}

struct FooNode {
    FooNode* next;
    FooNode* prev;
    u32 id;
};

extern "C" {
void fn_27_228C04(char* self, u32 id) {
    FooNode* node = *(FooNode**)(self + 0x84);
    while (node != 0) {
        FooNode* next = node->next;
        if (node->id == id) {
            remove__6utListFP10utListNode(self + 0x84, node);
            addTail__6utListFP10utListNode(self + 0x90, node);
            break;
        }
        node = next;
    }
}
}
