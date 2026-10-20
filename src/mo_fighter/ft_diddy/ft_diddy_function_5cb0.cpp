#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);

void operator delete(void*);

extern "C" void* fn_115_5CB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x61C, -1);
        fn_27_1A12AC(storage + 0x540, -1);
        fn_27_CB998(storage + 0x2DC, -1);
        fn_27_CD1F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
