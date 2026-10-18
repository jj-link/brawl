#pragma force_active on
extern "C" void fn_40_1FF8(char* self, void* val) {
    *(void**)(*(char**)(self + 0x524) + 0x628) = val;
    *(unsigned char*)(*(char**)(self + 0x524) + 0x603) = 1;
}
