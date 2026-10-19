#pragma force_active on
extern "C" void* fn_95_1922C(void*, short);
extern "C" void* fn_95_19460(void*, short);

extern "C" void* fn_95_191BC(void* object, short deleting) {
    if (object != 0) {
        fn_95_1922C(static_cast<unsigned char*>(object) + 0x19e8, -1);
        fn_95_19460(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
