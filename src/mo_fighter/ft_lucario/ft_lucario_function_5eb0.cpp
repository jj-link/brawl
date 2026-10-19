#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_118_5F1C(void* object, short deleting);

extern "C" void* fn_118_5EB0(void* object, short deleting) {
    if (object != 0) {
        fn_27_565F0(static_cast<unsigned char*>(object) + 0x14, -1);
        fn_118_5F1C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
