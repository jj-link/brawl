#pragma force_active on
void operator delete(void*);

extern "C" void* fn_107_3C8C(void*, short);

extern "C" void* fn_107_1ED6C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_107_3C8C(members + 0x18, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
