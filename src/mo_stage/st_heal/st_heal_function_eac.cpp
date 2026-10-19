#pragma force_active on
extern "C" void* fn_87_EAC(void* object, int shouldDelete) {
    extern void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
        void*, int, void*);
    extern void __dt__11stClassInfoFv(void*, int);
    extern void __dl__FPv(void*);
    extern unsigned char lbl_87_data_3F0[];

    if (object) {
        *static_cast<void**>(object) = lbl_87_data_3F0;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(
            object, 0x36, 0);
        __dt__11stClassInfoFv(object, 0);
        if (shouldDelete > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
