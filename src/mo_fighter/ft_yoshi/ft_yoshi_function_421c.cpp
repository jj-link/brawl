#pragma force_active on
void operator delete(void*);
extern "C" void fn_95_2040(void*, short);
extern "C" void* fn_95_209C(void*, short);

extern "C" void* fn_95_421C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short zero = 0;
        fn_95_2040(storage + 0x14, zero);
        fn_95_209C(storage + 0x8, zero);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
