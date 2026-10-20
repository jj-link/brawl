#pragma force_active on
extern "C" void* fn_41_15FD4(char*, int);
extern "C" bool fn_41_1AE7C(void*);
extern "C" void fn_41_1E2B0(void*, void*);

extern "C" void fn_41_17E2C(void* obj, int index) {
    if (index == -1) {
        for (int i = 0; i < 8; i++) {
            void* ptr = fn_41_15FD4((char*)obj, i);
            if (!fn_41_1AE7C(ptr)) {
                fn_41_1E2B0(ptr, *(void**)((char*)obj + 0x20));
            }
        }
    } else {
        void* ptr = fn_41_15FD4((char*)obj, index);
        fn_41_1E2B0(ptr, *(void**)((char*)obj + 0x20));
    }
}
