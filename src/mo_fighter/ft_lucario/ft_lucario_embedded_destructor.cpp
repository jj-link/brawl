void operator delete(void*);
extern "C" void* fn_118_38C8(void*, short);
extern "C" void* fn_27_1DBB60(void*, short);
extern "C" void* fn_118_12F20(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

// Embedded members are destroyed in reverse construction order without freeing
// their storage; only the complete object honors the positive deletion flag.
extern "C" void* fn_118_12E98(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_118_38C8(storage + 0x1DC8, -1);
        fn_27_1DBB60(storage + 0x1D90, -1);
        fn_118_12F20(storage + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
