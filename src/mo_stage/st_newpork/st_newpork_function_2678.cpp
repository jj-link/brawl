#pragma force_active on
extern "C" {
extern unsigned char lbl_69_data_610[];
void setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(void*, int, void*);
void __dt__11stClassInfoFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_69_2678(void* ptr, int flag) {
    if (ptr != 0) {
        *(void**)ptr = lbl_69_data_610;
        setClassInfo__11stClassInfoFQ26Stages11srStageKindP11stClassInfo(ptr, 0x20, 0);
        __dt__11stClassInfoFv(ptr, 0);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
