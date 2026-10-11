class soModuleAccesser;

// The assembly-owned parameter table's unreferenced fields remain opaque.
// Unsigned subtraction preserves its original 32-bit group-index arithmetic.
extern "C" float fn_101_16200(void* object, soModuleAccesser*, int parameter, int index) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x10);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    float* values = *reinterpret_cast<float**>(bytes + group * sizeof(float*) + 0x18);
    return values[index];
}
extern "C" int fn_101_16220(void* object, soModuleAccesser*, int parameter, int index) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x14);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    int* values = *reinterpret_cast<int**>(bytes + group * sizeof(int*) + 0x30);
    return values[index];
}
extern "C" void* fn_101_16240(void* object, soModuleAccesser*, int parameter, int) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x18);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    return *reinterpret_cast<void**>(bytes + group * sizeof(void*) + 0x3C);
}
