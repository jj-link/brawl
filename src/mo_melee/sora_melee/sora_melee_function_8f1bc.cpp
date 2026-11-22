#pragma force_active on
#include <so/event/so_event_system.h>

typedef soInstanceManagerFixedSimple<
    soEventManager*,
    soInstanceUnit<soEventManager*>,
    soArray<soInstanceUnit<soEventManager*> >
> ManagerSearch;

extern int lbl_27_bss_544;
extern "C" int fn_27_8FA24(ManagerSearch*, int, int, int);

soEventManager* soEventSystem::getManager(s32 key) {
 int branchResult;
 int result;
 int other,high,midpoint;
 if(m_instanceManager.m_fixedSimple.isEmpty()==1U) result=-1;
 else {
 high=m_instanceManager.m_fixedSimple.m_array->size()-1;
midpoint=(0)+((high)-(0))/2;
int value0=m_instanceManager.m_fixedSimple.m_array->at(midpoint).m_id;
if(value0==key) result=midpoint;
else if((0)==(high)) result=-1;
else if(value0<key) {
other=(midpoint+1)+((high)-(midpoint+1))/2;
int value1=m_instanceManager.m_fixedSimple.m_array->at(other).m_id;
if(value1==key) branchResult=other;
else if((midpoint+1)==(high)) branchResult=-1;
else if(value1<key) {
int index2;
midpoint=(other+1)+((high)-(other+1))/2;
int value2=m_instanceManager.m_fixedSimple.m_array->at(midpoint).m_id;
if(value2==key) index2=midpoint;
else if((other+1)==(high)) index2=-1;
else if(value2<key) {
int index3;
other=(midpoint+1)+((high)-(midpoint+1))/2;
int value3=m_instanceManager.m_fixedSimple.m_array->at(other).m_id;
if(value3==key) index3=other;
else if((midpoint+1)==(high)) index3=-1;
else if(value3<key) {
index3=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,other+1,high);
} else if(value3>key) {
index3=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,midpoint+1,other);
} else index3=-1;
index2=index3;
} else if(value2>key) {
int index4;
high=(other+1)+((midpoint)-(other+1))/2;
int value4=m_instanceManager.m_fixedSimple.m_array->at(high).m_id;
if(value4==key) index4=high;
else if((other+1)==(midpoint)) index4=-1;
else if(value4<key) {
index4=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,high+1,midpoint);
} else if(value4>key) {
index4=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,other+1,high);
} else index4=-1;
index2=index4;
} else index2=-1;
branchResult=index2;
} else if(value1>key) {
int index5;
high=(midpoint+1)+((other)-(midpoint+1))/2;
int value5=m_instanceManager.m_fixedSimple.m_array->at(high).m_id;
if(value5==key) index5=high;
else if((midpoint+1)==(other)) index5=-1;
else if(value5<key) {
int index6;
midpoint=(high+1)+((other)-(high+1))/2;
int value6=m_instanceManager.m_fixedSimple.m_array->at(midpoint).m_id;
if(value6==key) index6=midpoint;
else if((high+1)==(other)) index6=-1;
else if(value6<key) {
index6=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,midpoint+1,other);
} else if(value6>key) {
index6=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,high+1,midpoint);
} else index6=-1;
index5=index6;
} else if(value5>key) {
int index7;
other=(midpoint+1)+((high)-(midpoint+1))/2;
int value7=m_instanceManager.m_fixedSimple.m_array->at(other).m_id;
if(value7==key) index7=other;
else if((midpoint+1)==(high)) index7=-1;
else if(value7<key) {
index7=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,other+1,high);
} else if(value7>key) {
index7=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,midpoint+1,other);
} else index7=-1;
index5=index7;
} else index5=-1;
branchResult=index5;
} else branchResult=-1;
result=branchResult;
} else if(value0>key) {
other=(0)+((midpoint)-(0))/2;
int value8=m_instanceManager.m_fixedSimple.m_array->at(other).m_id;
if(value8==key) branchResult=other;
else if((0)==(midpoint)) branchResult=-1;
else if(value8<key) {
int index9;
high=(other+1)+((midpoint)-(other+1))/2;
int value9=m_instanceManager.m_fixedSimple.m_array->at(high).m_id;
if(value9==key) index9=high;
else if((other+1)==(midpoint)) index9=-1;
else if(value9<key) {
int index10;
other=(high+1)+((midpoint)-(high+1))/2;
int value10=m_instanceManager.m_fixedSimple.m_array->at(other).m_id;
if(value10==key) index10=other;
else if((high+1)==(midpoint)) index10=-1;
else if(value10<key) {
index10=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,other+1,midpoint);
} else if(value10>key) {
index10=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,high+1,other);
} else index10=-1;
index9=index10;
} else if(value9>key) {
int index11;
midpoint=(other+1)+((high)-(other+1))/2;
int value11=m_instanceManager.m_fixedSimple.m_array->at(midpoint).m_id;
if(value11==key) index11=midpoint;
else if((other+1)==(high)) index11=-1;
else if(value11<key) {
index11=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,midpoint+1,high);
} else if(value11>key) {
index11=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,other+1,midpoint);
} else index11=-1;
index9=index11;
} else index9=-1;
branchResult=index9;
} else if(value8>key) {
int index12;
midpoint=(0)+((other)-(0))/2;
int value12=m_instanceManager.m_fixedSimple.m_array->at(midpoint).m_id;
if(value12==key) index12=midpoint;
else if((0)==(other)) index12=-1;
else if(value12<key) {
int index13;
high=(midpoint+1)+((other)-(midpoint+1))/2;
int value13=m_instanceManager.m_fixedSimple.m_array->at(high).m_id;
if(value13==key) index13=high;
else if((midpoint+1)==(other)) index13=-1;
else if(value13<key) {
index13=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,high+1,other);
} else if(value13>key) {
index13=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,midpoint+1,high);
} else index13=-1;
index12=index13;
} else if(value12>key) {
int index14;
high=(0)+((midpoint)-(0))/2;
int value14=m_instanceManager.m_fixedSimple.m_array->at(high).m_id;
if(value14==key) index14=high;
else if((0)==(midpoint)) index14=-1;
else if(value14<key) {
index14=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,high+1,midpoint);
} else if(value14>key) {
index14=fn_27_8FA24(&m_instanceManager.m_fixedSimple,key,0,high);
} else index14=-1;
index12=index14;
} else index12=-1;
branchResult=index12;
} else branchResult=-1;
result=branchResult;
} else result=-1;
 }

 if (result < 0) return reinterpret_cast<soEventManager*>(reinterpret_cast<char*>(&lbl_27_bss_544) + 8);
 return m_instanceManager.atIndex(result);
}
