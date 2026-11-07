#pragma force_active on
extern "C" void fn_80281BBC(void*, const void*, int);
extern "C" int fn_80080A7C(char* self, void* dest, int size) {
    if (size > 0) {
        fn_80281BBC(dest, *(char**)(self + 8) + *(int*)(self + 0x10), size);
        *(int*)(self + 0x10) += size;
        return size;
    }
    return 0;
}