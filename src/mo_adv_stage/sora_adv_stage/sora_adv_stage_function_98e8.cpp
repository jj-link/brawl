#pragma force_active on
typedef unsigned int u32; typedef unsigned char u8; typedef short s16;
struct Stage { char pad[0x1A0]; void* resource; char pad1A4[0x1C]; u8* table; };
struct Count { u32 pad; u32 count; };
struct Entry { char pad[0x44]; u8 kind; char pad2[0x1EC-0x45]; float value; char pad3[0x240-0x1F0]; int result; };
struct Container { virtual void f0(); virtual void f1(); virtual void f2(); virtual Entry* get(u32); u32 pad; Count* data; };
struct GroundBase { char pad[0x3C]; };
struct Ground : GroundBase {
virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23();
virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31();
virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void setup(void*,u32,u32);
virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44(); virtual void f45();
virtual void f46(); virtual void f47(); virtual void f48(); virtual void f49(); virtual void f50(); virtual void f51(); virtual void f52(); virtual void f53();
virtual void f54(); virtual void f55(); virtual void f56(); virtual void f57(); virtual void f58(); virtual void f59(); virtual void f60(); virtual void f61();
virtual void f62(); virtual void f63(); virtual void f64(); virtual void f65(); virtual void f66(); virtual void f67(); virtual void f68(); virtual void f69();
virtual void f70(); virtual void f71(); virtual void f72(); virtual void f73(); virtual void f74(); virtual void f75(); virtual void f76(); virtual void f77();
virtual void f78(); virtual void f79(); virtual void setEntry(Entry*);
};
struct GlobalSub { char pad[0x5FD]; u8 frame; char pad2[0x4916-0x5FE]; u8 stageFrame; };
struct Global { char pad[0x30]; GlobalSub* sub; };
extern "C" {
extern Global* g_GameGlobal; extern char lbl_40_data_3FC[];
Ground* fn_40_38488(s16,const char*); void addGround__5StageFP6Ground(Stage*,Ground*);
Container* searchContainer__20stDataMultiContainerFUlUl(void*,u32,u32);
void fn_40_98E8(Stage* stage,u32 type,void* multi) {
Ground* ground; Container* container; u32 index=0;
while ((container=searchContainer__20stDataMultiContainerFUlUl(multi,type,index++))!=0) {
for(u32 i=0;i<container->data->count;++i) {
Entry* entry=container->get(i);
ground=fn_40_38488((s16)entry->kind,lbl_40_data_3FC);
if(stage->table!=0) {
GlobalSub* sub=g_GameGlobal->sub; int frame=sub->frame; int lower=frame-5; int value=frame-sub->stageFrame;
if(value<lower)value=lower; if(value<0)value=0; if(value>14)value=14;
u8 offset=(u8)value;
entry->result=(int)(entry->value*(float)stage->table[offset+0x80]);
} else entry->result=(int)entry->value;
if(ground!=0){addGround__5StageFP6Ground(stage,ground);ground->setEntry(entry);ground->setup(stage->resource,0,0);}
}
}
}
}
