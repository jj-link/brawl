#pragma force_active on
extern "C" int getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);

struct V {
    virtual void v2();
    virtual int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setA(int);
    virtual void setB(int, int);
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
    virtual void f80(int, int);
    virtual void v33();
    virtual void f88(int, int);
};

extern "C" void fn_41_3D00(char* self) {
    V* o = *(V**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x60);
    if (getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x10000 - 0x57ef, 0)) {
        if (getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x59fb, 0) == 1) {
            o->f80((unsigned char)getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x59f8, 0), -1);
            o->f88((unsigned char)getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(self + 0xdc, 0x59f7, 0), -1);
            o->setA(1);
            int n = o->size();
            for (int i = 0; i < n; i++) {
                if (i == 0) o->setB(1, i);
                else o->setB(0, i);
            }
        }
    }
}
