#pragma force_active on
extern "C" void fn_27_4B53C(void*, short);
extern "C" void fn_27_19C45C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_7640(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_4B53C(storage + 0x17C, -1);
        fn_27_19C45C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
