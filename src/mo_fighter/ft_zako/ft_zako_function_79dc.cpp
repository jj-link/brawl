#pragma force_active on
void operator delete(void*);

extern "C" void fn_126_8790(void*, short);

extern "C" void* fn_126_79DC(void* object, short deleting) {
    if (object != 0) {
        fn_126_8790(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
