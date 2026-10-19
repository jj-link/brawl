#pragma force_active on

extern "C" {
void fn_113_64C0(void *object);
extern unsigned char lbl_113_data_6F18[];
}

struct PikminBase {
    void* vtable;
};

struct PikminDerived {
    void* vtable;
    int param;
};

extern "C" PikminDerived* fn_113_6510(PikminDerived* object, int param) {
    fn_113_64C0(object);
    object->param = param;
    object->vtable = lbl_113_data_6F18;
    return object;
}
