#pragma force_active on
extern "C" void* fn_98_1AB0(void*, short);

extern "C" void* fn_98_1C84(void* component, int deleting) {
    if (component) {
        fn_98_1AB0(component, static_cast<short>(0));
        if (static_cast<short>(deleting) > 0) operator delete(component);
    }
    return component;
}
