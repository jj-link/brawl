#pragma force_active on
extern "C" const float lbl_rodata_C0;

struct Float2 {
    float pad[2];
    float first;
    float second;
};

extern "C" float fn_96_23BC4(const Float2 *object) {
    return object->first * object->second;
}
