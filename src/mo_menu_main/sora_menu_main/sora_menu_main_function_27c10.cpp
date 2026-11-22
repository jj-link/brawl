#pragma opt_propagation off
#pragma force_active on

#include <types.h>
#include <mu/mu_object.h>

class Inner {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void invoke(void*);
};

class Node {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float getFrame();
};

struct Model {
    char pad[0x0C];
    Node* node;
};

struct Obj {
    char pad[0x14];
    Model* model;
};

struct Objects {
    char pad[0x230];
    MuObject* first;
    MuObject* second;
};
struct Resources {
    char pad[0x38];
    void* first;
    void* second;
};
struct Info {
    char pad[0x8c];
    unsigned char count;
};
struct Self {
    char pad[0x64c];
    Objects* objects;
    Resources* resources;
    Inner* inner;
    char pad658[0x18];
    int state;
    int unk674;
    Info* info;
    unsigned char field67c;
    unsigned char field67d;
};

extern "C" {
extern const float lbl_2_rodata_E6C;
extern char lbl_2_data_3098[];
void fn_800B330C(MuObject*, void*, int);
}

static inline void setState(Self* self, int state) {
    if (state != self->state) {
        self->state = state;
        if (state == 0) {
            self->inner->invoke(self->resources->first);
            self->inner->invoke(self->resources->second);
            return;
        }
        int idx = state;
        if (state == 1) {
            unsigned char pos = self->field67d;
            int flags = 0;
            if (pos != 0) flags |= 2;
            if (pos + 6 < self->info->count) flags |= 1;
            self->objects->first->setFrameVisible((float)flags);
            unsigned char pos2 = self->field67c;
            int flags2 = 0;
            if (pos2 != 0) flags2 |= 1;
            if (pos2 + 5 < self->info->count) flags2 |= 2;
            self->objects->second->setFrameVisible((float)flags2);
            idx = 1;
        }
        void* data = lbl_2_data_3098 + idx * 0x14;
        fn_800B330C(self->objects->first, data, 0);
        fn_800B330C(self->objects->second, data, 0);
    }
}

extern "C" void fn_2_27C10(Self* self) {
    switch (self->state) {
    case 3:
    case 5:
        if (lbl_2_rodata_E6C == ((Obj*)self->objects->first)->model->node->getFrame())
            setState(self, 0);
        break;
    case 2:
    case 4:
        if (lbl_2_rodata_E6C == ((Obj*)self->objects->first)->model->node->getFrame())
            setState(self, 1);
        break;
    case 0:
    case 1:
        break;
    }
}
