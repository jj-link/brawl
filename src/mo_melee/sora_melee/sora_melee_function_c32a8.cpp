#pragma force_active on

class soCollisionAttackModuleImpl {
public:
    virtual ~soCollisionAttackModuleImpl();
    virtual void fn_27_39AA4();
    virtual void fn_27_39C34();
    virtual void fn_27_39C90();
    virtual void fn_27_39D10();
    virtual void fn_27_39D80();
    virtual void fn_27_39E30();
    virtual void fn_27_39EF4();
    virtual void fn_27_3A0C4();
    virtual unsigned int fn_27_3A270(int);
    virtual void fn_27_3AF7C();
    virtual void fn_27_3B070();
    virtual void fn_27_3B120();
    virtual void fn_27_3A3C8();
    virtual void fn_27_3A430();
    virtual void fn_27_3A4BC();
    virtual void fn_27_3A504();
    virtual void fn_27_3A600();
    virtual void fn_27_3A664();
    virtual void fn_27_3A6A4();
    virtual void fn_27_3A6D8();
    virtual void fn_27_3A718();
    virtual void fn_27_3AD40();
    virtual void fn_27_3ADDC();
    virtual void fn_27_3AF34();
    virtual void fn_27_3A75C();
    virtual void fn_27_3A920();
    virtual void fn_27_3A960();
    virtual void fn_27_3A994();
    virtual void fn_27_3A9EC();
    virtual void fn_27_3AA50();
    virtual void fn_27_3AAA8();
    virtual void fn_27_3AB0C();
    virtual void fn_27_3AB64();
    virtual void fn_27_3ABC8();
    virtual void fn_27_3A54C();
    virtual void fn_27_3A5A4();
    virtual void fn_27_3BCC4();
    virtual void fn_27_3AC30();
    virtual void fn_27_41464();
    virtual void fn_27_41454();
    virtual void fn_27_41434();
    virtual void fn_27_3ACEC();
    virtual void fn_27_4142C();
    virtual void fn_27_41424();
    virtual void fn_27_4141C();
    virtual void fn_27_41414();
    virtual void fn_27_4140C();
    virtual void fn_27_4077C();
    virtual void fn_27_41404();
    virtual void fn_27_413FC();
    virtual void fn_27_413F4();
    virtual void fn_27_413EC();
    virtual void fn_27_413E4();
    virtual void fn_27_413D0();
    virtual void fn_27_3B1A8();
    virtual void fn_27_3B3DC();
    virtual void fn_27_3B7FC();
    virtual void fn_27_3BA40();
    virtual void fn_27_3BA48();
    virtual void fn_27_413C8();
    virtual void fn_27_413C0();
    virtual int fn_27_3BA64(int, int);
    virtual void fn_27_413B8();
    virtual void fn_27_3BA50();
    virtual int fn_27_413B0(int);
};

class fn_27_C32A8_C {
public:
    char pad[0x54];
    soCollisionAttackModuleImpl* m_attack;
};

class fn_27_C32A8_B {
public:
    char pad[0xD8];
    fn_27_C32A8_C* m_c;
};

class fn_27_C32A8_A {
public:
    char pad[8];
    fn_27_C32A8_B* m_b;
    int m_index;
    int m_base;
};

extern "C" int fn_27_C32A8(const fn_27_C32A8_A* self, int arg) {
    if (self->m_index != -1) {
        if (self->m_b->m_c->m_attack->fn_27_3A270(self->m_index) == 1U) {
            return self->m_b->m_c->m_attack->fn_27_3BA64(self->m_index, arg);
        }
    }
    return self->m_base + self->m_b->m_c->m_attack->fn_27_413B0(arg);
}
