extern "C" unsigned int fn_99_106A8(const void* object);

// Recover the complete fighter from its secondary interface and read its
// stored 32-bit flag word.
extern "C" unsigned int fn_99_10D64(void* object) {
    return fn_99_106A8(static_cast<unsigned char*>(object) - 0x88);
}
