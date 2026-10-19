#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_116_FFB0(void* ptr, short count);

extern "C" void* fn_116_FF44(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0xC, -1);
        fn_116_FFB0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
