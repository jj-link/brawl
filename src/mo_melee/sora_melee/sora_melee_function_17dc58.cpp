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

struct ModuleAccessor {
    char padding[0x70];
    StatusModule* status;
};

struct Object {
    char padding[0xD8];
    ModuleAccessor* modules;
};

class Callback {
public:
    virtual void slot00();
    virtual void invoke(Object*);
};

extern "C" Callback lbl_27_bss_4964;

inline void invokeCallback(Callback* callback, Object* object) {
    callback->invoke(object);
}

extern "C" void fn_27_17DC58(void*, Object* object) {
    switch (object->modules->status->getStatus()) {
    case 0xA1:
    case 0xA2:
        invokeCallback(&lbl_27_bss_4964, object);
        break;
    }
}
