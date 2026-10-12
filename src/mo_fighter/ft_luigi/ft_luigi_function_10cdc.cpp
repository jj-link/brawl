extern "C" void fn_27_1DA690(void* object, unsigned int first, unsigned int second);

// Recover the complete object from its secondary-interface receiver.
extern "C" void fn_99_10CDC(void* object, unsigned int first, unsigned int second) {
    fn_27_1DA690(static_cast<unsigned char*>(object) - 0x88, first, second);
}
