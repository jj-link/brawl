// The interface pointer for this entry points 0xB8 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the shared check handler, which is imported from the sora_melee
// module.
extern "C" bool fn_27_135EE0(void* object);

extern "C" bool fn_117_E1C8(void* object) {
    return fn_27_135EE0(static_cast<unsigned char*>(object) - 0xB8);
}
