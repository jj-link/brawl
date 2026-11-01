#pragma force_active on
#pragma push
#pragma opt_propagation off
#pragma scheduling off

struct StGhostFootData;

struct GanonGlobals {
    unsigned char registration[0xC];
    void* object;
    unsigned char ghostRegistration[0xC];
    const StGhostFootData* ghostObject;
};

extern "C" {
extern GanonGlobals lbl_109_bss_1A8;
void* fn_109_DA40(void**);
void fn_109_DA50(const StGhostFootData**);
void* fn_109_D99C(void*, short);
void* fn_109_D95C(void*, short);
void* __register_global_object(void*, void* (*)(void*, short), void*);
}

extern "C" void fn_109_D9DC() {
    GanonGlobals* g = &lbl_109_bss_1A8;
    unsigned char (GanonGlobals::*chain)[0xC] = &GanonGlobals::registration;
    fn_109_DA40(&g->object);
    __register_global_object(&g->object, fn_109_D99C, &(g->*chain));
    fn_109_DA50(&g->ghostObject);
    __register_global_object(&g->ghostObject, fn_109_D95C, g->ghostRegistration);
}

#pragma pop

__declspec(section ".ctors") extern void* const fn_109_D9DC_ctor = (void*)fn_109_D9DC;
