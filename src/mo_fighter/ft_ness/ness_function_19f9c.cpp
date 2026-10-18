#pragma force_active on
class soModuleAccesser;

extern "C" void* fn_101_19F9C(void* object, soModuleAccesser*, int parameter, int) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x18);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    return *reinterpret_cast<void**>(bytes + group * sizeof(void*) + 0x34);
}
