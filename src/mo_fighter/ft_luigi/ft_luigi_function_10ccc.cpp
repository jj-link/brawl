extern "C" void fn_27_1DA618(void* object, unsigned int index);

// Recover the complete fighter from its secondary interface.
extern "C" void fn_99_10CCC(void* object, unsigned int index) {
    fn_27_1DA618(static_cast<unsigned char*>(object) - 0x88, index);
}
