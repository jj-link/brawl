#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_104_1F30(void*, short);
void fn_104_1F8C(void*, short);
}

extern "C" void* fn_104_1EB0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        char* sub = storage + 0x20;
        if (sub != 0) {
            fn_27_57BA0(sub, 0);
        }
        fn_104_1F30(storage + 0x14, 0);
        fn_104_1F8C(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
