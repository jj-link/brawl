#pragma force_active on
extern "C" void* fn_27_1A60DC(void*, short);

extern "C" void* fn_98_2830(void* component, short deleting) {
    if (component) {
        fn_27_1A60DC(component, static_cast<short>(-1));
        if (deleting > 0) operator delete(component);
    }
    return component;
}
