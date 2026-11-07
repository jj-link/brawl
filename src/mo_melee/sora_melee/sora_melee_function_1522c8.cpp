#pragma force_active on
#include <types.h>
#include <so/so_value_accesser.h>

extern "C" void* g_ftManager;

class ValueObj {
public:
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
    virtual u32 v17(u32 arg);
};

extern "C" float fn_27_1522C8(void* unused, soValueAccesser* self, float f) {
    float result = f;
    u32 flag = ((unsigned char*)g_ftManager)[0x6d] != 0;
    if (flag == 1) {
        ValueObj* obj = *(ValueObj**)((char*)*(void**)((char*)self + 0xd8) + 0x64);
        if (obj->v17(0x12000018) == 1) {
            result = (float)soValueAccesser::getConstantInt((soModuleAccesser*)self, 0x5a4d, 0);
        } else {
            result = (float)soValueAccesser::getConstantInt((soModuleAccesser*)self, 0x5a4c, 0);
        }
    }
    return result;
}
