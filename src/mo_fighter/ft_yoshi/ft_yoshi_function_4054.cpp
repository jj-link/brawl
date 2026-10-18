#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_40B4(void*, short);

extern "C" void* fn_95_4054(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0xC;
        fn_95_40B4(member, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
