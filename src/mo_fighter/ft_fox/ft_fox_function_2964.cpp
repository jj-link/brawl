#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_97_2C04(void*, short);
void* fn_97_2C60(void*, short);
void* fn_97_2CBC(void*, short);
void* fn_97_2D18(void*, short);
void* fn_97_2D74(void*, short);
void* fn_97_2DD0(void*, short);
void* fn_97_2EAC(void*, short);
void* fn_97_2F08(void*, short);
void* fn_97_2F64(void*, short);
void* fn_97_2FD8(void*, short);
void* fn_97_3070(void*, short);
void* fn_97_30CC(void*, short);
void* fn_97_321C(void*, short);
void* fn_97_64D8(void*, short);
void* fn_97_6538(void*, short);
void* fn_97_65B0(void*, short);
void* fn_97_7120(void*, short);
void* fn_97_40FC(void*, short);
void* fn_97_71FC(void*, short);
void* fn_97_7270(void*, short);
void* fn_97_734C(void*, short);
void* fn_97_73A8(void*, short);
void* fn_97_7414(void*, short);
void* fn_97_74C0(void*, short);
void* fn_97_7534(void*, short);
void* fn_97_7590(void*, short);
void* fn_97_75EC(void*, short);
void* fn_97_7648(void*, short);
void* fn_97_76A4(void*, short);
void* fn_97_7718(void*, short);
void* fn_97_7784(void*, short);
void* fn_97_7814(void*, short);
void* fn_97_78A4(void*, short);
void* fn_97_7928(void*, short);
void* fn_97_79AC(void*, short);
void* fn_97_4408(void*, short);
void* fn_97_4F3C(void*, short);
void* fn_97_4464(void*, short);
void* fn_97_7AE0(void*, short);
void* fn_97_7D14(void*, short);
void* fn_97_7DE8(void*, short);
void* fn_97_7E60(void*, short);
void* fn_97_4720(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_97_7EBC(void*, short);
}

extern "C" void* fn_97_2964(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_97_2C04(storage + 0x1AE8C, destroy);
        fn_97_2C60(storage + 0x1AE50, destroy);
        fn_97_2CBC(storage + 0x1ADE8, destroy);
        fn_97_2D18(storage + 0x1AD9C, destroy);
        fn_97_2D74(storage + 0x1AC48, destroy);
        fn_97_2DD0(storage + 0x1AB38, destroy);
        fn_97_2EAC(storage + 0x1AAF0, destroy);
        fn_97_2F08(storage + 0x1AA70, destroy);
        fn_97_2F64(storage + 0x1A9AC, destroy);
        fn_97_2FD8(storage + 0x1A638, destroy);
        fn_97_3070(storage + 0x1A608, destroy);
        fn_97_30CC(storage + 0x1A464, destroy);
        fn_97_321C(storage + 0x5794, destroy);
        fn_97_64D8(storage + 0x55B0, destroy);
        fn_97_6538(storage + 0x52A8, destroy);
        fn_97_65B0(storage + 0x4428, destroy);
        fn_97_7120(storage + 0x4334, destroy);
        fn_97_40FC(storage + 0x4300, destroy);
        fn_97_71FC(storage + 0x428C, destroy);
        fn_97_7270(storage + 0x3B68, destroy);
        fn_97_734C(storage + 0x3B38, destroy);
        fn_97_73A8(storage + 0x396C, destroy);
        fn_97_7414(storage + 0x38FC, destroy);
        fn_97_74C0(storage + 0x3864, destroy);
        fn_97_7534(storage + 0x382C, destroy);
        fn_97_7590(storage + 0x3808, destroy);
        fn_97_75EC(storage + 0x37D4, destroy);
        fn_97_7648(storage + 0x3770, destroy);
        fn_97_76A4(storage + 0x35C0, destroy);
        fn_97_7718(storage + 0x335C, destroy);
        fn_97_7784(storage + 0x29A0, destroy);
        fn_97_7814(storage + 0x2788, destroy);
        fn_97_78A4(storage + 0x2104, destroy);
        fn_97_7928(storage + 0x1A48, destroy);
        fn_97_79AC(storage + 0x19D4, destroy);
        fn_97_4408(storage + 0x1998, destroy);
        fn_97_4F3C(storage + 0x18F0, destroy);
        fn_97_4464(storage + 0x183C, destroy);
        fn_97_7AE0(storage + 0x14A8, destroy);
        fn_97_7D14(storage + 0x1180, destroy);
        fn_97_7DE8(storage + 0x115C, destroy);
        fn_97_7E60(storage + 0x0AC8, destroy);
        fn_97_4720(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_97_7EBC(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
