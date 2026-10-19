#pragma force_active on
extern "C" {
void* fn_104_4978(void* ptr, short count);
void operator delete(void* p);

void* fn_104_12090(void* ptr, short flags) {
    if (ptr != 0) {
        fn_104_4978(ptr, 0);
        if (flags > 0) {
            operator delete(ptr);
        }
    }
    return ptr;
}
}
