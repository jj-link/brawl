#include <ft/ft_common_data_accesser.h>
#pragma force_active on
struct LocalVec { float x, y, z; };
class Class_8BE4 {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16CDC();
    virtual void fn_95_17478();
    virtual void fn_95_17474();
    virtual int fn_95_17470(int);
    virtual void fn_95_1746C();
    virtual void fn_95_17464();
    virtual void fn_95_174AC();
    virtual void fn_95_174A4(int);
    virtual void fn_95_1749C();
    virtual void fn_95_17494();
    virtual void fn_95_1748C();
    virtual void fn_95_17424();
    virtual void fn_95_17458();
    virtual void fn_95_1744C();
    virtual void fn_95_17444();
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
    virtual void fn_95_1760C();
    virtual LocalVec fn_95_175BC(int);
    virtual void fn_95_17604(LocalVec*, int);
};
struct Modules {
    char pad[0xc];
    Class_8DBC* posture;
    char pad10[0x54];
    Class_8BE4* work;
};
struct Data { char pad[0x8c]; int* value; };
extern "C" void fn_95_F938(void*, char* p) {
    Modules* m = *(Modules**)(p + 0xd8);
    Class_8BE4* work = m->work;
    Class_8DBC* posture = m->posture;
    int* value = ((Data*)g_ftCommonDataAccesser.getData((ftKind)4))->value;
    if (work->fn_95_17470(0x10000041) > 0) {
        work->fn_95_174A4(0x10000041);
        const LocalVec& tmp = posture->fn_95_175BC(0);
        LocalVec& v = const_cast<LocalVec&>(tmp);
        v.y -= 180.0f / (float)*value;
        posture->fn_95_17604(&v, 0);
        if (*value / 2 == work->fn_95_17470(0x10000041))
            posture->fn_95_1761C();
    }
}
