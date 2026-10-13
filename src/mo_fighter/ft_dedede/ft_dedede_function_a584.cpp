// Shared handler accessor: return the handler address advanced by the 0x70 offset.
extern "C" void* fn_117_A584(void* handler) {
    return static_cast<unsigned char*>(handler) + 0x70;
}
