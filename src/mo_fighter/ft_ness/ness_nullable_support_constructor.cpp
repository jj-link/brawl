struct NessNullableSupportBase {
    void* vtable;
    unsigned char nullable;
};
extern "C" unsigned char lbl_101_data_43FC[];

extern "C" void* fn_101_9210(void* object, int nullable) {
    NessNullableSupportBase* base = static_cast<NessNullableSupportBase*>(object);
    base->vtable = lbl_101_data_43FC;
    base->nullable = nullable;
    return object;
}
