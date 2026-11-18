#include <gf/gf_task.h>
#pragma force_active on
struct Result { void* a; void* b; int c; int d; };
class soNullable { public:
 virtual void isNull(); virtual void fn_27_29FEAC(); virtual signed char fn_27_2975F0(); virtual int fn_27_2839BC(); virtual void fn_27_297638(); virtual Result fn_27_289454();
};
class Object_vptr_0 { public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(int, int);
};
extern "C" char lbl_27_data_1F88[];
struct Args {
 void* vtable; void* a; int b,c; int arg; bool error;
 Args(const Result& res, int value) { a=res.b; vtable=lbl_27_data_1F88; b=res.c; c=res.d; if(!b) c=0; arg=value; error=false; }
};
struct SelfBase { char pad[8]; };
class Self : public SelfBase { public:
virtual void f0();
virtual void f1();
virtual void f2();
virtual void f3();
virtual void f4();
virtual void f5();
virtual void f6();
virtual void f7();
virtual void f8();
virtual void f9();
virtual void f10();
virtual void f11();
virtual void f12();
virtual void f13();
virtual void f14();
virtual void f15();
virtual void f16();
virtual void f17();
virtual void f18();
virtual void f19();
virtual void f20();
virtual void f21();
virtual void f22();
virtual void f23();
virtual void f24();
virtual void f25();
virtual void f26();
virtual void f27();
virtual void f28();
virtual void f29();
virtual void f30();
virtual void f31();
virtual void f32();
virtual void f33();
virtual void f34();
virtual void f35();
virtual void f36();
virtual void f37();
virtual void f38();
virtual void f39();
virtual void f40();
virtual void f41();
virtual void f42();
virtual void f43();
virtual void f44();
virtual void f45();
virtual void f46();
virtual void f47();
virtual void f48();
virtual void f49();
virtual void f50();
virtual void get(int*,int*,int*,int*,int*,int*);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Owner { char pad[0x60]; Access* access; char pad2[0x3d2c-0x64]; unsigned int taskId; };
struct Target { char pad[0x174]; int a,b,c,d,e,f;
 static void set(Target* t,int x,int z,int u,int y,int w,int v) { t->a=x;t->c=z;t->e=u;t->b=y;t->d=w;t->f=v; }
};
extern "C" {
extern char lbl_27_data_6D090[]; extern char __RTTI__6gfTask[];
void* __dynamic_cast(void*,long,const void*,const void*,short);
int fn_27_735C8(Args*,int); float fn_27_736B8(Args*,int); void fn_80052644();
void fn_27_2C3870(Target*,int,float,float,float,float,float,float);
}
extern "C" int fn_27_297810(Self* self, int ownerBits, int cmdBits, int arg) {
 Owner* owner=(Owner*)ownerBits;
 soNullable* cmd=(soNullable*)cmdBits;
 switch(cmd->fn_27_2975F0()) {
 case 0x11:
  if(cmd->fn_27_2839BC()==7) {
   Args args(cmd->fn_27_289454(),arg);
   cmd=(soNullable*)fn_27_735C8(&args,0);
   float a=fn_27_736B8(&args,1);
   float b=fn_27_736B8(&args,2);
   float c=fn_27_736B8(&args,3);
   float d=fn_27_736B8(&args,4);
   float e=fn_27_736B8(&args,5);
   float f=fn_27_736B8(&args,6);
   if(!args.error && owner->taskId != -1) {
    Target* target=(Target*)__dynamic_cast(gfTask::getTask(owner->taskId),0x3c,lbl_27_data_6D090,__RTTI__6gfTask,0);
    if(target) {
     if((int)cmd==0x4f || (int)cmd==0x6f) {
      owner=(Owner*)owner->access->modules->work;
      int x,y; int z=0; int w=0; int u=0; int v=0;
      self->get(&x,&z,&u,&y,&w,&v);
      ((Object_vptr_0*)owner)->slot5(x,0x10000002);
      Target::set(target,x,z,u,y,w,v);
     }
     if((int)cmd==4) fn_80052644();
     fn_27_2C3870(target,(int)cmd,a,b,c,d,e,f);
     return 1;
    }
   }
  }
  break;
 }
 return 0;
}