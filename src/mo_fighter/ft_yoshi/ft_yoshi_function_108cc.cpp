#include <ft/ft_common_data_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Class_8BE4 {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16CDC();
    virtual void fn_95_17478();
    virtual void fn_95_17474();
    virtual void fn_95_17470();
    virtual void fn_95_1746C();
    virtual void fn_95_17464();
    virtual void fn_95_174AC();
    virtual void fn_95_174A4();
    virtual void fn_95_1749C();
    virtual void fn_95_17494();
    virtual void fn_95_1748C();
    virtual void fn_95_17424();
    virtual void fn_95_17458();
    virtual int fn_95_1744C(int, bool);
    virtual void fn_95_17444();
    virtual void fn_95_17438();
    virtual void fn_95_17430(int, int, bool);
};
class Class_8DBC {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16C80();
    virtual void fn_95_17664();
    virtual void fn_95_1765C();
    virtual void fn_95_17654();
    virtual void fn_95_1764C();
    virtual void fn_95_17644();
    virtual void fn_95_1763C();
    virtual void fn_95_17634();
    virtual void fn_95_1762C();
    virtual void fn_95_17624();
    virtual void fn_95_1761C();
    virtual void fn_95_17614();
    virtual Vec2f fn_95_1760C(short*);
    virtual void fn_95_175BC();
    virtual void fn_95_17604();
    virtual void fn_95_175F4();
    virtual void fn_95_175E4();
};
struct Modules {
    char pad[0x1c];
    Class_8BE4* attack;
    char pad2[0x5c];
    Class_8DBC* kinetic;
};
struct Fighter {
    char pad[0xd8];
    Modules* modules;
};
struct Params {
    char pad[0x78];
    float a, b;
};
struct Data {
    char pad[0x7c];
    Params* params;
};
extern "C" float fn_95_A8B4(float);
extern "C" void fn_95_108CC(Fighter* fighter) {
    Class_8BE4* attack = fighter->modules->attack;
    Params* params = ((Data*)g_ftCommonDataAccesser.getData((ftKind)4))->params;
    if (attack->fn_95_1744C(0, 0)) {
        short id = -1;
        Vec2f value;
        Vec2f::copy(value, fighter->modules->kinetic->fn_95_1760C(&id));
        int count = (int)(params->b * (params->a + fn_95_A8B4(value.m_x)));
        if (count < 1) count = 1;
        attack->fn_95_17430(0, count, 0);
        attack->fn_95_17430(1, count, 0);
    }
}