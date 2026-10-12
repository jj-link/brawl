// The destination interprets the signed low byte of the forwarded argument word.
extern "C" bool fn_99_106EC(void* object, int value);

// Recover the complete object from its secondary interface before forwarding.
extern "C" bool fn_99_10C54(void* object, int value) {
    return fn_99_106EC(static_cast<unsigned char*>(object) - 0x48, value);
}
