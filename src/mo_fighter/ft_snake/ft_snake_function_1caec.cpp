#pragma force_active on
void operator delete(void*);
extern "C" void fn_122_1CB5C(void*, short);
extern "C" void fn_122_1CC78(void*, short);

extern "C" void* fn_122_1CAEC(void* object, short deleting) {
    if (object != 0) {
        fn_122_1CB5C(static_cast<unsigned char*>(object) + 0x1B18, -1);
        fn_122_1CC78(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
