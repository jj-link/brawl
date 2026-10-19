#pragma force_active on
extern "C" void fn_108_705C(void*, short);
extern "C" void fn_108_3F60(void*, short);

extern "C" void* fn_108_6FF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_705C(storage + 0x24, -1);
        fn_108_3F60(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
