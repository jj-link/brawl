#pragma force_active on
extern "C" {
void* __dt__19soPostureModuleImplFv(void*, short);
void* fn_27_19FFEC(void*, short);
}

extern "C" void* fn_99_40D0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        __dt__19soPostureModuleImplFv(storage + 0x3C, destroyMember);
        if (object) fn_27_19FFEC(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
