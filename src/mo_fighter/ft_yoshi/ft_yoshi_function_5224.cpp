#pragma force_active on
extern "C" void* fn_95_4C88(void*, short);
extern "C" void* fn_95_5290(void*, short);
void operator delete(void*);

extern "C" void* fn_95_5224(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_95_4C88(p + 0x2008, -1);
        fn_95_5290(p + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
