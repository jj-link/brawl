#pragma force_active on
extern "C" {
void fn_27_57F78(void*);
}

// Activate the two embedded handles at 8-byte strides, starting 4 bytes into the object.
extern "C" void fn_117_A4B4(char* object) {
    for (int i = 0; i < 2; ++i)
        fn_27_57F78(object + (i << 3) + 4);
}
