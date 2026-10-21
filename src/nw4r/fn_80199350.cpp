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
    int count;
    unsigned short* flags;
    int childCount;
    Node** children;
};

extern "C" void fn_8019DA5C(Node*, int, int);

extern "C" void fn_80199350(Node* self) {
    for (int i = 0; i < self->count; i++) {
        self->flags[i] = 0x8000;
    }
    fn_8019DA5C(self, 4, 0);
}
