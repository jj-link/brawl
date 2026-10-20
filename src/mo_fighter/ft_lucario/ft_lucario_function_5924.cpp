#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_118_599C(void*, short);

extern "C" void* fn_118_5924(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xF0, -1);
        if (object != 0) {
            fn_118_599C(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
