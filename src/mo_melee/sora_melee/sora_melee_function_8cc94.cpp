#pragma force_active on
class Target {
    char pad[8];

public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void call();
};

struct Level2 {
    char pad[0xb8];
    Target* target;
};

struct Level1 {
    char pad[0xd8];
    Level2* next;
};

struct Object {
    char pad[0x60];
    Level1* next;
};

extern "C" void fn_27_8CC94(Object* object) {
    object->next->next->target->call();
}
