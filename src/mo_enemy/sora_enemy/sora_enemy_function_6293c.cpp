#pragma force_active on
extern "C" void fn_41_62CC4(void*, short);
extern "C" void fn_41_628D0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_6293C(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        fn_41_62CC4(static_cast<char*>(ptr) + 0x248, -1);
        fn_41_628D0(static_cast<char*>(ptr) + 4, -1);
        if (shouldDelete > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
