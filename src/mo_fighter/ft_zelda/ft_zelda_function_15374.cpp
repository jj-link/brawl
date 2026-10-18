#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_3F88(void*, short);
extern "C" void* fn_104_400C(void*, short);
extern "C" void* fn_104_5164(void*, short);
extern "C" void* fn_104_406C(void*, short);
extern "C" void* fn_104_15410(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_104_15374(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_104_3F88(storage + 0x114, destroy);
        fn_104_400C(storage + 0x100, destroy);
        fn_104_5164(storage + 0xf0, destroy);
        fn_104_406C(storage + 0x4c, destroy);
        fn_104_15410(storage + 0x10, destroy);
        fn_27_C74E8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
