#pragma force_active on
extern "C" void fn_120_5BD8(void*, unsigned char);
extern "C" unsigned char lbl_120_data_79A8[];

struct RobotParameterAccesser {
    void* vtable;
    unsigned char padding[4];
    void* parameters;
    int index;
};

extern "C" void* fn_120_124E8(RobotParameterAccesser* object, void* parameters) {
    fn_120_5BD8(object, 0);
    object->vtable = lbl_120_data_79A8;
    object->parameters = parameters;
    object->index = -1;
    return object;
}
