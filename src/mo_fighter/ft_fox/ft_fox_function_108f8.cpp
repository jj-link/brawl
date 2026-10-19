#pragma force_active on
extern "C" {
void fn_27_311F44(void* p);
void fn_27_1D9FF8(void* p);
}

extern "C" void fn_97_108F8(void* self) {
    fn_27_311F44(*(void**)((char*)self + 0x60));
    fn_27_1D9FF8(self);
}
