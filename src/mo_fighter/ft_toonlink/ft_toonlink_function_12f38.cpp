#pragma force_active on
void operator delete(void*);
extern "C" void* fn_121_2CE0(void*, short);
extern "C" void* fn_121_12EDC(void*, short);
extern "C" void* fn_27_CD934(void*, short);

extern "C" void* fn_121_12F38(void* object, short deleting) {
    if (object != 0) {
        fn_121_2CE0(static_cast<unsigned char*>(object) + 0x8C, -1);
        fn_121_12EDC(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
