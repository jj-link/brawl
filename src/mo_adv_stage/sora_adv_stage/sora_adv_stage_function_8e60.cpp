#pragma force_active on
typedef unsigned long u32; typedef unsigned char u8; typedef short s16; typedef int s32; typedef float f32;

struct Stage { char pad[0x1A0]; void* resource; char pad1A4[0x1C]; u8* table; };
struct Count { u32 pad; u32 count; };
struct Entry { char pad[0x78]; f32 value; u8 kind; char pad1[0x90-0x7D]; s16 result; };
struct Container { virtual void f0(); virtual void f1(); virtual void f2(); virtual Entry* get(u32); u32 pad; Count* data; };
struct GroundBase { char pad[0x3C]; };
struct Ground : GroundBase {
virtual void s01(); virtual void s02(); virtual void s03(); virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07(); virtual void s08();
virtual void s09(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32();
virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36();
virtual void s38(); virtual void setup(void*,u32,u32);
virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63();
virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71();
virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
virtual void s80(); virtual void s81(); virtual void s82();
virtual void setEntry(Entry*);
};
struct GlobalSub { char pad[0x5FD]; u8 frame; char pad2[0x4916-0x5FE]; u8 stageFrame; };
struct Global { char pad[0x30]; GlobalSub* sub; };
extern "C" {
extern Global* g_GameGlobal; extern char lbl_40_data_3B8[];
extern const f32 lbl_40_rodata_68;
Ground* fn_40_35ACC(s16,const char*); void addGround__5StageFP6Ground(Stage*,Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*,u32,u32);
void fn_40_8E60(Stage* stage,u32 type,void* multi) {
Ground* ground; Container* container; u32 index=0;
while ((container=searchContainer__20stDataMultiContainerFUlUl(multi,type,index++))!=0) {
for(u32 i=0;i<container->data->count;++i) {
Entry* entry=container->get(i);
ground=fn_40_35ACC((s16)entry->kind,lbl_40_data_3B8);
if(stage->table!=0) {
GlobalSub* sub=g_GameGlobal->sub; s32 frame=sub->frame; s32 lower=frame-5; s32 value=frame-sub->stageFrame;
if(value<lower)value=lower; if(value<0)value=0; if(value>14)value=14;
u8 offset=(u8)value;
entry->result=(s16)(entry->value*(float)stage->table[offset+0x9E]);
} else entry->result=(s16)entry->value;
if(ground!=0){addGround__5StageFP6Ground(stage,ground);ground->setEntry(entry);ground->setup(stage->resource,0,0);}
}
}
}
}
