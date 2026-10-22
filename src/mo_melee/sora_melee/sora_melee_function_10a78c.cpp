#include <types.h>
#pragma force_active on

extern "C" {
    extern s32 fn_27_1190D0(void*);
    extern void* getEntity__14ftEntryManagerFUl(void*, u32);
    extern s32 getStatusKind__23soExternalValueAccesserFP11StageObject(void*);

    struct P {
        int a;
        char pad[0x38];
    };

    struct Obj : P {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19();
        virtual void v20();
        virtual void v21();
        virtual void v22();
        virtual void v23();
        virtual void v24();
        virtual void v25();
        virtual void v26();
        virtual void v27();
        virtual void v28();
        virtual void v29();
        virtual void v30();
        virtual void v31();
        virtual void v32();
        virtual void v33();
        virtual void v34();
        virtual void v35();
        virtual void v36();
        virtual void v37();
        virtual void v38();
        virtual void v39();
        virtual void v40();
        virtual s32 check();
    };

    s32 fn_27_10A78C(u8* self, u32 arg1) {
        s32 result;
        Obj* acc;
        if (fn_27_1190D0(*(void**)(self + 0x154)) == 0) {
            acc = (Obj*)0;
        } else if (*(s32*)((u8*)getEntity__14ftEntryManagerFUl(*(void**)(self + 0x154), arg1) + 0x5C) == 0x10) {
            acc = *(Obj**)((u8*)getEntity__14ftEntryManagerFUl(*(void**)(self + 0x154), arg1) + 0x3C);
        } else {
            acc = (Obj*)0;
        }
        result = 0;
        if (acc != 0 && acc->check() != 0 && getStatusKind__23soExternalValueAccesserFP11StageObject(acc) == 0x10B) {
            result = 1;
        }
        return result;
    }
}