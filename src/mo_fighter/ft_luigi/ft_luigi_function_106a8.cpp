// The field's meaning is unknown; preserve the stored 32-bit value unchanged.
extern "C" unsigned int fn_99_106A8(const void* object) {
    return *reinterpret_cast<const unsigned int*>(
        static_cast<const unsigned char*>(object) + 0xc0);
}
