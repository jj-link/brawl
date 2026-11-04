#pragma force_active on
#include <ft/ft_common_data_accesser.h>
#include <so/controller/so_controller_impl.h>

struct WorkModule {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(int);
};

struct ControlModule {
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
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual int getButtons();
};

struct Modules {
    unsigned char pad[0x5C];
    ControlModule* control;
    unsigned char pad2[4];
    WorkModule* work;
};

struct Object {
    unsigned char pad[0xD8];
    Modules* modules;
};

extern "C" int fn_95_FE54(void* fighter) {
    ControlModule* control;
    unsigned int mask;
    char* data = reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(4)));
    int* params = *reinterpret_cast<int**>(data + 0x7c);
    Object* object = static_cast<Object*>(fighter);
    int value = object->modules->work->getInt(0x20000000);
    if (value < params[0] - params[1]) {
        control = object->modules->control;
        mask = soController::getButtonMask(soController::Pad_Button_Special);
        unsigned int buttons = control->getButtons();
        buttons &= mask;
        if (buttons) {
            return 1;
        }
    }
    return 0;
}
