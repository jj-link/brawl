#pragma force_active on
extern "C" {
void* fn_27_93100(void*, short);
void* fn_96_9750(void*, short);
void* fn_27_19ECCC(void*, short);
void* fn_27_1A4F98(void*, short);

void* fn_96_97AC(void* object, short deleting) {
    if (object != 0) {
        fn_27_93100(static_cast<unsigned char*>(object) + 0x12934, static_cast<short>(-1));
        fn_96_9750(static_cast<unsigned char*>(object) + 0x108, static_cast<short>(-1));
        fn_27_19ECCC(static_cast<unsigned char*>(object) + 0x3c, static_cast<short>(-1));
        fn_27_1A4F98(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
