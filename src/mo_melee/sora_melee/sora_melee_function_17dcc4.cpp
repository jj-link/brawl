#pragma force_active on

class StatusModule {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int getStatus();
};

class ControllerModule {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void set(int, float, int);
};

struct ModuleAccessor {
    char padding[0x70];
    StatusModule* status;
    char padding2[0x34];
    ControllerModule* controller;
};

struct Object {
    char padding[0xD8];
    ModuleAccessor* modules;
};

class Callback {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void invoke(Object*, int);
};

extern "C" Callback lbl_27_bss_4964;
extern "C" const float lbl_27_rodata_23A8[];

inline void invokeCallback(Callback* callback, Object* object, int id) {
    callback->invoke(object, id);
}

extern "C" void fn_27_17DCC4(void*, Object* object, int id) {
    switch (object->modules->status->getStatus()) {
    case 0xA1:
    case 0xA2:
        invokeCallback(&lbl_27_bss_4964, object, id);
        break;
    }
    object->modules->controller->set(5, lbl_27_rodata_23A8[0], 0);
}