#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
void operator delete(void*);

extern "C" void* fn_117_5410(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        fn_27_1A2524(members + 0x10, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
