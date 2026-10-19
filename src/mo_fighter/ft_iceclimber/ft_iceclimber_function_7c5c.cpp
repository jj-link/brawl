#pragma force_active on
void operator delete(void*);

extern "C" void* fn_105_7CB8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_7C5C(void* object, short deleting) {
    if (object != 0) {
        fn_105_7CB8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
