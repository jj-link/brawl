#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_95_67D4(void*, short);

extern "C" void* fn_95_675C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A18A0(storage + 0x354, -1);
        if (object != 0) {
            fn_95_67D4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
