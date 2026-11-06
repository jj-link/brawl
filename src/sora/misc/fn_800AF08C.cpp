#pragma force_active on
extern "C" void fn_800B96E8(void*, int);

extern "C" void start__6muMenuFv(void* self) {
    char* p = (char*)self;
    fn_800B96E8(p + 0x8, 0);
    fn_800B96E8(p + 0xb0, 1);
    fn_800B96E8(p + 0x158, 2);
    fn_800B96E8(p + 0x200, 3);
    fn_800B96E8(p + 0x2a8, 0xf0);
}