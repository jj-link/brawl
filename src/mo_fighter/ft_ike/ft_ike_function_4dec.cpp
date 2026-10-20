#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);

void operator delete(void*);

extern "C" void* fn_119_4DEC(void* object, short deleting) {
    if (object != 0) {
        __dt__27soCollisionAttackModuleImplFv(static_cast<unsigned char*>(object) + 0x61C, -1);
        fn_27_1A12AC(static_cast<unsigned char*>(object) + 0x540, -1);
        fn_27_CB998(static_cast<unsigned char*>(object) + 0x2DC, -1);
        fn_27_CD1F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
