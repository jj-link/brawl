#pragma force_active on
extern "C" void* __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_82AD4(void*, short);
extern "C" void* fn_27_19958C(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);

void operator delete(void*);

extern "C" void* fn_120_17800(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        __dt__27soCollisionAttackModuleImplFv(storage + 0x454, -1);
        fn_27_82AD4(storage + 0x450, -1);
        fn_27_19958C(storage + 0x2dc, -1);
        fn_27_CD1F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
