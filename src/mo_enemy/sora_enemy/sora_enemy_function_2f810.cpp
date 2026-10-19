#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_41_25C8(void* p, short size);

extern "C" void* fn_41_2F810(void* p, short flag) {
    if (p) {
        fn_27_565F0(static_cast<unsigned char*>(p) + 0xC, -1);
        fn_41_25C8(p, -1);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}
