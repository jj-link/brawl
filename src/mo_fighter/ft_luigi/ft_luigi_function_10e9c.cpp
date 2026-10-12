extern "C" const unsigned char lbl_99_data_6E58[];

struct LuigiGlobalObject {
    const void* vtable;
};

extern "C" LuigiGlobalObject* fn_99_10E9C(LuigiGlobalObject* object) {
    object->vtable = lbl_99_data_6E58;
    return object;
}
