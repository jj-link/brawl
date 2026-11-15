#include <so/stageobject.h>
#pragma force_active on

struct CaptainFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};
struct InitParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    CaptainFlags flags;
};
struct Triple { void* vt; int a, b, c; };
template<int offset>
inline void assignTriple(char* self, const Triple& other) {
    if ((void*)(self + offset) != (const void*)&other) {
        if ((void*)(self + offset + 4) != (const void*)&other.a)
            *(int*)(self + offset + 4) = other.a;
        bool empty = other.b == 0;
        *(int*)(self + offset + 8) = other.b;
        *(int*)(self + offset + 12) = other.c;
        if (empty) *(int*)(self + offset + 12) = 0;
    }
}
class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(int, unsigned int); virtual void* slot6(int);
    virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10();
    virtual void slot11(); virtual void slot12(); virtual void slot13(unsigned int, float);
    virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33();
    virtual void slot34(int, void*);
};
struct Energy {
    char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    char pad2[2];
    Vec2f a, b, c, d, e;
};
extern "C" {
void fn_27_1D8370(void*, const InitParam*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_20878[], lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_65B0, lbl_27_rodata_65B4;
}
extern "C" void fn_27_30E85C(char* self, int arg1, const Vec3f* arg2, int arg3, int arg4, int arg5, float farg0, float farg1)
{
    InitParam p;
    p.resource = arg3;
    p.team = arg4;
    p.teamOwner = arg4;
    p.teamAnother = arg4;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = arg1;
    p.reserved1 = 0;
    __memcpy(&p.position, arg2, sizeof(Vec3f));
    p.facing = farg0;
    p.parameter = arg5;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 0;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;
    p.motion = 0x50;
    fn_27_1D8370(self, &p);

    Triple t1;
    int v1 = *(int*)(*(char**)(self + 0x2044) + arg1 * 4 + 0x34);
    t1.a = 0; t1.vt = lbl_27_data_20878; t1.b = v1; t1.c = 4;
    if (v1 == 0) t1.c = 0;
    assignTriple<0x2048>(self, t1);

    Triple t2;
    int v2 = *(int*)(*(char**)(self + 0x2044) + arg1 * 4 + 0x48);
    t2.a = 0; t2.vt = lbl_27_data_20878; t2.b = v2; t2.c = 4;
    if (v2 == 0) t2.c = 0;
    assignTriple<0x2074>(self, t2);

    Triple t3;
    int v3 = *(int*)(*(char**)(self + 0x2044) + arg1 * 4 + 0x5c);
    t3.a = 0; t3.vt = lbl_27_data_20878; t3.b = v3; t3.c = 4;
    if (v3 == 0) t3.c = 0;
    assignTriple<0x20a0>(self, t3);

    char* P = *(char**)(self + 0x60);
    char* Q = *(char**)(P + 0xd8);
    (*(Object_vptr_0**)(Q + 0x70))->slot34(0, P);
    P = *(char**)(self + 0x60);
    Q = *(char**)(P + 0xd8);
    (*(Object_vptr_0**)(Q + 0x64))->slot13(0x21000000, farg1);
    P = *(char**)(self + 0x60);
    Q = *(char**)(P + 0xd8);
    (*(Object_vptr_0**)(Q + 0x64))->slot5(arg1, 0x10000005);
    P = *(char**)(self + 0x60);
    Q = *(char**)(P + 0xd8);
    void* o = (*(Object_vptr_0**)(Q + 0x7c))->slot6(0);
    Energy* r = (Energy*)__dynamic_cast(o, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 0);
    if (r != 0) {
        r->a = Vec2f(lbl_27_rodata_65B4, lbl_27_rodata_65B4);
        r->b = Vec2f(lbl_27_rodata_65B4, lbl_27_rodata_65B4);
        r->c = Vec2f(lbl_27_rodata_65B0, lbl_27_rodata_65B0);
        r->d = Vec2f(lbl_27_rodata_65B0, lbl_27_rodata_65B0);
        r->e = Vec2f(lbl_27_rodata_65B0, lbl_27_rodata_65B0);
        r->flag = 0;
    }
}