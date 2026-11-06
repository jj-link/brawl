#pragma force_active on
// Reads the flag byte stored at offset +0x20 of the object.
unsigned char fn_801EF018(const void* object) {
    return ((const unsigned char*)object)[0x20];
}
