#pragma force_active on
struct Value { int tag; int value; };
struct Ref {
 Value* p; unsigned char flag;
 Ref(Value* q): p(q), flag(0) {}
 int get() const { return flag == 1 ? 0 : p->value; }
};
struct Args {
 virtual void v0(); virtual void v1(); virtual Value* at(int);
 int data[3];
};
inline Ref getArg(Args& args) { return Ref(args.at(0)); }
struct Cmd {
 virtual void v0(); virtual signed char group(); virtual signed char type();
 virtual void v3(); virtual signed char value(); virtual Args args();
};
struct Sub {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual int act(void*, Args*, signed char*, void*);
};
struct Self {
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
 virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
 virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
 virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
 virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
 virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
 virtual int valid(signed char);
 char pad[0x28]; Sub* sub; char pad2[8]; int field_38;
};
extern void* lbl_27_rodata_9D0[];
extern "C" int fn_27_744B4(Self* self, Cmd* cmd, void* acc) {
 if (!self->valid(cmd->group())) return 0;
 if (cmd->type() <= -1 || cmd->type() >= 15) return 0;
 switch (cmd->type()) {
 case 0: case 1: case 2: case 3: case 4: case 5: case 6:
 case 7: case 8: case 9: case 10: case 11: case 12: case 14: {
  signed char value = cmd->value();
  Args args = cmd->args();
  return self->sub->act(lbl_27_rodata_9D0[cmd->type()], &args, &value, acc);
 }
 case 13: {
  Args args = cmd->args();
  Ref ref = getArg(args);
  self->field_38 = ref.get();
  return 1;
 }
 }
 return 0;
}