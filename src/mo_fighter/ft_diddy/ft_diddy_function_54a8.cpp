#pragma force_active on
void operator delete(void*);
extern "C" void fn_115_5514(void*, short);
extern "C" void fn_115_3C8C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_54A8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_5514(storage + 0x24, -1);
        fn_115_3C8C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
