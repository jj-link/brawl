#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_92_3AA4(void*, short);
void* fn_92_3B00(void*, short);
void* fn_92_1203C(void*, short);
void* fn_92_3B5C(void*, short);
void* fn_92_3BE8(void*, short);
void* fn_92_3CE4(void*, short);
void* fn_92_12098(void*, short);
void* fn_92_408C(void*, short);
void* fn_92_41C0(void*, short);
void* fn_92_421C(void*, short);
void* fn_92_4278(void*, short);
void* fn_92_42E4(void*, short);
void* fn_92_4344(void*, short);
void* fn_92_43A4(void*, short);
void* fn_92_12190(void*, short);
void* fn_92_4400(void*, short);
void* fn_92_44CC(void*, short);
void* fn_92_4528(void*, short);
void* fn_92_12270(void*, short);
void* fn_92_4624(void*, short);
void* fn_92_4690(void*, short);
void* fn_92_4748(void*, short);
void* fn_92_4788(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_92_123E0(void*, short);
}

extern "C" void* fn_92_11EBC(unsigned char* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_92_3AA4(object + 0x191C, -1);
        fn_92_3B00(p + 0x1904, -1);
        fn_92_1203C(p + 0x17AC, -1);
        fn_92_3B5C(p + 0x1614, -1);
        fn_92_3BE8(p + 0x15B4, -1);
        fn_92_3CE4(p + 0x1500, -1);
        fn_92_12098(p + 0x1340, -1);
        fn_92_408C(p + 0x129C, -1);
        fn_92_41C0(p + 0x1268, -1);
        fn_92_421C(p + 0x1250, -1);
        fn_92_4278(p + 0x10EC, -1);
        fn_92_42E4(p + 0x1084, -1);
        fn_92_4344(p + 0x1078, -1);
        fn_92_43A4(p + 0x1050, -1);
        fn_92_12190(p + 0x0E80, -1);
        fn_92_4400(p + 0x0E1C, -1);
        fn_92_44CC(p + 0x0DE0, -1);
        fn_92_4528(p + 0x0D28, -1);
        fn_92_12270(p + 0x0B1C, -1);
        fn_92_4624(p + 0x093C, -1);
        fn_92_4690(p + 0x090C, -1);
        fn_92_4748(p + 0x08FC, -1);
        fn_92_4788(p + 0x08E4, -1);
        __dt__16soModuleAccesserFv(p + 0x0804, -1);
        fn_92_123E0(p, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
