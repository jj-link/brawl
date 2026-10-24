#pragma force_active on
struct Registration {
    void* next;
    void* destructor;
    void* object;
};

struct ToonLinkGlobals {
    Registration registration1;
    unsigned char object1[4];
    Registration registration2;
    unsigned char object2[4];
    Registration registration3;
    unsigned char object3[4];
};

#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern ToonLinkGlobals lbl_121_bss_180;

void* fn_121_10F78(void*);
void* fn_121_10F88(void*);
void* fn_121_10F98(void*);

void* fn_121_10EB8(void*, short);
void* fn_121_10E78(void*, short);
void* fn_121_10E38(void*, unsigned short);

void* __register_global_object(void*, void*, void*);

void fn_121_10EF8() {
    ToonLinkGlobals* base = &lbl_121_bss_180;
    Registration (ToonLinkGlobals::*reg) = &ToonLinkGlobals::registration1;

    fn_121_10F78(base->object1);
    __register_global_object(base->object1, fn_121_10EB8, &(base->*reg));

    fn_121_10F88(base->object2);
    __register_global_object(base->object2, fn_121_10E78, &base->registration2);

    fn_121_10F98(base->object3);
    __register_global_object(base->object3, fn_121_10E38, &base->registration3);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_121_10EF8_ctor = (void*)fn_121_10EF8;
