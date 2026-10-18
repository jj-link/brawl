#pragma force_active on
void operator delete(void*);
extern "C" void* fn_125_3B44(void*, short);

extern "C" void* fn_125_6FE8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x88;
        fn_125_3B44(member, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
