#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C6A4(void*, short);

extern "C" void* fn_116_1E944(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_4B53C(storage + 0x1d8, -1);
        fn_27_19C6A4(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
