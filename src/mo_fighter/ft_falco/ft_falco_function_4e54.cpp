#pragma force_active on
void operator delete(void*);

extern "C" void fn_108_1F14(void*, short);

extern "C" void* fn_108_4E54(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_108_1F14(members + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
