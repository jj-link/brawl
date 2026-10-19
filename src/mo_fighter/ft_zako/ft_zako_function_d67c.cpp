#pragma force_active on
class Callback {
public:
    virtual void first();
    virtual void second();
    virtual void callback();
};

extern "C" void fn_126_D67C(char* owner) {
    reinterpret_cast<Callback*>(owner + 0x7b90)->callback();
}
