#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
};

struct Modules {
    char pad[0x64];
    Object_vptr_0* posture;
};

struct soValueAccesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
void fn_109_D00C(void*, float, float);
}

extern "C" void fn_109_CEE0(soValueAccesser* arg0) {
    Object_vptr_0* obj = arg0->modules->posture;
    int state = obj->slot4(0x20000003);
    if (state != obj->slot4(0x20000004)) {
        bool doIt = true;
        float f1;
        float f2;
        switch (state) {
        case 1:
            f1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg0, 0xfa9, 0);
            f2 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg0, 0xfaa, 0);
            break;
        case 2:
            f1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg0, 0xfab, 0);
            f2 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg0, 0xfac, 0);
            break;
        default:
            doIt = false;
            break;
        }
        if (doIt) {
            fn_109_D00C(arg0, f1, f2);
        }
        obj->slot5(state, 0x20000004);
    }
}
