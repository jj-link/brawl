#pragma force_active on
void operator delete(void*);
extern "C" void* fn_101_817C(void*, short);
extern "C" void* fn_101_4364(void*, short);

extern "C" void* fn_101_8110(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_101_817C(static_cast<unsigned char*>(object) + 0x24, memberDeleting);
        fn_101_4364(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
