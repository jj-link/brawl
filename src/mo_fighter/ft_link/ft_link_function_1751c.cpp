#pragma force_active on
void operator delete(void*);

extern "C" void fn_93_5FA8(void*, short);

extern "C" void* fn_93_1751C(void* object, short deleting) {
    if (object != 0) {
        fn_93_5FA8(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
