extern "C" void fn_27_1DB794(void* object, float multiplier);

// Recover the complete fighter from its secondary interface.
extern "C" void fn_99_10C94(void* object, float multiplier) {
    fn_27_1DB794(static_cast<unsigned char*>(object) - 0x88, multiplier);
}
