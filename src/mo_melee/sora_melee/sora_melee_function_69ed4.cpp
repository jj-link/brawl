#pragma force_active on
typedef unsigned long u32;
struct ArgData { int type; u32 data; };
struct Arg {
 const ArgData* p; unsigned char null;
 Arg(const ArgData* q):p(q),null(0){}
 int type() const { return null==1?-1:p->type; }
 u32 value() const { return null==1?0:p->data; }
 bool boolean() const { return null==1?false:p->data!=0; }
};
struct List {
 virtual void v0();
 virtual void v1();
 virtual const ArgData* at(int) const;
 virtual int size() const;
 char data[12];
 Arg get(int i) const { Arg a(at(i)); return a; }
 int count() const { return size(); }
};
struct Cmd {
 virtual void v0();
 virtual signed char group();
 virtual signed char type();
 virtual void v3();
 virtual void v4();
 virtual List args();
};
struct Obj {
 virtual void v0();
 virtual void v1();
 virtual void set(void*,bool,int);
 virtual void reset();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(); virtual void v17(); virtual void v18();
 virtual int valid(signed char);
};
struct Sub {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void act();
};
struct Modules { char pad[12]; Sub* sub; };
struct Access { char pad[0xd8]; Modules* modules; };
extern "C" void* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(Access*,u32,u32);
extern "C" bool fn_27_69ED4(Obj* self,Cmd* cmd,Access* acc) {
 if (!self->valid(cmd->group())) return 0;
 if (cmd->type()<=-1 || cmd->type()>=2) return 0;
 switch(cmd->type()) {
 case 0: {
 const List args=cmd->args();
 void* value;
 if(args.get(0).type()==5)
 value=getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(acc,args.get(0).value(),0);
 else return 1;
 bool flag=true;
 if(args.count()>1) {
 if(args.get(1).type()==3) flag=args.get(1).boolean();
 else return 1;
 }
 acc->modules->sub->act();
 self->set(value,flag,0);
 return 1;
 }
 case 1:self->reset();return 1;
 }
 return 0;
}
