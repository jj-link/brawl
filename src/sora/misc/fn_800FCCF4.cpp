#pragma force_active on
extern "C" void fn_800FD96C(int, int);

extern "C" void fn_800FCCF4(int base, int idx) {
    fn_800FD96C(*(int*)(base + idx * 4 + 0x1c), 5);
}
