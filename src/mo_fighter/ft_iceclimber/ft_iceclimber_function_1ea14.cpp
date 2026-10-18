#pragma force_active on
struct IceClimberFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned int gap;
    float* floatArrays[1];
};

extern "C" float fn_105_1EA14(
    IceClimberFloatAccesser* self,
    void* accesser,
    int index,
    int element
) {
    return self->floatArrays[index - self->indexBase][element];
}
