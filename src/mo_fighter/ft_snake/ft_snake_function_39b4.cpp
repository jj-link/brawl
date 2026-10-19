#pragma force_active on
extern "C" void* fn_122_2234(void* p, short flag);
extern "C" void* fn_122_2158(void* p, short del);

extern "C" void* fn_122_39B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_2234(storage + 0x50, -1);
        fn_122_2158(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
