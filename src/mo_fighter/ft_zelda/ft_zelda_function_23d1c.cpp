#pragma force_active on
void operator delete(void*);

extern "C" void* fn_104_3DB0(void*, short);

extern "C" void* fn_104_23D1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object) + 0x1C;
        fn_104_3DB0(member, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
