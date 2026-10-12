// Shared handler flag-byte getter: return the byte stored at offset 0x44 of
// the handler object.
extern "C" int fn_117_A2B8(void* handler) {
    return *reinterpret_cast<unsigned char*>(static_cast<unsigned char*>(handler) + 0x44);
}
