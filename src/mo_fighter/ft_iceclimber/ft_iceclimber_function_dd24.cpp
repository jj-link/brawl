#pragma force_active on
typedef struct WorkObj {
    unsigned char pad[0x14];
    float *floats;
} WorkObj;

extern "C" void fn_105_DD24(WorkObj *obj, unsigned int index, float value) {
    obj->floats[index] *= value;
}
