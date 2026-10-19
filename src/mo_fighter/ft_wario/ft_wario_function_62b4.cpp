#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);

extern "C" void* fn_110_62B4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_4B53C(storage + 0x17C, -1);
        fn_27_19C45C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
