#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_104_3F88(void*, short);
void* fn_104_400C(void*, short);
void* fn_104_199C0(void*, short);
void* fn_104_5CF8(void*, short);
void* fn_104_6710(void*, short);
void* fn_27_C74E8(void*, short);
}

extern "C" void* fn_104_19924(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_104_3F88(storage + 0xe0c, destroy);
        fn_104_400C(storage + 0xdf8, destroy);
        fn_104_199C0(storage + 0x970, destroy);
        fn_104_5CF8(storage + 0xfc, destroy);
        fn_104_6710(storage + 0x10, destroy);
        fn_27_C74E8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
