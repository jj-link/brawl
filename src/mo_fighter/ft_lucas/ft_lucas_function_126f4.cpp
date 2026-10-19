#include <types.h>
#pragma force_active on

extern "C" void* getData__20ftCommonDataAccesserCF6ftKind(const void* accesser, int kind);
extern "C" const float lbl_114_rodata_A8;
extern "C" unsigned char g_ftCommonDataAccesser;

class LucasView {
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
    virtual void unk(int);
};

extern "C" void fn_114_126F4(void* param1, void* object, int kind) {
    if (kind == 0x10) {
        void* data = getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 0x1a);
        float value = *reinterpret_cast<float*>(*reinterpret_cast<u32*>(static_cast<char*>(data) + 0x84) + 0x2c);
        if (value > lbl_114_rodata_A8) {
            LucasView* view = *reinterpret_cast<LucasView**>(static_cast<char*>(*reinterpret_cast<void**>(static_cast<char*>(object) + 0xd8)) + 0x64);
            view->unk(0x11000000);
        }
    }
}
