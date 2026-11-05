#pragma force_active on
extern "C" const double lbl_49_rodata_B0;
extern "C" const float lbl_49_rodata_B8;
struct Result { float rate; float pad; float max_val; float pad2; float pad3; float multiplier; char padding[0x18]; unsigned char flag; };
struct Elem { char padding[0x2C]; unsigned char flag; unsigned char state; char padding2[6]; };
struct Self_base { char padding[0x3C]; };
class Self : public Self_base {
public:
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual Result* getRate();
 char padding2[0x148]; unsigned char index; char padding3[0xC3]; float position; char padding4[4]; Elem* elems;
};
extern "C" void fn_49_2CD4(Self* self, float delta) {
 Result* result=self->getRate();
 if(result) {
  float val=result->rate*delta; float max=result->max_val;
  Elem* elem=&self->elems[self->index];
  int state=(int)elem->state;
  if(state==1) goto special;
  if(state<1) goto done;
  if(state>=4) goto done;
  goto common;
special:
  if((float)elem->flag>lbl_49_rodata_B8*(float)result->flag) { val*=result->multiplier; max*=result->multiplier; }
  self->position+=val*delta;
  if(self->position>max) self->position=max;
  goto done;
common:
  self->position+=val*delta;
  if(self->position>max) self->position=max;
done:
  ;
 }
}