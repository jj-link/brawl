#pragma force_active on
extern "C" void fn_800FD96C(int a, int b);

extern "C" void fn_800FCCE0(int base, int idx) {
    fn_800FD96C(*(int*)(base + idx * 4 + 0x1c), 4);
}
