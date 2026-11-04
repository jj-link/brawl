#include <so/so_value_accesser.h>
#pragma force_active on
struct ArgData { int type; unsigned long data; };
struct Arg {
 const ArgData* p; unsigned char null;
 Arg(const ArgData* q):p(q),null(0){}
 int type() const { return null==1?-1:p->type; }
 unsigned long value() const { return null==1?0:p->data; }
 bool boolean() const { return null==1?false:p->data!=0; }
};
struct List {
 virtual void v0();
 virtual void v1();
 virtual const ArgData* at(int) const;
 virtual int size() const;
 char data[12];
 Arg get(int i) const { Arg a(at(i)); return a; }
};
struct Cmd {
 virtual void v0();
 virtual signed char group();
 virtual signed char type();
 virtual int count();
 virtual void v4();
 virtual List args();
};
struct Stop {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void set(int);
 virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
 virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void stop(int,bool);
 virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
 virtual int valid(signed char);
};
extern "C" bool notifyEventAnimCmd__16soStopModuleImplFP9acAnimCmdP16soModuleAccesserl(Stop* self, Cmd* cmd, soModuleAccesser* acc, long) {
 if (!self->valid(cmd->group())) return false;
 if (cmd->type()<=-1 || cmd->type()>=2) return false;
 switch(cmd->type()) {
 case 0: {
 if(cmd->count()<2 || cmd->count()>2) return true;
 const List args=cmd->args();
 int value;
 if(args.get(0).type()==0) value=args.get(0).value();
 else if(args.get(0).type()==5) value=soValueAccesser::getValueInt(acc,args.get(0).value(),0);
 else return true;
 self->stop(value,args.get(1).boolean());
 return true;
 }
 case 1: {
 if(cmd->count()<1 || cmd->count()>1) return true;
 const List args=cmd->args();
 int value;
 if(args.get(0).type()==0) value=args.get(0).value();
 else if(args.get(0).type()==5) value=soValueAccesser::getValueInt(acc,args.get(0).value(),0);
 else return true;
 self->set(value);
 return true;
 }
 }
 return false;
}