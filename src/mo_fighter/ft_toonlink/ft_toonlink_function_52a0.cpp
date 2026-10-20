#pragma force_active on
extern "C" void* fn_121_5228(void*, short);
extern "C" void* fn_27_1A1CFC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_121_52A0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_1A1CFC(p + 0x524, -1);
        if (object != 0) {
            fn_121_5228(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
