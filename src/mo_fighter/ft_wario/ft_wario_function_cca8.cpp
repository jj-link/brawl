#pragma force_active on
typedef unsigned int u32;
struct Event { int kind; bool flag; u32 id; Event(u32 v):kind(0x45c),flag(false),id(v){} };
struct Pair { u32 a; void* b; u32 c,d; };
struct Obj {
 virtual void dummy8();
 virtual void dummy12();
 virtual void dummy16();
 virtual void change(int,void*);
 virtual int get(int);
 virtual void set(int,int);
 virtual void dummy32();
 virtual void dummy36();
 virtual void dummy40();
 virtual int test2c(int);
 virtual int test30(int);
 virtual void dummy52();
 virtual void dummy56();
 virtual void dummy60();
 virtual void dummy64();
 virtual void dummy68();
 virtual void send(int,Event*,int);
 virtual void dummy76();
 virtual u32 ground(int);
 virtual int get54(int);
 virtual void dummy88();
 virtual void dummy92();
 virtual void dummy96();
 virtual int kind();
 virtual void dummy104();
 virtual void pair(Pair*);
 virtual void release(void*);
};
struct FighterBase { char pad[0x28]; int id; char pad2[0x10]; };
struct Fighter: FighterBase {
virtual void d0();virtual void d1();virtual void d2();virtual void d3();virtual void d4();virtual void d5();virtual void d6();virtual void d7();virtual void d8();virtual void d9();
virtual void d10();virtual void d11();virtual void d12();virtual void d13();virtual void d14();virtual void d15();virtual void d16();virtual void d17();virtual void d18();virtual void d19();
virtual void d20();virtual void d21();virtual void d22();virtual void d23();virtual void d24();virtual void d25();virtual void d26();virtual void d27();virtual void d28();virtual void d29();
virtual void d30();virtual void d31();virtual void d32();virtual void d33();virtual void d34();virtual void d35();virtual void d36();virtual void d37();virtual void d38();virtual void d39();
virtual int kind();
};
struct Modules { char pad[0x54]; Obj* item; char p58[0xc]; Obj* work; char p68[8]; Obj* status; char p74[0x10]; Obj* ground; char p88[0x20]; Obj* capture; };
struct Access { char pad[8]; Fighter* fighter; char p0c[0xcc]; Modules* modules; };
struct Params { char pad[0x18]; int limit; };
struct Data { void* a; Params* params; };
extern "C" {
extern char lbl_110_data_5F8[],lbl_110_data_212C[],lbl_110_data_62B8[];
void* __dynamic_cast(void*,long,const void*,const void*,short);
Data* fn_110_8C60(void*);
Data* fn_110_1EF78(void*);
Obj* fn_27_8CD94(void*);
}
extern "C" void fn_110_CCA8(void*,Access* a) {
 Obj* ground=a->modules->ground;
 Obj* capture=a->modules->capture;
 Obj* work=a->modules->work;
 Obj* status=a->modules->status;
 Obj* item=a->modules->item;
 Fighter* fighter=a->fighter;
 Params* params;
 if(fighter->kind()==0x15) {
 Data* d=fn_110_8C60(__dynamic_cast(fighter,0x3c,lbl_110_data_5F8,lbl_110_data_212C,1));
 params=d->params;
 } else {
 Data* d=fn_110_1EF78(__dynamic_cast(fighter,0x3c,lbl_110_data_62B8,lbl_110_data_212C,1));
 params=d->params;
 }
 if(capture->kind()==0x5c) {
 Pair pair;
 capture->pair(&pair);
 Obj* link;
 void* target=pair.b;
 link=fn_27_8CD94(target);
 if(link->test30(7)) {
 work->set(link->get54(7),0x10000044);
 Event event(fighter->id);
 link->send(7,&event,0);
 }
 capture->release(target);
 status->change(0x123,a);
 } else if(item->test2c(7)) {
 status->change(0x122,a);
 } else if(work->get(0x10000043)<params->limit) {
 status->change(0x122,a);
 } else if(ground->ground(0)==1) {
 status->change(0x122,a);
 } else {
 work->set(0,0x10000043);
 work->set(fighter->id,0x10000044);
 status->change(0x121,a);
 }
 work->get54(0x12000041);
}
