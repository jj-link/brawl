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
extern "C" unsigned int fn_27_B1E5C(Outer*);
extern "C" unsigned int fn_27_B2E70(Object p)
{
    return fn_27_B1E5C(p.interface->get());
}
