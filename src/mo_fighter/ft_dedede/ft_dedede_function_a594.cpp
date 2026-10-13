// Shared handler accessor: return the handler address advanced by the 0x48 offset.
extern "C" void* fn_117_A594(void* handler) {
    return static_cast<unsigned char*>(handler) + 0x48;
}
