#pragma force_active on
#include <types.h>
struct acCmdArgConv { int argType; int data; };
template<class T> class ArrayBase { public: virtual void v0(); virtual T& at(int); virtual const T& at(int) const; virtual void v3(); virtual void v4(); virtual ~ArrayBase(); };
template<class T> class soArrayContractibleTable:public ArrayBase<T> { public: virtual ~soArrayContractibleTable(); char data[12]; };
class acCmdArg { public: const acCmdArgConv* p; unsigned char n; acCmdArg():p(0),n(0){} };
class acAnimCmd { public: virtual void v0(); virtual signed char getGroup(); virtual signed char getType(); virtual int getArgNum(); virtual void v4(); virtual soArrayContractibleTable<const acCmdArgConv> getArgList(); virtual bool getArg(acCmdArg*,int); };
class soAnimCmdEventObserver { public: virtual void addObserver(); virtual void fn_41_285A0(); virtual void fn_41_28598(); virtual void fn_41_27C1C(); virtual void fn_41_28508(); };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(int,void*,int); };
class Service { public: int a,b; virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual int s32(int); };
struct Arg { const acCmdArgConv* p; unsigned char null; Arg(const acCmdArgConv*q):p(q),null(0){} int address(){return null==1?0:p->data;} };
#pragma inline_depth(8)
#pragma inline_max_size(1000)
inline Arg getArg(const soArrayContractibleTable<const acCmdArgConv>& list,int index){Arg arg(&list.at(index));return arg;}
extern "C" int fn_41_A184(const void*);
extern "C" int fn_41_A1C4(const void*);
extern "C" unsigned int fn_41_A25C(const void*);
inline int argType(Arg a){return fn_41_A1C4(&a);}
inline int argInt(Arg a){return fn_41_A184(&a);}
extern "C" void fn_41_27A68(void*,int);
extern "C" bool fn_27_6EAB8(void*,acAnimCmd*,void*,int);
extern "C" void* fn_41_2842C(void*,void*,const soArrayContractibleTable<const acCmdArgConv>*);
extern "C" int fn_41_28478(void*,int,int,void*);
extern "C" int fn_41_28490(void*,int,int,unsigned int);
extern "C" void* fn_41_284A8(void*,short);
inline void sendValue(void*self,int command,int firstValue,unsigned int secondValue){char result[0x10];int value=fn_41_28490(result,command,firstValue,secondValue);((Object_vptr_0*)self)->slot16(3,(void*)value,0);}
inline void convert(void* converted,void* module,const soArrayContractibleTable<const acCmdArgConv>& list){fn_41_2842C(converted,module,&list);}
struct Event {char data[16];Event(){}};
inline void* makeEvent(const Event& event,int second,int first,void* converted){return (void*)fn_41_28478((void*)&event,second,first,converted);}
inline void* makeEvent(const Event& event,int command,int first,unsigned int second){return (void*)fn_41_28490((void*)&event,command,first,second);}
extern "C" bool fn_41_27C1C(void*self,acAnimCmd*cmd,void*module,int kind){
if(cmd->getGroup()!=0x6e)return fn_27_6EAB8(self,cmd,module,kind);
signed char type=cmd->getType();int count=cmd->getArgNum();
if(type<=-1||type>=7)return false;
switch(type){
case 0:{
if(count<2||count>4)return true;
acCmdArg first;if(!cmd->getArg(&first,0)||fn_41_A1C4(&first)!=0)return true;int firstValue=fn_41_A184(&first);
acCmdArg second;if(!cmd->getArg(&second,1)||fn_41_A1C4(&second)!=0)return true;
char converted[24];
convert(converted,module,cmd->getArgList());
((Object_vptr_0*)self)->slot16(3,makeEvent(Event(),fn_41_A184(&second),firstValue,converted),0);
fn_41_284A8(converted,-1);return true;
}
case 1:{
if(count<2||count>4)return true;
acCmdArg first;if(!cmd->getArg(&first,0)||fn_41_A1C4(&first)!=0)return true;int firstValue=fn_41_A184(&first);
acCmdArg second;if(!cmd->getArg(&second,1)||fn_41_A1C4(&second)!=0)return true;
char converted[24];
convert(converted,module,cmd->getArgList());
((Object_vptr_0*)self)->slot16(3,makeEvent(Event(),fn_41_A184(&second),firstValue,converted),0);
fn_41_284A8(converted,-1);return true;
}
case 2:{
if(count<2||count>2)return true;
acCmdArg first;if(!cmd->getArg(&first,0)||fn_41_A1C4(&first)!=0)return true;int firstValue=fn_41_A184(&first);
acCmdArg second;if(!cmd->getArg(&second,1)||fn_41_A1C4(&second)!=2)return true;
sendValue(self,0x13f4,firstValue,fn_41_A25C(&second));return true;
}
case 3:{
if(count<2||count>2)return true;
acCmdArg first;if(!cmd->getArg(&first,0)||fn_41_A1C4(&first)!=0)return true;int firstValue=fn_41_A184(&first);
acCmdArg second;if(!cmd->getArg(&second,1)||fn_41_A1C4(&second)!=2)return true;
((Object_vptr_0*)self)->slot16(3,makeEvent(Event(),0x13f5,firstValue,fn_41_A25C(&second)),0);return true;
}
case 4:{
if(count<2||count>2)return true;
acCmdArg first;if(!cmd->getArg(&first,0)||fn_41_A1C4(&first)!=0)return true;int firstValue=fn_41_A184(&first);
acCmdArg second;if(!cmd->getArg(&second,1)||fn_41_A1C4(&second)!=2)return true;
((Object_vptr_0*)self)->slot16(3,makeEvent(Event(),0x13f6,firstValue,fn_41_A25C(&second)),0);return true;
}
case 5:case 6:{
if(count<1||count>1)return true;
const soArrayContractibleTable<const acCmdArgConv> lists[1]={cmd->getArgList()};int value=-1;
if(type==5){if(argType(getArg(lists[0],0))!=0)return true;value=argInt(getArg(lists[0],0));}
else if(type==6){if(argType(getArg(lists[0],0))!=4)return true;Service*service=*(Service**)(*(char**)((char*)module+0xd8)+4);value=service->s32(getArg(lists[0],0).address());}
if((unsigned int)value==0xffffffffU)return true;
fn_41_27A68(self,value);return true;
}
}
return false;
}
