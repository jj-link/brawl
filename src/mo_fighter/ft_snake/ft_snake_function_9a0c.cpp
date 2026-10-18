#pragma force_active on
void operator delete(void*);
extern "C" void fn_122_3E48(void*, short);

extern "C" void* fn_122_9A0C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_122_3E48(members + 0x88, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
