#pragma force_active on
extern "C" {
void fn_27_248FA8(void* a, int b);
void* fn_27_253110(void* ptr, int flag) {
    if (ptr) {
        fn_27_248FA8(ptr, 0);
        if (flag > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
}
