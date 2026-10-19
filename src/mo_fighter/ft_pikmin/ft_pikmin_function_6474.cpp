#pragma force_active on
struct PikminLinked {
    void* vtable;
    void* linkedObject;
};

extern "C" {
void fn_113_64C0(void*);
extern unsigned char lbl_113_data_6F98[];
}

extern "C" PikminLinked* fn_113_6474(PikminLinked* object, void* linkedObject) {
    fn_113_64C0(object);
    object->linkedObject = linkedObject;
    object->vtable = lbl_113_data_6F98;
    return object;
}
