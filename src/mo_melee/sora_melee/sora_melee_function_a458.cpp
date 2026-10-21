#pragma force_active on

typedef unsigned long u32;

struct Node {
    u32 id;
    char pad04[12];
    float x;
    char pad14[20];
    u32 flags;
};

struct ModelBase {
    char pad00[8];
};

struct Model : ModelBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void update();

    char pad0c[0x30];
    char list[12];
};

extern "C" Node* fn_8015C1D0(void*, int);
extern "C" void fn_8015C144(void*, Node*);
extern "C" void fn_8015C024(void*, Node*, Node*);
extern "C" Node* fn_8015C1B0(void*, Node*);

inline Node* findNode(Model* self, u32 id) {
    Node* node = 0;

    while ((node = fn_8015C1B0(self->list, node)) != 0) {
        if (node->flags != 0) {
            if (id == node->id)
                return node;

            if (id < node->id) {
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

extern "C" void setNodeRotateX__17soModelModuleImplFUlf(
    Model* self, u32 id, float value
) {
    Node* node = findNode(self, id);
    node->id = id;
    node->x = value;
    node->flags |= 8;
    self->update();
}
