#pragma force_active on
#include <types.h>

extern "C" {
    s32 fn_80325BE4();
    void fn_80325BB0(void*);
    void fn_80325BD0(void*);

    extern char lbl_80414568[];

    typedef struct {
        void* unk0;
        void* unk4;
        void* unk8;
        s32 unkC;
    } HavokStruct;

    extern HavokStruct lbl_805332F0;

    void fn_80325F8C() {
        s32 val = fn_80325BE4();
        lbl_805332F0.unk0 = &lbl_80414568;
        lbl_805332F0.unk4 = (void*)&fn_80325BB0;
        lbl_805332F0.unk8 = (void*)&fn_80325BD0;
        lbl_805332F0.unkC = val;
    }
}

__declspec(section ".ctors") extern void* const fn_80325F8C_ctor = (void*)fn_80325F8C;
