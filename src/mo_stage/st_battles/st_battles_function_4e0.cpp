#pragma force_active on
typedef void (*Destructor)(void *);
struct DestructorChain;

extern "C" void __ct__11stClassInfoFv(void *);
extern "C" void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void *, int, void *);
extern "C" void __register_global_object(void *, Destructor, struct DestructorChain *);
extern "C" unsigned char lbl_42_data_358[];
extern "C" unsigned char lbl_42_bss_8[];
extern "C" unsigned char lbl_42_bss_14[];
extern "C" void fn_42_544(void *);

extern "C" void fn_42_4E0(void) {
    __ct__11stClassInfoFv(lbl_42_bss_14);

    void *data = lbl_42_data_358;
    *(void **)lbl_42_bss_14 = data;

    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        lbl_42_bss_14, 0x41, lbl_42_bss_14);

    __register_global_object(
        lbl_42_bss_14, (Destructor)fn_42_544,
        (DestructorChain *)lbl_42_bss_8);
}

__declspec(section ".ctors") extern void* const fn_42_4E0_ctor = (void*)fn_42_4E0;
