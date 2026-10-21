#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_41_28F74(void*, unsigned int, unsigned int);
void fn_41_B8D4(void*, void*, void*, void*, void*);
}

extern char lbl_41_data_5720[];
extern char __RTTI__11StageObject[];

class ModuleSlots {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual int get();
    virtual void set(int, bool);
};

struct Event {
    int kind;
    bool handled;
};

extern "C" void fn_41_57768(
    char* self, Event* event, char* accesser, void* object, void* arg
) {
    switch (event->kind) {
    case 0x13F7: {
        short one = 1;
        char* enemy = (char*)__dynamic_cast(
            object, 0x3C, lbl_41_data_5720, __RTTI__11StageObject, one
        );
        char* otherAccesser = *(char**)(enemy + 0x6C);
        ModuleSlots* other =
            *(ModuleSlots**)(*(char**)(otherAccesser + 0xD8) + 0x44);
        int value = other->get();
        ModuleSlots* module =
            *(ModuleSlots**)(*(char**)(accesser + 0xD8) + 0x44);
        module->set(value, true);
        event->handled = one;
        break;
    }
    case 0x13FF:
        fn_41_28F74(self + 0x1108, 1, 0x2D);
        event->handled = true;
        break;
    }
    fn_41_B8D4(self, event, accesser, object, arg);
}
