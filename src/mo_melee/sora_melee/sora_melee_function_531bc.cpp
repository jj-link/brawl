#pragma force_active on
struct Element {
    void* pad;
    int key;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Element* slot1(int index);
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_52964();
    virtual void fn_27_53194();
    virtual void fn_27_541C8();
    virtual void fn_27_531A8();
    virtual unsigned int fn_27_54258();

    int pad;
    Object_vptr_0* array;
};

extern "C" int fn_27_539D8(soNullable*, int, int, int);
extern "C" bool fn_27_531BC(soNullable* s,int key) {
 bool valid = key != -1;
 if (valid) {
 int branchResult;
 int result;
 int other,high,midpoint;
 if(s->fn_27_54258()==1U) result=-1;
 else {
 high=s->array->slot3()-1;
midpoint=(0)+((high)-(0))/2;
int value0=s->array->slot1(midpoint)->key;
if(value0==key) result=midpoint;
else if((0)==(high)) result=-1;
else if(value0<key) {
other=(midpoint+1)+((high)-(midpoint+1))/2;
int value1=s->array->slot1(other)->key;
if(value1==key) branchResult=other;
else if((midpoint+1)==(high)) branchResult=-1;
else if(value1<key) {
int index2;
midpoint=(other+1)+((high)-(other+1))/2;
int value2=s->array->slot1(midpoint)->key;
if(value2==key) index2=midpoint;
else if((other+1)==(high)) index2=-1;
else if(value2<key) {
int index3;
other=(midpoint+1)+((high)-(midpoint+1))/2;
int value3=s->array->slot1(other)->key;
if(value3==key) index3=other;
else if((midpoint+1)==(high)) index3=-1;
else if(value3<key) {
index3=fn_27_539D8(s,key,other+1,high);
} else if(value3>key) {
index3=fn_27_539D8(s,key,midpoint+1,other);
} else index3=-1;
index2=index3;
} else if(value2>key) {
int index4;
high=(other+1)+((midpoint)-(other+1))/2;
int value4=s->array->slot1(high)->key;
if(value4==key) index4=high;
else if((other+1)==(midpoint)) index4=-1;
else if(value4<key) {
index4=fn_27_539D8(s,key,high+1,midpoint);
} else if(value4>key) {
index4=fn_27_539D8(s,key,other+1,high);
} else index4=-1;
index2=index4;
} else index2=-1;
branchResult=index2;
} else if(value1>key) {
int index5;
high=(midpoint+1)+((other)-(midpoint+1))/2;
int value5=s->array->slot1(high)->key;
if(value5==key) index5=high;
else if((midpoint+1)==(other)) index5=-1;
else if(value5<key) {
int index6;
midpoint=(high+1)+((other)-(high+1))/2;
int value6=s->array->slot1(midpoint)->key;
if(value6==key) index6=midpoint;
else if((high+1)==(other)) index6=-1;
else if(value6<key) {
index6=fn_27_539D8(s,key,midpoint+1,other);
} else if(value6>key) {
index6=fn_27_539D8(s,key,high+1,midpoint);
} else index6=-1;
index5=index6;
} else if(value5>key) {
int index7;
other=(midpoint+1)+((high)-(midpoint+1))/2;
int value7=s->array->slot1(other)->key;
if(value7==key) index7=other;
else if((midpoint+1)==(high)) index7=-1;
else if(value7<key) {
index7=fn_27_539D8(s,key,other+1,high);
} else if(value7>key) {
index7=fn_27_539D8(s,key,midpoint+1,other);
} else index7=-1;
index5=index7;
} else index5=-1;
branchResult=index5;
} else branchResult=-1;
result=branchResult;
} else if(value0>key) {
other=(0)+((midpoint)-(0))/2;
int value8=s->array->slot1(other)->key;
if(value8==key) branchResult=other;
else if((0)==(midpoint)) branchResult=-1;
else if(value8<key) {
int index9;
high=(other+1)+((midpoint)-(other+1))/2;
int value9=s->array->slot1(high)->key;
if(value9==key) index9=high;
else if((other+1)==(midpoint)) index9=-1;
else if(value9<key) {
int index10;
other=(high+1)+((midpoint)-(high+1))/2;
int value10=s->array->slot1(other)->key;
if(value10==key) index10=other;
else if((high+1)==(midpoint)) index10=-1;
else if(value10<key) {
index10=fn_27_539D8(s,key,other+1,midpoint);
} else if(value10>key) {
index10=fn_27_539D8(s,key,high+1,other);
} else index10=-1;
index9=index10;
} else if(value9>key) {
int index11;
midpoint=(other+1)+((high)-(other+1))/2;
int value11=s->array->slot1(midpoint)->key;
if(value11==key) index11=midpoint;
else if((other+1)==(high)) index11=-1;
else if(value11<key) {
index11=fn_27_539D8(s,key,midpoint+1,high);
} else if(value11>key) {
index11=fn_27_539D8(s,key,other+1,midpoint);
} else index11=-1;
index9=index11;
} else index9=-1;
branchResult=index9;
} else if(value8>key) {
int index12;
midpoint=(0)+((other)-(0))/2;
int value12=s->array->slot1(midpoint)->key;
if(value12==key) index12=midpoint;
else if((0)==(other)) index12=-1;
else if(value12<key) {
int index13;
high=(midpoint+1)+((other)-(midpoint+1))/2;
int value13=s->array->slot1(high)->key;
if(value13==key) index13=high;
else if((midpoint+1)==(other)) index13=-1;
else if(value13<key) {
index13=fn_27_539D8(s,key,high+1,other);
} else if(value13>key) {
index13=fn_27_539D8(s,key,midpoint+1,high);
} else index13=-1;
index12=index13;
} else if(value12>key) {
int index14;
high=(0)+((midpoint)-(0))/2;
int value14=s->array->slot1(high)->key;
if(value14==key) index14=high;
else if((0)==(midpoint)) index14=-1;
else if(value14<key) {
index14=fn_27_539D8(s,key,high+1,midpoint);
} else if(value14>key) {
index14=fn_27_539D8(s,key,0,high);
} else index14=-1;
index12=index14;
} else index12=-1;
branchResult=index12;
} else branchResult=-1;
result=branchResult;
} else result=-1;
 }
 valid = result >= 0;
 }
 return valid;
}