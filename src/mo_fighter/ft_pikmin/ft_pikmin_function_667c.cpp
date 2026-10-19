#pragma force_active on

struct PikminState {
    void* vtable;
    void* linkedObject;
};

extern "C" {
void fn_113_64C0(void*);
extern unsigned char lbl_113_data_70D0[];

PikminState* fn_113_667C(PikminState* object, void* linkedObject) {
    fn_113_64C0(object);
    object->linkedObject = linkedObject;
    object->vtable = lbl_113_data_70D0;
    return object;
}
}
