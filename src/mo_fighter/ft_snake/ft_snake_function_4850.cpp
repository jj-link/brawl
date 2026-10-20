#pragma force_active on
extern "C" void* fn_27_B5324(void*, short);
extern "C" void* fn_122_48DC(void*, short);
extern "C" void __dl__FPv(void*);

void operator delete(void*);

extern "C" void* fn_122_4850(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_B5324(storage + 0x20, -1);
        if (storage + 0x10 != 0) {
            fn_122_48DC(storage + 0x10, 0);
        }
        if (object != 0) {
            fn_122_48DC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
