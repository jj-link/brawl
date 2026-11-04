#pragma force_active on
class Class_6B48 {
public:
    virtual void fn_113_10FB8();
    virtual void fn_113_10E80();
    virtual void fn_113_CBA8();
    virtual void fn_113_CBA4(int, int);
    virtual void fn_113_CBA0();
    virtual void fn_113_CB9C();
    virtual void fn_113_CB98(int);
    virtual void fn_113_CB94();
    virtual void fn_113_CB90();
    virtual void fn_113_CB88(int);
    virtual void fn_113_CB84(int);
};
struct Child { char pad[0x18]; Class_6B48* target; };
struct Owner { char pad[0xd8]; Child* child; };
struct Object { char pad[0x60]; Owner* owner; };
extern "C" void fn_113_1A26C(Object* object, int a, int b) {
    Owner* owner = object->owner;
    owner->child->target->fn_113_CBA4(a, 0);
    owner->child->target->fn_113_CB98(a);
    owner->child->target->fn_113_CB88(b);
    owner->child->target->fn_113_CB84(b);
}