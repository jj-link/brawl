#pragma force_active on
class soModuleAccesser;

// Same table layout as fn_101_16240, but the group index is read from 0x18 and the entry is at 0x44.
extern "C" void* fn_101_23D2C(void* object, soModuleAccesser*, int parameter, int) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x18);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    return *reinterpret_cast<void**>(bytes + group * sizeof(void*) + 0x44);
}
