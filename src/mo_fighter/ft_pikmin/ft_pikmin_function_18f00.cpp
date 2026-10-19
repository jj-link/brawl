#pragma force_active on
class Target {
public:
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void unused3() = 0;
    virtual void unused4() = 0;
    virtual void unused5() = 0;
    virtual void unused6() = 0;
    virtual void unused7() = 0;
    virtual void unused8() = 0;
    virtual void unused9() = 0;
    virtual void unused10() = 0;
    virtual void unused11() = 0;
    virtual void unused12() = 0;
    virtual void unused13() = 0;
    virtual void unused14() = 0;
    virtual void unused15() = 0;
    virtual void unused16() = 0;
    virtual void unused17() = 0;
    virtual void invoke(void*) = 0;
};

struct Level3 {
    unsigned char pad[0x64];
    Target* target;
};

struct Level2 {
    unsigned char pad[0xD8];
    Level3* next;
};

struct Level1 {
    unsigned char pad[0x60];
    Level2* next;
};

extern "C" void fn_113_18F00(void* arg1, void* arg2) {
    ((Level1*)arg1)->next->next->target->invoke(arg2);
}
