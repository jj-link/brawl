struct NessNullableSupportBase {
    void* vtable;
    bool nullable;
};

extern "C" bool fn_101_92E8(const NessNullableSupportBase* object) {
    return object->nullable;
}
