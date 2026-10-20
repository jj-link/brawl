#pragma force_active on
struct Outer;

class Interface {
public:
    virtual void unused();
    virtual Outer* get();
};

struct Object {
    unsigned char pad[0x18];
    Interface* interface;
};

extern "C" unsigned int fn_27_B1D74(Outer*);

extern "C" unsigned int fn_27_B2C90(Object p)
{
    return fn_27_B1D74(p.interface->get());
}
