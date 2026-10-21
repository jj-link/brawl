#pragma force_active on
void operator delete(void*);

extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_104_3270(void*, short);
extern "C" void* fn_27_19F4C4(void*, short);
extern "C" void* fn_27_1A55B0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_31E8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_27_93100(storage + 0xFF04, -1);
        fn_104_3270(storage + 0x7C, -1);
        fn_27_19F4C4(storage + 0x20, -1);
        fn_27_1A55B0(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
