#pragma force_active on
#define V1(n) virtual void* d##n();
#define V10(n) V1(n##0) V1(n##1) V1(n##2) V1(n##3) V1(n##4) V1(n##5) V1(n##6) V1(n##7) V1(n##8) V1(n##9)
#define V100(n) V10(n##0) V10(n##1) V10(n##2) V10(n##3) V10(n##4) V10(n##5) V10(n##6) V10(n##7) V10(n##8) V10(n##9)

struct Pad { char p[0x28]; int taskId; char q[0x10]; };
struct Fighter : Pad {
    V100(1) V10(20) V10(21) V10(22) V10(23) V10(24) V10(25) V10(26) V10(27)
    V1(280) V1(281) V1(282) V1(283) V1(284)
    virtual void* call187(void*);
};
struct FighterNA : Pad {
    V100(1) V10(20) V10(21) V10(22) V10(23) V10(24) V10(25) V10(26) V10(27)
    V1(280) V1(281) V1(282) V1(283) V1(284)
    virtual void* call187();
};
struct ObjA { V1(0) V1(1) V1(2) V1(3) virtual void* get(int); };
struct Pad8 { char p[8]; };
struct ObjB : Pad8 { V1(0) V1(1) V1(2) V1(3) virtual void* get(); };
struct Object_vptr_0 {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void* slot10();
};
struct Posture {
    V1(0) V1(1) V1(2) V1(3) V1(4) V1(5) V1(6) V1(7) V1(8)
    virtual float lr();
};
struct Accesser {
    ObjB* m0;
    char pad[8];
    Posture* mC;
    char pad10[0x54];
    ObjA* m64;
};
extern "C" {
extern const char lbl_107_data_3D3C[], lbl_107_data_45B8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
unsigned char fn_27_1119B8(void*);
void fn_107_1AA38(void*, int, void*, int, float, void*, float);
}
extern "C" int fn_107_B930(void* arg0, char* arg1) {
    int owner;
    Posture* r31;
    ObjA* r30;
    ObjB* r29;
    int taskId;
    Fighter* fighter;
    float f31, f30;
    fighter = static_cast<Fighter*>(__dynamic_cast(*(void**)(arg1 + 8), 0x3c, lbl_107_data_3D3C, lbl_107_data_45B8, (short)1));
    Accesser* acc = *(Accesser**)(arg1 + 0xd8);
    r30 = acc->m64;
    r31 = acc->mC;
    r29 = acc->m0;
    taskId = fighter->taskId;
    f30 = (float)fn_27_1119B8(fighter->call187(acc));
    void* r30b = r30->get(0x10000043);
    f31 = r31->lr();
    owner = fn_27_111364(reinterpret_cast<FighterNA*>(fighter)->call187());
    Object_vptr_0* o = (Object_vptr_0*)r29->get();
    void* r5 = o->slot10();
    fn_107_1AA38(arg0, taskId, r5, owner, f31, r30b, f30);
    return 1;
}