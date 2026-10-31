#pragma force_active on
extern "C" {
extern const float lbl_2_rodata_B40[];
extern unsigned char lbl_2_data_2EF8[];
void setFrameNode__8MuObjectFf(void*, float);
void fn_800B330C(void*, void*, int);
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
    virtual void f8(float);
};

struct Model {
    unsigned char padding[0x0C];
    Node* node;
};

struct MuObject {
    unsigned char padding[0x14];
    Model* model;
    int field18;
    int field1C;
};

struct MenuObjects {
    unsigned char padding[0x220];
    MuObject* object;
};

struct Menu {
    unsigned char padding[0x64C];
    MenuObjects* objects;
    unsigned char padding650[0x28];
    int state;
};

extern "C" void fn_2_26DC4(Menu* self, int state)
{
    const float* ro = lbl_2_rodata_B40;

    if (state != self->state) {
        MuObject* object = self->objects->object;

        switch (state) {
        case 0:
            object->field1C = 0;
            setFrameNode__8MuObjectFf(object, ro[0x98]);
            object->model->node->f8(ro[0x98]);
            break;
        case 1:
            fn_800B330C(object, lbl_2_data_2EF8, 0);
            break;
        case 2:
            object->field1C = 0;
            setFrameNode__8MuObjectFf(object, ro[0xAA]);
            object->model->node->f8(ro[0x98]);
            break;
        case 3:
            fn_800B330C(object, lbl_2_data_2EF8 + 0x14, 0);
            break;
        case 4:
            fn_800B330C(object, lbl_2_data_2EF8 + 0x28, 0);
            break;
        case 5:
            fn_800B330C(object, lbl_2_data_2EF8 + 0x3C, 0);
            break;
        case 6:
        case 7:
            break;
        case 8:
            object->field1C = 0;
            setFrameNode__8MuObjectFf(object, ro[0xAB]);
            object->model->node->f8(ro[0x98]);
            break;
        }

        self->state = state;
    }
}
