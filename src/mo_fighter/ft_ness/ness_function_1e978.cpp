#pragma force_active on
class soModuleAccesser;

extern "C" float fn_101_1E978(void* object, soModuleAccesser*, int parameter, int index) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x10);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    float* values = *reinterpret_cast<float**>(bytes + group * sizeof(float*) + 0x18);
    return values[index];
}
