#pragma force_active on
#pragma opt_propagation off
extern "C" {
struct Data { char a[12]; char b[0x274]; char c[8]; char d[4]; char e[4]; };
extern Data lbl_15_data_0;
extern void* lbl_805A01D8;
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_800B5854(void*, int, int, int, int);
void fn_15_1F78(void*, int);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, const char*);
void fn_800B7224(void*, unsigned int, const char*, int);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void fn_80078DAC(void*, int, int, int);
}
struct Obj {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void call(void*);
};
extern "C" void fn_15_26E8(char* self) {
Data* data=&lbl_15_data_0;
Obj* obj;
char* resource;
char* mdl;
char* name;
int mode;
if (*(int*)(self+0x44)==0) {
mode=0;
obj=*(Obj**)(self+0x194);
resource=*(char**)(self+0x18c);
obj->call(*(void**)(resource+0x10));
Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(obj, *(void**)(resource+0x10), data->b);
} else mode=3;
fn_800B5854(*(void**)(self+0x4c),mode,1,1,0);
fn_15_1F78(self,0);
mdl=*(char**)(self+0x4c);
name=data->e;
void* mat=GetResMat__Q34nw4r3g3d6ResMdlCFPCc(mdl+8,data->c);
fn_800B7224(mdl,*(unsigned int*)((char*)mat+0xc),name,0);
printf__5MuMsgFUlPCce(*(void**)(self+0x24c),1,data->d);
*(int*)(self+0x514)=0;
fn_80078DAC(lbl_805A01D8,0x2a,0,0);
}
