#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_C644(void*, short);

extern "C" void* fn_116_C6A4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        fn_116_C644(member + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
