#pragma force_active on
void operator delete(void*);
extern "C" void fn_105_1EEC(void*, short);
extern "C" void fn_105_1F48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_4228(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        fn_105_1EEC(storage + 0x14, 0);
        fn_105_1F48(storage + 8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
