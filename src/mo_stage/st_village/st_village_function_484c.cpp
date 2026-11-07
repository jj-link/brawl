#pragma force_active on
extern const float lbl_70_rodata_48;

class Class_3790 {
public:
    virtual void fn_70_B644();
    virtual void fn_70_AB0C();
    virtual void fn_70_AB1C();
    virtual void fn_70_9164();
    virtual void fn_70_8EEC();
    virtual void fn_70_8A50();
    virtual float fn_70_AE10();
};

struct Node {
    unsigned char pad[0x10];
    Class_3790* obj;
};

struct Village {
    unsigned char pad[0x48];
    Node** nodes;
};

extern "C" float fn_70_484C(Village* self, int index) {
    Node* node = self->nodes[index];
    if (node == 0) {
        return lbl_70_rodata_48;
    }
    if (node->obj == 0) {
        return lbl_70_rodata_48;
    }
    return node->obj->fn_70_AE10();
}
