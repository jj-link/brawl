#include <types.h>
#pragma force_active on
struct Data {
s32 field0; s16 field4; s16 field6; f32 field8; f32 fieldC; s32 field10; f32 field14;
char pad18[4]; s32 modes[2]; char pad24[8]; s32 field2C; char pad30[4]; u8 field34;
};
class Object_vptr_0 { public: virtual void slot0(); virtual void* slot1(s32 index); };
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base { public:
virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28(); virtual void fn_27_7AB50(); virtual void fn_27_7B2EC(s32*, s32);
};
extern "C" {
void fn_27_362E4(s32,s32);
s32 fn_27_3786C(s32);
s32 fn_27_41968(void*);
s32 fn_27_36028(s32,s32,s32);
u32 fn_27_4182C(void*,void*,f32,s32,s32,s32,u8,s32);
void fn_27_378D0(s32,s32,s32,f32,f32);
}
inline void updateMax(s32& value, s32 candidate) {
if (candidate <= value) return;
value = candidate;
}
extern "C" s32 fn_27_4238C(Data* self,s32 owner,Object_vptr_0* collection,Class_90D8* destination,s32 index,f32 value,f32 scale,f32 finalScale) {
s32* out;
f32 savedScale=finalScale;
s32 id=self->field0;
s32 mode;
s32 values[200];
self->field8=value; self->fieldC=scale; self->field10=index; self->field14=finalScale;
if(id!=-1) {
mode=0;
for (s32 j=0; j<2; ++j) {
    if (self->modes[j]>mode) mode=self->modes[j];
}
fn_27_362E4(owner,id);
if(mode!=3) {
s32 flag=fn_27_3786C(self->field10);
s32 result=0;
if(self->field6>1) {
out=values;
s32 count=0;
for(s32 i=0;i<self->field6;++i) {
s32 found=fn_27_41968(collection->slot1(self->field4+i));
if((u32)(found+0x10000)!=0xFFFFU) { *out++=found; ++count; }
}
if(count>0) destination->fn_27_7B2EC(values,count);
}
for(s32 i=0;i<self->field6;++i) {
out=(s32*)collection->slot1(self->field4+i);
if(fn_27_4182C(out,destination,self->fieldC,fn_27_36028(owner,i,self->field0),mode,flag,self->field34,self->field2C)==1U) result=1;
}
s32 finalFlag=(mode-1)==0;
fn_27_378D0(owner,self->field0,finalFlag,self->field8,savedScale);
return result;
}
}
return 0;
}
