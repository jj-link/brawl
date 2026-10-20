#pragma force_active on
extern "C" void* fn_41_4E364(void* ptr, short shouldDelete);

extern "C" void* fn_41_4E424(void* ptr, short shouldDelete) {
    if (ptr != 0) {
        if (ptr != 0) {
            fn_41_4E364(static_cast<char*>(ptr) + 4, -1);
        }
        if (shouldDelete > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
