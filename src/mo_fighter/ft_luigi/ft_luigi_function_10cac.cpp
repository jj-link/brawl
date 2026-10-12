extern "C" void fn_27_1DB270(void* result, void* object);

// The result-buffer argument precedes the secondary-interface receiver in the ABI.
extern "C" void fn_99_10CAC(void* result, void* object) {
    fn_27_1DB270(result, static_cast<unsigned char*>(object) - 0x88);
}
