// The interface pointer for this entry points 0x40 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the in-module handler, forwarding the flag argument unchanged.
// fn_117_A218's verified interface is (void* object, int flag) -> void*: it
// saves both r3 and r4 on entry, tests the flag via a sign-extended halfword
// compare, and returns its first parameter in r3; the flag is forwarded in
// the ABI word type so the tail call needs no conversion.
extern "C" void* fn_117_A218(void* object, int flag);

extern "C" void* fn_117_E1D8(void* interface, int flag) {
    return fn_117_A218(static_cast<unsigned char*>(interface) - 0x40, flag);
}
