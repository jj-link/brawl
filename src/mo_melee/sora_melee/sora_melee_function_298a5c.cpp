#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_46DC;

class soVtblBase {
public:
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
    virtual int v23();
};

extern "C" void fn_27_298A5C(int a, u8* b, u8* c, u32 d)
{
    if (d & 1) {
        u8* p = *(u8**)(b + 0x60);
        p = *(u8**)(p + 0xd8);
        soVtblBase* o = *(soVtblBase**)(p + 0x8);
        int r = o->v23();
        if ((r >= 12 && r <= 16) || r == 11) {
            *(float*)(c + 4) = lbl_27_rodata_46DC;
        }
    }
}
