#pragma force_active on

typedef unsigned short u16;

struct Root {
    unsigned char pad[0x1B8];
    int count;
};

struct Manager;

struct Context {
    u16 flag;
    unsigned char pad2[2];
    int value;
    Root* root1;
    Root* root2;
    int pad14;
    void* owner;
};

class Self {
public:
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
    virtual int v10();

    unsigned char pad[4];
    Manager* manager;
    Root* root1;
    Root* root2;
};

extern "C" void fn_802F4458(Manager* self, Context* context);
extern "C" void fn_802E4140(Root* self, Context* context);

extern "C" void fn_802D7C78(Self* self, u16 arg1) {
    Root* root1 = self->root1;
    Root* root2 = self->root2;
    Context context;

    context.flag = arg1;
    context.value = 0;
    context.root1 = root1;
    context.root2 = root2;
    context.owner = self;

    if (arg1 != 0xFFFF) {
        int value = self->v10();
        if (value != 0) {
            value += 8;
        }
        context.value = value;
    }

    fn_802F4458(self->manager, &context);

    if (root1->count != 0) {
        fn_802E4140(root1, &context);
    }

    if (root2->count != 0) {
        fn_802E4140(root2, &context);
    }
}
