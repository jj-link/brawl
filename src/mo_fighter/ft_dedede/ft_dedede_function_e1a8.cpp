// The interface pointer for this entry points 0x40 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the primary implementation, forwarding the flag argument
// unchanged.
extern "C" void* fn_117_19B4(void* interface, int flag);

extern "C" void* fn_117_E1A8(void* interface, int flag) {
    return fn_117_19B4(static_cast<unsigned char*>(interface) - 0x40, flag);
}
