#pragma force_active on
extern "C" void fn_800FD96C(int a, int b);

extern "C" void fn_800FCCCC(void* base, int idx) {
    fn_800FD96C(*(int*)((char*)base + idx * 4 + 0x1C), 3);
}
