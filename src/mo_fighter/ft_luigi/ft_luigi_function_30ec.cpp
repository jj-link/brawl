#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_99_3170(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
}

extern "C" void* fn_99_30EC(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroying = -1;
        fn_27_93100(storage + 0x5FC4, destroying);
        fn_99_3170(storage + 0x7C, destroying);
        fn_27_19F4C4(storage + 0x20, destroying);
        fn_27_1A55B0(object, destroying);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
