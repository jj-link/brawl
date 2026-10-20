#pragma force_active on
extern "C" void* fn_27_14B698(void*, short);

extern "C" {
void* fn_27_37B498(void* ptr, int flag) {
    if (ptr) {
        fn_27_14B698(ptr, -1);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
}
