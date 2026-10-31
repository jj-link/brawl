#pragma force_active on
extern "C" {
extern float lbl_2_rodata_DA0;
void fn_2_26DC4(void*, int);
void fn_2_26520(void*, int);
}

struct Node {
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

struct MuObject {
    char pad[0x14];
    Model* model;
};

struct MenuObjects {
    char pad[0x220];
    MuObject* object;
};

struct Menu {
    char pad[0x64C];
    MenuObjects* objects;
    char pad650[0x28];
    int state;
};

extern "C" void fn_2_26BE4(Menu* self) {
    switch (self->state) {
    case 0:
        break;
    case 1:
        if (self->objects->object->model->node->getFrame() == lbl_2_rodata_DA0)
            fn_2_26DC4(self, 2);
        break;
    case 2:
        break;
    case 3:
        if (self->objects->object->model->node->getFrame() == lbl_2_rodata_DA0)
            fn_2_26DC4(self, 0);
        break;
    case 4:
        if (self->objects->object->model->node->getFrame() == lbl_2_rodata_DA0) {
            fn_2_26DC4(self, 2);
            fn_2_26520(self, 1);
        }
        break;
    case 5:
        if (self->objects->object->model->node->getFrame() == lbl_2_rodata_DA0) {
            fn_2_26DC4(self, 2);
            fn_2_26520(self, 1);
        }
        break;
    case 6:
        if (self->objects->object->model->node->getFrame() == lbl_2_rodata_DA0)
            fn_2_26DC4(self, 8);
        break;
    case 7:
        if (self->objects->object->model->node->getFrame() == lbl_2_rodata_DA0)
            fn_2_26DC4(self, 2);
        break;
    case 8:
        break;
    }
}
