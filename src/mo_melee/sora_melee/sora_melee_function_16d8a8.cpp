#pragma force_active on
extern const float lbl_27_rodata_21C8;
extern const float lbl_27_rodata_21CC;
struct Param { int id; float a, b; unsigned char c, d, e, f; };
class soNullable {
public:
    virtual void isNull();
    virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
    virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
    virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20();
    virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24();
    virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28();
    virtual void slot29(); virtual void slot30(Param*);
};
struct Modules { char pad[8]; soNullable* obj; };
struct Fighter { char pad[0xd8]; Modules* modules; };
extern "C" void fn_27_16C98C(void*, Fighter*);
extern "C" void fn_27_193410(Fighter*);
extern "C" void fn_27_16C924(void*, Fighter*);
extern "C" void fn_27_16D8A8(void* self, Fighter* fighter) {
    Param p;
    p.id = 0xa8;
    p.a = lbl_27_rodata_21C8;
    p.b = lbl_27_rodata_21CC;
    p.c = 0; p.d = 0; p.e = 0; p.f = 0;
    fighter->modules->obj->slot30(&p);
    fn_27_16C98C(self, fighter);
    fn_27_193410(fighter);
    fn_27_16C924(self, fighter);
}