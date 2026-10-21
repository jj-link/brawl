#pragma force_active on

extern "C" void fn_801F0208(int, const void*, int);

extern "C" void fn_801928B0(void** arg, int b) {
    void* ptr = *arg;
    if (!ptr) return;
    unsigned int t = (unsigned int)(b - 0xb);
    if (t > 1u) return;
    int offset = *(int*)((char*)ptr + 8);
    void* target = offset ? (void*)((char*)ptr + offset) : 0;
    unsigned char val = *(unsigned char*)((char*)ptr + 0x1c);
    fn_801F0208(b, target, (int)val);
}
