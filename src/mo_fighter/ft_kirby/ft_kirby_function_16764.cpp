#include <types.h>
#pragma force_active on

struct A {
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
    virtual u32 v16(int);
    virtual void v17();
    virtual void v18();
    virtual u32 v19(int);
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29(int);
};

extern "C" void fn_96_16764(void* unused, u8* obj) {
    if (((A*)*(void**)(*(u8**)(obj + 0xD8) + 0x64))->v19(0x2200001C) == 0) {
        for (int i = 3; i < 7; ++i) {
            if (((A*)*(void**)(*(u8**)(obj + 0xD8) + 0xA8))->v16(i) != 0) {
                ((A*)*(void**)(*(u8**)(obj + 0xD8) + 0xA8))->v29(i);
            }
        }
    }
}
