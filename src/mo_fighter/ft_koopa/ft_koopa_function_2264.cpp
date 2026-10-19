#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_22D0(void*, short);
extern "C" void* fn_102_212C(void*, short);

extern "C" void* fn_102_2264(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_102_22D0(storage + 0x50, -1);
        fn_102_212C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
