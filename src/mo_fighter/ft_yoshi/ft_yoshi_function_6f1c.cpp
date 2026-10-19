#pragma force_active on
extern "C" void fn_95_6F88(void*, short);
extern "C" void fn_95_421C(void*, short);

extern "C" void* fn_95_6F1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_6F88(storage + 0x24, -1);
        fn_95_421C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
