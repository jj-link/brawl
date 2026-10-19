#pragma force_active on
extern "C" void fn_40_278C0(void* self);

extern "C" void fn_40_2A1E0(void* self) {
    fn_40_278C0(self);
    *(unsigned int*)((char*)self + 0x170) = *(unsigned int*)((char*)self + 0xBC);
}
