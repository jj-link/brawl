#pragma force_active on
extern "C" {
extern unsigned char lbl_99_data_1BAC[];
}

struct LuigiSubobject {
    const void* vtable;
    unsigned char padding[0x0C];
    void* field10;
    void* field14;
    void* field18;
};

extern "C" LuigiSubobject* fn_99_7C08(
    LuigiSubobject* object, void* a, void* b, void* c
) {
    object->vtable = lbl_99_data_1BAC;
    object->field10 = a;
    object->field14 = b;
    object->field18 = c;
    return object;
}
