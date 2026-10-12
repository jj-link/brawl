// Shared word getter: return the 32-bit word stored at offset 0x110 of
// the handler object.
extern "C" int fn_117_A450(void* handler) {
    return *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(handler) + 0x110);
}
