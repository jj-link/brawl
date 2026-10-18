#pragma force_active on
void operator delete(void*);

extern "C" void fn_104_3480(void*, short);

extern "C" void* fn_104_4BEC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        fn_104_3480(member + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
