#pragma force_active on
void operator delete(void*);
extern "C" void fn_93_136C0(void*, short);
extern "C" void* fn_93_132A4(void*, short);

extern "C" void* fn_93_13750(void* object, short deleting) {
    if (object != 0) {
        fn_93_136C0(static_cast<unsigned char*>(object) + 0x19EC, -1);
        fn_93_132A4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
