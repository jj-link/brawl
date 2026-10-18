#pragma force_active on
class soModuleAccesser;

// Reads the 0x18 "first group" field, subtracts it from the parameter (unsigned),
// and returns the pointer stored at bytes + group * 4 + 0x24.
extern "C" void* fn_101_1C684(void* object, soModuleAccesser*, int parameter, int) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x18);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    return *reinterpret_cast<void**>(bytes + group * sizeof(void*) + 0x24);
}
