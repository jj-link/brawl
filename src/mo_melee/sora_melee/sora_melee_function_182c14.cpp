#include <types.h>
#include <so/so_value_accesser.h>
#include <so/controller/so_controller_impl.h>
#pragma force_active on

class ControllerValues {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual u8 getValue(float);
    virtual void slot5c();
    virtual u8 getValue2();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual int getButtons();
};

class IntegerModule {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual int getInt(u32);
    virtual void setInt(int, u32);
};

class FloatModule {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void setFloat(float);
};

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);
extern "C" u32 getButtonMask__12soControllerFQ212soController9PadButton(int);
extern float lbl_27_rodata_2460;

extern "C" void fn_27_182C14(void*, void* accesser) {
    char* modules = *(char**)((char*)accesser + 0xd8);
    IntegerModule* integerModule = *(IntegerModule**)(modules + 0x64);
    FloatModule* floatModule = *(FloatModule**)(modules + 0x08);
    ControllerValues* controller = *(ControllerValues**)(modules + 0x5c);

    int threshold =
        getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x5a52, 0);
    float value =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x0d34, 0);

    int triggered = 0;
    if ((controller->getValue(value) & 0xff) < threshold)
        triggered = 1;
    if ((controller->getValue2() & 0xff) < threshold)
        triggered = 1;

    int buttonTriggered = 0;
    int mask = getButtonMask__12soControllerFQ212soController9PadButton(1);
    u32 buttons = controller->getButtons();
    if ((buttons & mask) != 0 ||
        (controller->getButtons() &
         getButtonMask__12soControllerFQ212soController9PadButton(0)) != 0)
        buttonTriggered = 1;

    int counter = integerModule->getInt(0x20000001) - 1;
    if (triggered || buttonTriggered) {
        counter = (int)getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x0d33, 0);
        floatModule->setFloat(
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0x0d32, 0));
    }

    if (counter <= 0)
        floatModule->setFloat(lbl_27_rodata_2460);

    integerModule->setInt(counter, 0x20000001);
}
