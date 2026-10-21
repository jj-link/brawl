#pragma force_active on
extern "C" void fn_8026F860(void);

extern "C" void fn_80036BF4(void* self) {
    int c = *(unsigned char*)((char*)self + 0xb1);
    c |= 0x20;
    *(unsigned char*)((char*)self + 0xb1) = (unsigned char)c;
    if (((c >> 4) & 1) == 0) {
        return;
    }
    int x = *(int*)((char*)self + 0xb0);
    if ((x >> 28) != 2) {
        return;
    }
    fn_8026F860();
}
