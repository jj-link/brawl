#pragma force_active on
// Pit (ft_pit) flag accessor: byte 0xA4 of the Pit work struct keeps its
// per-flag state in single bits.  This sets/clears the "selected" flag
// (bit 6 of the byte) from the low bit of the caller supplied value,
// leaving the remaining bits of the byte untouched.
struct PitCallbackFlags {
    unsigned char high : 1;   // bit 7 of the byte (shift distance 24)
    unsigned char selected : 1; // bit 6 of the byte (shift distance 25)
    unsigned char other : 6;  // bits 0-5 of the byte
};

static inline PitCallbackFlags* callbackFlags(void* object) {
    return reinterpret_cast<PitCallbackFlags*>(static_cast<unsigned char*>(object) + 0xA4);
}

extern "C" void fn_112_110F4(void* object, int flags) {
    callbackFlags(object)->selected = (flags & 1) != 0;
}
