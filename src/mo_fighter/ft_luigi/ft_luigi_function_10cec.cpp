extern "C" void* fn_27_1DB16C(void* object);

// Recover the complete object from its secondary interface before forwarding.
extern "C" void* fn_99_10CEC(void* object) {
    return fn_27_1DB16C(static_cast<unsigned char*>(object) - 0x88);
}
