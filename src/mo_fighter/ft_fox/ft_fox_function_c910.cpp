#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void second();
    virtual void target();
};

extern "C" void fn_97_C910(void* object) {
    reinterpret_cast<Interface*>(
        static_cast<char*>(object) + 0x1C794
    )->target();
}
