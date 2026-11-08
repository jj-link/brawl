#pragma force_active on
#pragma opt_propagation off
struct V2 { float x,y; };
struct W { unsigned int a,b; };
struct Attr { short v; };
struct Flag { unsigned char value; };
struct Kinetic {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
virtual void unableAll(); virtual W getSum(Attr*);
};
struct Modules { char pad[0x7c]; Kinetic* kinetic; };
struct Access { char pad[0xd8]; Modules* mods; };
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13();
};
struct Temp { char data[0x34]; };
extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_94;
Temp* fn_113_1E0A0(Temp*, const V2*, const V2*, const V2*, const V2*, const V2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
void fn_113_BC00(void*, const void*);
}
extern "C" void fn_113_20844(void*, unsigned char* owner, Access* access) {
    access->mods->kinetic->unableAll();
    Attr attr;
    attr.v = 1;
    W s;
    W r = access->mods->kinetic->getSum(&attr);
    s.a = r.a;
    s.b = r.b;
    Flag flag = {0};
    unsigned char* obj = owner + 0x10;
    V2 e,d,c,b,a;
    a.x = lbl_113_rodata_94; a.y = lbl_113_rodata_94;
    b.x = lbl_113_rodata_90; b.y = lbl_113_rodata_90;
    c.x = lbl_113_rodata_94; c.y = lbl_113_rodata_94;
    d.x = lbl_113_rodata_90; d.y = lbl_113_rodata_90;
    e.x = lbl_113_rodata_90; e.y = lbl_113_rodata_90;
    Temp temp;
    fn_113_1E0A0(&temp, &e, &d, &c, &b, &a, 0, 0);
    fn_113_1E164(obj, &temp);
    fn_113_4730(&temp, 0);
    obj[0x30] = 0;
    ((Object_vptr_0*)obj)->slot13();
    V2 vel;
    vel.x = *(float*)&s.a;
    vel.y = lbl_113_rodata_90;
    fn_113_BC00(obj + 8, &vel);
    obj[5] |= 0x80;
}