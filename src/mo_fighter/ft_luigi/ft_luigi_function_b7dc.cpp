#pragma force_active on
struct soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiObserver {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char blocked;
    unsigned char field7;
};

struct LuigiContainer {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiObserver observer;
};

extern "C" {
void fn_99_B78C(LuigiObserver*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B86C(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" void fn_99_B7DC(LuigiContainer* object,
                           const LuigiObserverSignal* signal,
                           soModuleAccesser* accesser) {
    LuigiObserver* observer = &object->observer;
    if ((signal->flags & 4) && static_cast<bool>(observer->enabled) == true &&
        observer->blocked == 0) {
        fn_99_B78C(observer, accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, signal);
    fn_99_B86C(object->baseStorage, &copy, accesser);
}
