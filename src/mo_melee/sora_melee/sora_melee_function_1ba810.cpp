#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void second();
};

extern "C" void fn_27_1BA810(void* object) {
    reinterpret_cast<Interface*>(static_cast<char*>(object) + 0x10)->second();
}
