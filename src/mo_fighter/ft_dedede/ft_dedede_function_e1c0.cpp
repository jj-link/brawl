// The interface pointer for this entry points 0x70 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the sora_melee implementation, forwarding the flag argument
// unchanged.
extern "C" void* fn_27_131CD0(void* interface, int flag);

extern "C" void* fn_117_E1C0(void* interface, int flag) {
    return fn_27_131CD0(static_cast<unsigned char*>(interface) - 0x70, flag);
}
