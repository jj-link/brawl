// The secondary interface begins four bytes after the complete object; this
// vtable entry re-derives the complete object pointer and tail-calls the base
// destructor, forwarding the flag argument unchanged.
extern "C" void* fn_117_32EC(void* interface, int flag);

extern "C" void* fn_117_E1A0(void* interface, int flag) {
    return fn_117_32EC(static_cast<unsigned char*>(interface) - 4, flag);
}
