#pragma force_active on

typedef unsigned long u32;

struct Node {
    u32 id;
    char pad4[0x10];
    float y;
    char pad18[0x10];
    u32 flags;
};

struct ModuleBase {
    char pad0[8];
};

struct soModelModuleImpl : ModuleBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void update();

    char padC[0x30];
    char list[12];
};

extern "C" Node* fn_8015C1B0(void*, Node*);
extern "C" Node* fn_8015C1D0(void*, int);
extern "C" void fn_8015C144(void*, Node*);
extern "C" void fn_8015C024(void*, Node*, Node*);

inline Node* findNode(soModelModuleImpl* self, u32 id) {
    Node* node = 0;
    while ((node = fn_8015C1B0(self->list, node)) != 0) {
        if (node->flags != 0) {
            if (id == node->id) return node;
            else if (id < node->id) {
                Node* fresh = fn_8015C1D0(self->list, 0);
                fn_8015C144(self->list, fresh);
                fn_8015C024(self->list, node, fresh);
                return fresh;
            }
        } else {
            return node;
        }
    }
    return 0;
}

extern "C" void setNodeRotateY__17soModelModuleImplFUlf(
    soModelModuleImpl* self, u32 id, float value
) {
    Node* node = findNode(self, id);
    node->id = id;
    node->y = value;
    node->flags |= 0x10;
    self->update();
}
