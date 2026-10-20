#pragma force_active on
struct GeneratorHandle {
    int index;
    void* generator;
};

extern unsigned char lbl_27_bss_D0[0x18];

extern "C" void fn_27_57E20(char* self, int index);

extern "C" void fn_27_57F78(GeneratorHandle* self) {
    if (self->index != -1) {
        fn_27_57E20(reinterpret_cast<char*>(lbl_27_bss_D0), self->index);
        self->index = -1;
        self->generator = 0;
    }
}
