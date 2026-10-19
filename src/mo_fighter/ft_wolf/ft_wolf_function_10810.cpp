#pragma force_active on
extern "C" {
void fn_27_311F44(void*);
void fn_27_1D9FF8(void*);

void fn_125_10810(void* self) {
    fn_27_311F44(*(void**)((char*)self + 0x60));
    fn_27_1D9FF8(self);
}
}
