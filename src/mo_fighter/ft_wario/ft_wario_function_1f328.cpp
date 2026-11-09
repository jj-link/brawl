#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual signed char slot1();
 virtual signed char slot2();
};
class SelfCall {
public:
 char pad[0x3c];
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
 virtual void v44(); virtual void v45(); virtual void v46();
 virtual bool check(signed char);
};
extern "C" {
extern char lbl_27_bss_8094[];
void fn_27_35896C(void*, void*, void*, unsigned char, unsigned char);
bool fn_27_133AA4(void*, Object_vptr_0*, void*, int);
bool fn_110_1F328(void* self, Object_vptr_0* command, void* accesser, int kind) {
 signed char group = command->slot1();
 bool valid = reinterpret_cast<SelfCall*>(self)->check(group);
 if (!valid) return false;
 switch (command->slot2()) {
 case 5:
  fn_27_35896C(lbl_27_bss_8094, accesser, *(void**)((char*)self + 0x10c), 1, 0);
  return true;
 default:
  return fn_27_133AA4(self, command, accesser, kind);
 }
}
}