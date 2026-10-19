#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_625DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_62648(void* ptr, short shouldDelete) {
    if (ptr) {
        fn_41_62CC4(static_cast<char*>(ptr) + 0xF8, -1);
        fn_41_625DC(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
