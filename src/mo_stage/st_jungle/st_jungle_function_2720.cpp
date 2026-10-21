#pragma force_active on
extern "C" {
    typedef struct {
        void* next;
        void* destructor;
        void* object;
    } DestructorChain;

    extern unsigned char lbl_51_bss_8[];
    extern unsigned char lbl_51_bss_14[];

    void __ct__11stClassInfoFv(void* self);
    void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void* self, unsigned int kind, void* info);
    void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
    void fn_51_2784(void* self, unsigned int flag);
}

extern "C" unsigned char lbl_51_data_968[];

extern "C" void fn_51_2720() {
    __ct__11stClassInfoFv(lbl_51_bss_14);
    *(void**)lbl_51_bss_14 = lbl_51_data_968;
    setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(lbl_51_bss_14, 8, lbl_51_bss_14);
    __register_global_object(lbl_51_bss_14, (void*)fn_51_2784, (DestructorChain*)lbl_51_bss_8);
}

__declspec(section ".ctors") extern void* const fn_51_2720_ctor = (void*)fn_51_2720;
