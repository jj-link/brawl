#pragma force_active on
class soModuleAccesser;

// Returns the pointer stored at 0x2C + (parameter - first) * 4, where `first` is the u32 at +0x18.
// Unsigned subtraction preserves the original 32-bit group-index arithmetic.
extern "C" void* fn_101_1E9B8(void* object, soModuleAccesser*, int parameter, int) {
    unsigned char* bytes = static_cast<unsigned char*>(object);
    unsigned int first = *reinterpret_cast<unsigned int*>(bytes + 0x18);
    unsigned int group = static_cast<unsigned int>(parameter) - first;
    return *reinterpret_cast<void**>(bytes + group * sizeof(void*) + 0x2C);
}
