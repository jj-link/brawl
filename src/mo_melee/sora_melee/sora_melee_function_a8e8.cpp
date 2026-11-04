#pragma force_active on

typedef unsigned long u32;

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Node {
    u32 id;
    char pad04[0x18];
    float x;
    float y;
    float z;
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
    virtual void update(float y);

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

extern "C" void setNodeTranslate__17soModelModuleImplFUlP5Vec3f(
    soModelModuleImpl* self, u32 id, const Vec3f* v
) {
    Node* node = findNode(self, id);
    node->id = id;
    float x = v->x;
    float y = v->y;
    node->x = x;
    float z = v->z;
    node->y = y;
    node->z = z;
    node->flags |= 0x1c0;
    self->update(v->y);
}
