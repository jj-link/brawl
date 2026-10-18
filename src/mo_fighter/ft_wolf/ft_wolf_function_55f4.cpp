#pragma force_active on
void operator delete(void*);
extern "C" void fn_125_527C(void*, short);

extern "C" void* fn_125_55F4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 8;
        fn_125_527C(member, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
