#pragma force_active on

struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual int process(int*, void*, void*);

    char pad[12];
    unsigned int count;
    unsigned short* flags;
    int childCount;
    Node** children;
};

extern "C" void fn_8019DA5C(Node*, int, int);

extern "C" bool fn_8019A37C(Node* self, const int* arg, void* a, void* b) {
    bool result = false;
    for (int i = 0; i < self->childCount; i++) {
        Node* child = self->children[i];
        if (child) {
            int value = *arg;
            int current = child->process(&value, a, b);
            result = result || current;
            for (unsigned int j = 0; j < self->count; j++) {
                if (!(child->flags[j] & 0x8000)) {
                    self->flags[j] = 0;
                }
            }
        }
    }
    fn_8019DA5C(self, 4, 1);
    return result;
}
