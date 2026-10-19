#pragma force_active on
void operator delete(void*);
extern "C" void fn_112_1F4C(void*, short);
extern "C" void fn_112_1FA8(void*, short);

extern "C" void* fn_112_4B3C(void* object, short deleting) {
    if (object != 0) {
        fn_112_1F4C(static_cast<char*>(object) + 0x14, 0);
        fn_112_1FA8(static_cast<char*>(object) + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
