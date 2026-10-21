#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
void* fn_104_17CE4(void*, short);
void __dl__FPv(void*);

void* fn_104_17C5C(void* object, short deleting) {
    if (object != 0) {
        short destroy = -1;
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_93100(storage + 0x17640, destroy);
        fn_104_17CE4(storage + 0x7c, destroy);
        fn_27_19F4C4(storage + 0x20, destroy);
        fn_27_1A55B0(object, destroy);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
}
