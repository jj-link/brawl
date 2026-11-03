#pragma force_active on
class Command {
public:
 virtual void f0();
 virtual signed char getGroup();
 virtual signed char getType();
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
class Class_6EB8 {
public:
 virtual void fn_116_DEEC(); virtual void fn_116_DD40(); virtual void fn_116_DD48();
 virtual void fn_116_DD44(); virtual void fn_116_DEE8(); virtual void fn_116_DEE4();
 virtual void fn_116_DEE0(); virtual void fn_116_DEDC(); virtual void fn_116_DED8();
 virtual void fn_116_DED0(); virtual void fn_116_DECC(); virtual void fn_116_DEC4();
};
class Class_7624 {
public:
 virtual void fn_116_7384(); virtual void fn_116_101BC();
 virtual Class_6EB8** fn_116_11518(int);
 virtual void fn_116_11510(); virtual int fn_116_11508();
 virtual void fn_116_11500(); virtual void fn_116_114F8(); virtual void fn_116_114F0();
 virtual void fn_116_114E8(); virtual void fn_116_114E0(); virtual void fn_116_114D8();
 virtual void fn_116_114D0();
};
extern "C" Class_7624* fn_116_9570(void*);
extern "C" bool fn_27_133AA4(void*, Command*, void*, int);
extern "C" bool fn_116_1817C(void* self, Command* command, void* accesser, int kind) {
 signed char group = command->getGroup();
 bool valid = reinterpret_cast<SelfCall*>(self)->check(group);
 if (!valid) return false;
 switch (command->getType()) {
 case 0x22: {
  int i;
  Class_7624* mgr = fn_116_9570((char*)self + 0x1630c);
  for (i = 0; i < mgr->fn_116_11508(); i++)
   (*mgr->fn_116_11518(i))->fn_116_DEC4();
  return true;
 }
 default:
  return fn_27_133AA4(self, command, accesser, kind);
 }
}