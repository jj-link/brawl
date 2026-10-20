#pragma force_active on
extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_113_29430(void*, short);
extern "C" void fn_113_344C(void*, short);
extern "C" void __dl__FPv(void*);

void operator delete(void*);

extern "C" void* fn_113_293AC(void* object, short deleting) {
    if (object != 0) {
        fn_27_13C90(static_cast<char*>(object) + 0x104, -1);
        fn_27_21038(static_cast<char*>(object) + 0xF0, -1);
        fn_113_29430(static_cast<char*>(object) + 0x88, -1);
        fn_113_344C(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
