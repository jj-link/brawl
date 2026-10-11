struct soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiFlagFourObserver {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char blocked;
    unsigned char field7;
};

struct LuigiFlagFourContainer {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiFlagFourObserver observer;
};

extern "C" {
void fn_99_B5BC(LuigiFlagFourObserver*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B69C(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" bool fn_99_B60C(LuigiFlagFourContainer* object,
                           const LuigiObserverSignal* signal,
                           soModuleAccesser* accesser) {
    LuigiFlagFourObserver* observer = &object->observer;
    if ((signal->flags & 4) && static_cast<bool>(observer->enabled) == true &&
        observer->blocked == 0) {
        fn_99_B5BC(observer, accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, signal);
    return fn_99_B69C(object->baseStorage, &copy, accesser);
}

extern "C" bool fn_99_B69C(void*, const LuigiObserverSignal*, soModuleAccesser*) {
    return false;
}
