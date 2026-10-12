// Shared handler vtable getter: return the 32-bit field stored at offset
// 0xB8 of the handler object.
extern "C" int fn_117_99D8(void* handler) {
    return *reinterpret_cast<int*>(static_cast<unsigned char*>(handler) + 0xB8);
}
