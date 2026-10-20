#pragma force_active on
extern "C" void* fn_115_3BAC(void*, short);
extern "C" void* fn_115_62AC(void*, short);
extern "C" void* fn_27_CD934(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_6234(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_3BAC(storage + 0xAC, -1);
        fn_115_62AC(storage + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
