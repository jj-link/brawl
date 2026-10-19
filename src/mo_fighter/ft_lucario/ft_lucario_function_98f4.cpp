#pragma force_active on
extern "C" void fn_118_99DC(void*, unsigned long, unsigned char);

extern "C" void fn_118_98F4(void* obj) {
    void* target = *(void**)((unsigned char*)obj + 0x60);
    fn_118_99DC(target, 0x10000047, 0);
    fn_118_99DC(target, 0x10000048, 0);
    fn_118_99DC(target, 0x10000043, 0);
    fn_118_99DC(target, 0x10000044, 0);
}
