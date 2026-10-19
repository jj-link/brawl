#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_4EB8(void*, short);
extern "C" void* fn_116_52A0(void*, short);

extern "C" void* fn_116_4E4C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_4EB8(storage + 0x44B4, -1);
        fn_116_52A0(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
