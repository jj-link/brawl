#pragma force_active on
extern "C" void* fn_27_75E0C(void*, short);
extern "C" void* fn_27_64930(void*, short);
extern "C" void* fn_99_1E40(void*, short);

extern "C" void* fn_99_3DA8(void* object, short deleting) {
    if (object) {
        fn_27_75E0C(static_cast<char*>(object) + 0x4C, -1);
        if (static_cast<char*>(object) + 0x20) {
            fn_27_64930(static_cast<char*>(object) + 0x20, 0);
        }
        fn_99_1E40(static_cast<char*>(object) + 0x14, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
