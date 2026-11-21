#pragma opt_propagation off
#pragma force_active on

class Node {
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
    virtual float frame();
};

struct Model {
    char pad[0xC];
    Node* node;
};

struct Obj {
    char pad[0x14];
    Model* model;
};

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
    virtual void invoke(int);
};

struct Base {
    char pad[0x654];
    Inner* inner;
    char pad658[0x10];

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
    virtual void activate();
    virtual void v17();
    virtual void v18();
    virtual void finish(int);
};

struct Self : Base {
    int field66c;
    int state;
    int state2;
    int field678;
    Obj* obj;
    Obj* obj2;
    char pad684[8];
    int first;
    int second;
};

extern "C" {
extern float lbl_2_rodata_EC0;
extern char lbl_2_data_3358[];
extern char lbl_2_data_33D0[];

void fn_800B330C(void*, void*, int);

void fn_2_2948C(Self* self) {
    switch (self->state) {
    case 0:
    case 1:
        break;
    case 3:
    case 5:
        if (self->obj->model->node->frame() == lbl_2_rodata_EC0 &&
            self->state != 0) {
            self->state = 0;
            self->inner->invoke(self->first);
            self->inner->invoke(self->second);
        }
        break;
    case 2:
    case 4:
        if (self->obj->model->node->frame() == lbl_2_rodata_EC0 &&
            self->state != 1) {
            self->state = 1;
            self->activate();
            Obj* obj = self->obj;
            unsigned int idx = 1;
            fn_800B330C(obj, lbl_2_data_3358 + idx * 0x14, 0);
        }
        break;
    }

    switch (self->state2) {
    case 0:
        break;
    case 1:
        if (self->obj2->model->node->frame() == lbl_2_rodata_EC0) {
            fn_800B330C(self->obj2, lbl_2_data_33D0, 0);
            self->state2 = 0;
            self->finish(1);
        }
        break;
    case 2:
        if (self->obj2->model->node->frame() == lbl_2_rodata_EC0) {
            fn_800B330C(self->obj2, lbl_2_data_33D0, 0);
            self->state2 = 0;
            self->finish(1);
        }
        break;
    }
}
}

