#pragma force_active on
extern "C" void fn_800FD96C(int a, int b);

extern "C" void fn_800FCCB8(unsigned char* base, unsigned int idx) {
    int v = *(int*)(base + (idx << 2) + 0x1c);
    fn_800FD96C(v, 2);
}
