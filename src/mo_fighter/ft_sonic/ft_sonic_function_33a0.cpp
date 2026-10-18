#pragma force_active on
void operator delete(void*);

extern "C" void fn_123_3400(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_33A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* member = static_cast<unsigned char*>(object);
        fn_123_3400(member + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
