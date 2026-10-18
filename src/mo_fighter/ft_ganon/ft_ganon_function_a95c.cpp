#pragma force_active on
void operator delete(void*);

extern "C" void fn_109_A8FC(void*, short);

extern "C" void* fn_109_A95C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        fn_109_A8FC(member + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
