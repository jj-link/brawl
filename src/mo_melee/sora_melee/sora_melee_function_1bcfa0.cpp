#pragma force_active on
struct Interface {
    virtual void first();
    virtual void target();
};

extern "C" void fn_27_1BCFA0(void* self) {
    Interface* sub = reinterpret_cast<Interface*>(
        static_cast<char*>(self) + 16);
    sub->target();
}
