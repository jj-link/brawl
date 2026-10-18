#pragma force_active on
struct GameWatchFloatAccesser {
    unsigned char prefix[0x10];
    unsigned int indexBase;
    unsigned char gap[0x4];
    float* floatArrays[1];
};

extern "C" float fn_107_16950(GameWatchFloatAccesser* self, void* accesser, int index, int element) {
    return self->floatArrays[index - self->indexBase][element];
}
