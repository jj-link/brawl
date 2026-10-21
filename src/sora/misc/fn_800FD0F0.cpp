#pragma force_active on
extern "C" void fn_800FBDF4(void*, void*, int);

extern "C" void fn_800FD0F0(void* self, void* other) {
    fn_800FBDF4(*(void**)((char*)self + 0x38), other, 0);
}
