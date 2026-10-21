#pragma force_active on

typedef unsigned int u32;

struct Node {
    u32 id;
    char pad04[0x14];
    float rotateZ;
    char pad1C[0xC];
    u32 flags;
};

struct Prefix {
    char pad0[8];
};

struct Model : Prefix {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void update();

    char padC[0x30];
    char list[1];
};

extern "C" Node* fn_8015C1B0(void*, Node*);
extern "C" Node* fn_8015C1D0(void*, int);
extern "C" void fn_8015C144(void*, Node*);
extern "C" void fn_8015C024(void*, Node*, Node*);

inline Node* findNode(Model* self, u32 id) {
    Node* node = 0;
    while ((node = fn_8015C1B0(self->list, node)) != 0) {
        if (node->flags != 0) {
            if (id == node->id) {
                return node;
            } else if (id < node->id) {
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

extern "C" void setNodeRotateZ__17soModelModuleImplFUlf(
    Model* self, u32 id, float value
) {
    Node* node = findNode(self, id);
    node->id = id;
    node->rotateZ = value;
    node->flags |= 0x20;
    self->update();
}
