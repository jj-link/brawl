#include <types.h>
#pragma force_active on

class fnVirtBase {
public:
    virtual u32 v0();
    virtual u32 v1();
    virtual u32 v2();
    virtual u32 v3();
    virtual u32 v4();
    virtual u32 v5();
    virtual u32 v6();
    virtual u32 v7();
    virtual u32 v8();
    virtual u32 v9();
    virtual u32 v10();
    virtual u32 v11();
    virtual u32 v12();
    virtual u32 v13();
    virtual u32 v14();
    virtual u32 v15();
    virtual u32 v16();
    virtual u32 v17();
    virtual u32 v18();
    virtual u32 v19();
    virtual u32 v20();
    virtual u32 v21();
};

extern "C" u32 fn_27_DA204(fnVirtBase* self) {
    fnVirtBase* obj = *(fnVirtBase**)((u32)self + 8);
    return obj->v19();
}
