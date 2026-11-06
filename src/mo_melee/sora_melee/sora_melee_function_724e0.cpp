#pragma force_active on
typedef unsigned long u32;
struct ArgData { int type; u32 data; };
struct Arg {
 const ArgData* p; unsigned char null;
 Arg():p(0),null(0){}
 Arg(const ArgData* q):p(q),null(0){}
 int type() const { return null==1?-1:p->type; }
 u32 value() const { return null==1?0:p->data; }
};
struct List {
 virtual void v0(); virtual void v1(); virtual const ArgData* at(int) const; virtual int size() const;
 char data[12];
 Arg get(int i) const { Arg a(at(i)); return a; }
};
struct Cmd {
 virtual void v0(); virtual signed char group(); virtual signed char type(); virtual void v3(); virtual void v4();
 virtual List args();
 virtual bool get(Arg*,int);
};
struct Flags { short bits; Flags(const Flags& x) : bits(x.bits) {} };
struct Sub {
 virtual void v0(); virtual Flags flags(int);
};
struct Module {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
 virtual bool valid(int);
 char pad[8]; Sub sub;
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void slot6(int,int,int,float); virtual void slot7(int,int,int);
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual bool slot29(signed char);
 char pad[28]; Module* module;
};
struct Object_vptr_88_base { char pad[0x88]; };
class Object_vptr_88 : public Object_vptr_88_base {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
};
extern "C" const float lbl_27_rodata_9B8;
extern "C" bool fn_27_724E0(Object_vptr_0* self, Cmd* cmd, int arg) {
 if (!self->slot29(cmd->group())) return false;
 if (cmd->type() <= -1 || cmd->type() >= 5) return false;
 switch(cmd->type()) {
 case 0: case 1: {
  Arg a;
  if (!cmd->get(&a,0) || a.type()!=0) return true;
  int id=a.value();
  bool fail=true;
  if (self->module->valid(id)) {
   if (self->module->sub.flags(id).bits & 4) fail=false;
  }
  if (fail) return true;
  int value=0;
  if (cmd->type()==0) {
   Arg b;
   if (!cmd->get(&b,1) || b.type()!=2) return true;
   value=b.value();
  }
  self->slot7(id,value,arg);
  return true;
 }
 case 2: {
  const List args=cmd->args();
  bool fail;
  int id=args.get(0).value();
  fail=true;
  if (self->module->valid(id)) {
   bool no=false;
   if (!(self->module->sub.flags(id).bits & 8) && !(self->module->sub.flags(id).bits & 16)) no=true;
   if (!no) fail=false;
  }
  if (fail) return true;
  self->slot7(id,args.get(1).value(),arg);
  return true;
 }
 case 3: {
  const List args=cmd->args();
  bool fail;
  int id=args.get(0).value();
  fail=true;
  if (self->module->valid(id)) {
   bool no=false;
   if (!(self->module->sub.flags(id).bits & 8) && !(self->module->sub.flags(id).bits & 16)) no=true;
   if (!no) fail=false;
  }
  if (fail) return true;
  self->slot6(id,arg,args.get(1).value(),lbl_27_rodata_9B8);
  return true;
 }
 case 4: {
  const List args=cmd->args();
  bool fail;
  int id=args.get(0).value();
  fail=true;
  if (self->module->valid(id)) {
   bool no=false;
   if (!(self->module->sub.flags(id).bits & 8) && !(self->module->sub.flags(id).bits & 16)) no=true;
   if (!no) fail=false;
  }
  if (fail) return true;
  self->slot7(id,0,arg);
  return true;
 }
 }
 return false;
}