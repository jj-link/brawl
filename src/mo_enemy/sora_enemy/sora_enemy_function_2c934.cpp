#pragma force_active on
extern "C" void* getNode__6utListFUl(void*, unsigned long);
extern "C" void remove__6utListFP10utListNode(void*, void*);
extern "C" void addTail__6utListFP10utListNode(void*, void*);

struct NodeBase {
    char padding[8];
};

struct Node : NodeBase {
    virtual void vf0();
    virtual void vf1(int);
};

extern "C" void* fn_41_2C934(char* self, unsigned long arg1) {
    void* node;

    if (*(unsigned char*)(self + 0x20) != 0) {
        return 0;
    }
    if (*(int*)(self + 0x10) == 0) {
        if (arg1 != 0 && *(int*)(self + 0x1c) != 0) {
            node = getNode__6utListFUl(self + 0x14, 0);
            ((Node*)node)->vf1(1);
        } else {
            return 0;
        }
    }

    node = getNode__6utListFUl(self + 8, 0);
    remove__6utListFP10utListNode(self + 8, node);
    addTail__6utListFP10utListNode(self + 0x14, node);
    return node;
}
