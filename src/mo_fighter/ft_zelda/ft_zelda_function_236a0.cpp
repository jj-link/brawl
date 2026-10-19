#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_23710(void*, short);
extern "C" void* fn_104_239D0(void*, short);

extern "C" void* fn_104_236A0(void* object, short deleting) {
    if (object != 0) {
        fn_104_23710(static_cast<unsigned char*>(object) + 0x19EC, -1);
        fn_104_239D0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
