#pragma force_active on
extern "C" void* fn_122_22FC(void*, short);
extern "C" void* fn_122_2158(void*, short);

extern "C" void* fn_122_2290(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_22FC(storage + 0x50, -1);
        fn_122_2158(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
