#pragma force_active on
extern "C" void fn_27_12DCA8(void*);

extern "C" void fn_101_B650(void* self) {
    fn_27_12DCA8(self);
    *(unsigned char*)((unsigned char*)self + 0x4AE25) = 0;
    *(unsigned char*)((unsigned char*)self + 0x4AE24) = 0;
}
