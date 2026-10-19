#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_614C4(void*, short);
extern "C" void* fn_27_D3080(void*, short);

extern "C" void* fn_104_6CF4(void* object, short deleting) {
    if (object != 0) {
        fn_27_614C4(static_cast<unsigned char*>(object) + 0xAC, -1);
        if (object != 0) {
            fn_27_D3080(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
