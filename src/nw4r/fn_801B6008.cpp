#pragma force_active on
extern "C" void fn_8019E088(void* self, int n);

extern "C" void fn_801B6008(int* self) {
    *self = 0;
    fn_8019E088((char*)self + 4, 0x40);
}
