#pragma force_active on
extern "C" void fn_123_6D30(void* object, unsigned int value);
extern "C" unsigned char lbl_123_data_7050[];

struct FtSonicParamAccesser {
    void* vtable;
    unsigned char nullableStorage[4];
    void* parameters;
    int index;
};

extern "C" void* fn_123_13000(FtSonicParamAccesser* object, void* parameters) {
    fn_123_6D30(object, 0);
    object->vtable = lbl_123_data_7050;
    object->parameters = parameters;
    object->index = -1;
    return object;
}
