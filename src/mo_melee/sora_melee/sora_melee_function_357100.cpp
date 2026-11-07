#include <types.h>
#pragma force_active on

class Obj70 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int getStatus(void*);
};

class Obj64 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int getInt(u32);
    virtual void setInt(int, u32);
};

class Obj5c {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual int getButtons();
};

class Obj8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void setFloat(float);
};

extern "C" int fn_27_30FACC(void*, unsigned int, int, void*, unsigned int);
extern "C" float fn_27_192278(void*, unsigned long);
extern "C" unsigned char lbl_27_bss_7B0C[];
extern "C" u32 getButtonMask__12soControllerFQ212soController9PadButton(int);
extern float lbl_27_rodata_79A0;

extern "C" void fn_27_357100(void*, void* accesser) {
    void* modules = *(void**)((char*)accesser + 0xd8);
    Obj70* obj70 = *(Obj70**)((char*)modules + 0x70);
    
    int status = obj70->getStatus(accesser);
    int result = fn_27_30FACC(lbl_27_bss_7B0C, 0, status, accesser, 1);
    
    if (result != 0x119) {
        modules = *(void**)((char*)accesser + 0xd8);
        Obj64* obj64 = *(Obj64**)((char*)modules + 0x64);
        Obj5c* obj5c = *(Obj5c**)((char*)modules + 0x5c);
        Obj8* obj8 = *(Obj8**)((char*)modules + 0x8);
        
        int counter = obj64->getInt(0x20000004) - 1;
        int triggered = 0;
        
        u32 mask1 = getButtonMask__12soControllerFQ212soController9PadButton(1);
        u32 buttons = obj5c->getButtons();
        if ((buttons & mask1) != 0 ||
            (obj5c->getButtons() &
             getButtonMask__12soControllerFQ212soController9PadButton(0)) != 0)
            triggered = 1;
        
        if (triggered != 0) {
            counter = (int)fn_27_192278(accesser, 0xfa3);
            obj8->setFloat(fn_27_192278(accesser, 0xfa2));
        }
        
        if (counter <= 0) {
            obj8->setFloat(lbl_27_rodata_79A0);
        }
        
        obj64->setInt(counter, 0x20000004);
    }
}