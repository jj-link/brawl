#pragma force_active on
extern "C" void fn_800FD96C(int, int);

extern "C" void fn_800FCD08(unsigned char* base, unsigned int idx) {
    fn_800FD96C(*(int*)(base + idx * 4 + 0x1c), 6);
}
