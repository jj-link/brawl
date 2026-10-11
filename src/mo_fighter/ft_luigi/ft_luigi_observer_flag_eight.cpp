struct soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiFlagEightObserver {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char blocked;
    unsigned char field7;
};

struct LuigiFlagEightContainer {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiFlagEightObserver observer;
};

extern "C" {
void fn_99_B6A4(LuigiFlagEightObserver*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B784(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" bool fn_99_B6F4(LuigiFlagEightContainer* object,
                           const LuigiObserverSignal* signal,
                           soModuleAccesser* accesser) {
    LuigiFlagEightObserver* observer = &object->observer;
    if ((signal->flags & 8) && static_cast<bool>(observer->enabled) == true &&
        observer->blocked == 0) {
        fn_99_B6A4(observer, accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, signal);
    return fn_99_B784(object->baseStorage, &copy, accesser);
}
