#pragma force_active on
extern "C" void* fn_98_3F6C(void*, short);

extern "C" void* fn_98_3F10(void* component, int deleting) {
    if (component) {
        fn_98_3F6C(component, short(0));
        if (static_cast<short>(deleting) > 0) operator delete(component);
    }
    return component;
}
