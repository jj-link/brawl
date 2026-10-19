#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_102_1AD5C(void* p, short flag);

extern "C" void* fn_102_1ACF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0xC, -1);
        fn_102_1AD5C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
