#pragma force_active on
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" int fn_27_68140(float, float, float, float, float);
extern "C" float lbl_112_rodata_28[];

class Vt {
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
    virtual void v10(float value);
    virtual void v11();
    virtual void v12();
    virtual void v13(float value, unsigned int index);
    virtual void v14();
    virtual void v15();
    virtual int v16();
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
    virtual void v34(int value, soModuleAccesser* moduleAccesser);
};

class VtStop {
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
    virtual void v16(int value, int flag);
};

extern "C" void fn_112_10F08(void* arg0, float* arg1, void* arg2, soModuleAccesser* arg3) {
    float* k = lbl_112_rodata_28;
    int state = reinterpret_cast<Vt*>(arg3->m_enumerationStart->m_statusModule)->v16();
    switch (state) {
    case 2:
    case 3:
        if (arg1[0] >= soValueAccesser::getConstantFloat(arg3, 0xfaa, 0)) {
            soModuleAccesser* owner = *(soModuleAccesser**)((char*)arg0 + 0x60);
            reinterpret_cast<Vt*>(owner->m_enumerationStart->m_workManageModule)->v13(-arg1[31], 0x11000001);
            reinterpret_cast<Vt*>(arg3->m_enumerationStart->m_postureModule)->v10(arg1[31]);
            reinterpret_cast<Vt*>(arg3->m_enumerationStart->m_statusModule)->v34(4, arg3);
        }
        if (arg1[3] > k[5]) {
            reinterpret_cast<VtStop*>(arg3->m_enumerationStart->m_stopModule)->v16(
                fn_27_68140(arg1[2], k[7], k[8], k[3], k[9]), 1);
        }
        break;
    }
}
