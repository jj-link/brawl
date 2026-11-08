#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(int, unsigned int);
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void processCamera(); virtual void slot12(); virtual void slot13(); virtual void slot14();
 virtual void slot15(); virtual void slot16(); virtual void renderOpa(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void init(); virtual void slot22(); virtual void slot23(); virtual void slot24();
 virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34();
 virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual int slot40();
};
struct ModelBase { char pad[8]; };
class Model : public ModelBase {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual int v32(const char*);
};
struct Modules { char pad0[4]; Model* model; char pad1[0x5c]; Object_vptr_0* work; };
struct Owner { char pad0[8]; Object_vptr_3c* stage; char pad1[0xcc]; Modules* modules; };
extern char lbl_27_data_88A78[];
extern "C" void fn_27_32E984(int unused, Owner* owner) {
 owner->modules->work->slot5(-1, 0x20000003);
 owner->modules->work->slot5(-1, 0x20000005);
 owner->modules->work->slot5(-1, 0x20000008);
 owner->modules->work->slot5(-1, 0x20000009);
 if (owner->stage->slot40() == 5) {
  owner->modules->work->slot5(0x1ad7, 0x20000006);
  owner->modules->work->slot5(0x1ad8, 0x20000007);
  owner->modules->work->slot5(0, 0x2000000a);
 } else {
  owner->modules->work->slot5(0xefd, 0x20000006);
  owner->modules->work->slot5(0xefe, 0x20000007);
  int value = owner->modules->model->v32(lbl_27_data_88A78);
  owner->modules->work->slot5(value, 0x2000000a);
 }
}