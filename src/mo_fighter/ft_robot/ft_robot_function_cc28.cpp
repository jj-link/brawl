#pragma force_active on
#pragma opt_propagation off
#pragma scheduling off
struct GlobalRegistration {
    void* next;
    void* object;
    void* destructor;
};
struct RobotGlobals {
    GlobalRegistration registration;
    unsigned char parameterStorage[0x230];
    unsigned int value0[2];
    unsigned int value1[2];
    GlobalRegistration classInfoRegistration;
    unsigned char classInfoStorage[0xc];
};

extern "C" {
extern RobotGlobals lbl_120_bss_8;
void* fn_120_CCAC(void*);
void* fn_120_948C(void*, short);
void fn_120_CCF4(unsigned int*, unsigned int, unsigned int);
void* fn_120_CD00(void*);
void* fn_120_CD58(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_120_CC28() {
    GlobalRegistration RobotGlobals::* registration = &RobotGlobals::registration;
    fn_120_CCAC(lbl_120_bss_8.parameterStorage);
    __register_global_object(lbl_120_bss_8.parameterStorage,
                            reinterpret_cast<void*>(fn_120_948C),
                            &(lbl_120_bss_8.*registration));
    fn_120_CCF4(lbl_120_bss_8.value0, 0xff, 0);
    fn_120_CCF4(lbl_120_bss_8.value1, 0xff, 1);
    fn_120_CD00(lbl_120_bss_8.classInfoStorage);
    __register_global_object(lbl_120_bss_8.classInfoStorage,
                            reinterpret_cast<void*>(fn_120_CD58),
                            &lbl_120_bss_8.classInfoRegistration);
}

__declspec(section ".ctors") extern void* const fn_120_CC28_ctor = (void*)fn_120_CC28;
