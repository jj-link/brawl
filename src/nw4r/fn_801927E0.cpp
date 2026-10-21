#pragma force_active on

extern "C" void fn_801F0208(int, const void*, int);

extern "C" void fn_801927E0(void** arg) {
    void* ptr = *arg;
    if (!ptr) return;
    int offset = *(int*)((char*)ptr + 8);
    void* target;
    if (offset) {
        target = (void*)((char*)ptr + offset);
    } else {
        target = 0;
    }
    unsigned char val = *(unsigned char*)((char*)ptr + 0x1d);
    fn_801F0208(0xa, target, (int)val);
}
