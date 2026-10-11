struct soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiFlagTwoObserver {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char blocked;
    unsigned char field7;
};

struct LuigiFlagTwoContainer {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiFlagTwoObserver observer;
};

extern "C" {
void fn_99_B4D4(LuigiFlagTwoObserver*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B5B4(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" bool fn_99_B524(LuigiFlagTwoContainer* object,
                           const LuigiObserverSignal* signal,
                           soModuleAccesser* accesser) {
    LuigiFlagTwoObserver* observer = &object->observer;
    if ((signal->flags & 2) && static_cast<bool>(observer->enabled) == true &&
        observer->blocked == 0) {
        fn_99_B4D4(observer, accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, signal);
    return fn_99_B5B4(object->baseStorage, &copy, accesser);
}

extern "C" bool fn_99_B5B4(void*, const LuigiObserverSignal*, soModuleAccesser*) {
    return false;
}
