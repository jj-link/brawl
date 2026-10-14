// The interface pointer for this entry points 0x48 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the local event predicate, which reports whether the event
// equals 12 (the predicate sign-extends the event internally).
extern "C" bool fn_117_A1FC(void* object, int event);

extern "C" bool fn_117_E1E8(void* object, int event) {
    return fn_117_A1FC(static_cast<unsigned char*>(object) - 0x48, event);
}
