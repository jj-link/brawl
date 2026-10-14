// The secondary interface begins four bytes after the complete object; this
// vtable entry re-derives the complete object pointer and tail-calls the
// primary implementation, forwarding the flag argument unchanged.
extern "C" void* fn_117_43A8(void* interface, int flag);

extern "C" void* fn_117_E190(void* interface, int flag) {
    return fn_117_43A8(static_cast<unsigned char*>(interface) - 4, flag);
}
