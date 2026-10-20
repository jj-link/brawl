#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

#define VIRTUAL_4(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3();

#define VIRTUAL_16(p) \
    VIRTUAL_4(p##a) \
    VIRTUAL_4(p##b) \
    VIRTUAL_4(p##c) \
    VIRTUAL_4(p##d)

struct ModuleData {
    u8 pad[8];
};

struct Module : ModuleData {
    VIRTUAL_4(m_a)
    VIRTUAL_4(m_b)
    VIRTUAL_4(m_c)
    virtual void m_last();
    virtual u32 getState();
};

struct Modules {
    u8 pad[0xbc];
    Module* module;
};

struct Accesser {
    u8 pad[0xd8];
    Modules* modules;
};

struct Event {
    u8 pad[0x21];
    u8 type;
};

struct PrimaryData {
    u8 pad[8];
};

struct Primary : PrimaryData {
    VIRTUAL_16(p_a)
    VIRTUAL_16(p_b)
    VIRTUAL_16(p_c)
    VIRTUAL_16(p_d)
    VIRTUAL_16(p_e)
    VIRTUAL_16(p_f)
    VIRTUAL_16(p_g)
    VIRTUAL_16(p_h)
    VIRTUAL_16(p_i)
    VIRTUAL_16(p_j)
    VIRTUAL_4(p_k)
    VIRTUAL_4(p_l)
    VIRTUAL_4(p_m)
    virtual int process();
};

struct SecondaryData {
    u8 pad[0x3c];
};

struct Secondary : SecondaryData {
    VIRTUAL_16(s_a)
    VIRTUAL_16(s_b)
    VIRTUAL_16(s_c)
    VIRTUAL_16(s_d)
    VIRTUAL_16(s_e)
    VIRTUAL_16(s_f)
    VIRTUAL_16(s_g)
    VIRTUAL_16(s_h)
    VIRTUAL_4(s_i)
    VIRTUAL_4(s_j)
    virtual void s_last();
    virtual void prepare();
};

struct Enemy : Primary, Secondary {
    u8 pad[0x21cc];
    u8 flag;
};

#undef VIRTUAL_16
#undef VIRTUAL_4

extern "C" void fn_41_33580(Enemy* self, Event* event, Accesser* accesser) {
    if (event) {
        int handled = 0;
        if (event->type == 3) {
            Module* module = accesser->modules->module;
            if (module->getState() == 1) {
                self->prepare();
                handled = self->process();
            }
        }
        if (!handled) {
            self->flag = 1;
        }
    }
}
