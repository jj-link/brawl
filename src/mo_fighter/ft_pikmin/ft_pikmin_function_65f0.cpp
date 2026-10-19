#pragma force_active on

struct PikminObject {
    void* vtable;
    void* value;
};

extern "C" {
void fn_113_64C0(void*);
extern unsigned char lbl_113_data_7150[];

PikminObject* fn_113_65F0(PikminObject* object, void* value) {
    fn_113_64C0(object);
    object->value = value;
    object->vtable = lbl_113_data_7150;
    return object;
}
}
