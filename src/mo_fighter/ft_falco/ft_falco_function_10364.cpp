#pragma force_active on
void operator delete(void*);
extern "C" void* fn_108_3C2C(void* object, short deleting);
extern "C" void* fn_108_3CB0(void* object, short deleting);
extern "C" void* fn_108_10400(void* object, short deleting);
extern "C" void* fn_108_3D10(void* object, short deleting);
extern "C" void* fn_108_3E38(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_108_10364(void* object, short deleting) {
    if (object != 0) {
        char* p = static_cast<char*>(object);
        short d = -1;
        fn_108_3C2C(p + 0x118, d);
        fn_108_3CB0(p + 0x104, d);
        fn_108_10400(p + 0xEC, d);
        fn_108_3D10(p + 0x48, d);
        fn_108_3E38(p + 0x10, d);
        fn_27_C74E8(object, d);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
