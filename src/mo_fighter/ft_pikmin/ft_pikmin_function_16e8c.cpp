#pragma force_active on
extern "C" {
void fn_27_C7744(void*, void*, int); void fn_27_D22D0(void*, int); void fn_113_9C84(void*, void*, void*, void*);
void fn_113_9CA0(void*, short, void*, int, int, float, signed char*);
extern float lbl_113_rodata_5C; extern char lbl_27_bss_D8C[]; extern char lbl_27_bss_8C4[];
struct FloatObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual int getValue(); };
struct Holder { char pad[8]; FloatObj obj; }; struct Obj3 { virtual void v0(); virtual void method(void**, short*); };
struct Inner { char pad[0x6C]; Obj3* obj3; char pad2[0x10]; Holder* holder; }; struct B { char pad[0xD8]; Inner* inner; };
struct C { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void* v36(int,int); };
struct Locals { signed char flags[6]; short values[6]; char pad1[2]; void* ptrs[12]; };
void* fn_113_16E8C(void* a, B* b, C* c) {
Locals local; char* ap=(char*)a;
c->v36(0,2); void* t1=c->v36(0,1); void* t0=c->v36(0,0); fn_27_C7744(a,t0,0x34); fn_27_C7744(ap+0x10,t1,0x34); fn_27_D22D0(ap+0x24,0); fn_113_9C84(ap+0xD0,a,ap+0x10,(void*)lbl_27_bss_D8C);
local.flags[5]=0; int val=b->inner->holder->obj.getValue(); fn_113_9CA0(ap+0xEC,(short)val,ap+0x24,0,0,lbl_113_rodata_5C,&local.flags[5]);
local.values[5]=1; local.ptrs[10]=ap+0xEC; local.ptrs[11]=ap+0xD0; b->inner->obj3->method(&local.ptrs[10],&local.values[5]);
c->v36(1,2); c->v36(1,1); c->v36(1,0); fn_27_D22D0(ap+0x140,0); fn_113_9C84(ap+0x1EC,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C);
local.flags[4]=0; val=b->inner->holder->obj.getValue(); fn_113_9CA0(ap+0x208,(short)val,ap+0x140,1,1,lbl_113_rodata_5C,&local.flags[4]);
local.values[4]=2; local.ptrs[8]=ap+0x208; local.ptrs[9]=ap+0x1EC; b->inner->obj3->method(&local.ptrs[8],&local.values[4]);
c->v36(2,2); c->v36(2,1); c->v36(2,0); fn_27_D22D0(ap+0x25C,0); fn_113_9C84(ap+0x308,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C);
local.flags[3]=0; val=b->inner->holder->obj.getValue(); fn_113_9CA0(ap+0x324,(short)val,ap+0x25C,2,1,lbl_113_rodata_5C,&local.flags[3]);
local.values[3]=2; local.ptrs[6]=ap+0x324; local.ptrs[7]=ap+0x308; b->inner->obj3->method(&local.ptrs[6],&local.values[3]);
c->v36(3,2); c->v36(3,1); c->v36(3,0); fn_27_D22D0(ap+0x378,0); fn_113_9C84(ap+0x424,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C);
local.flags[2]=0; val=b->inner->holder->obj.getValue(); fn_113_9CA0(ap+0x440,(short)val,ap+0x378,3,1,lbl_113_rodata_5C,&local.flags[2]);
local.values[2]=2; local.ptrs[4]=ap+0x440; local.ptrs[5]=ap+0x424; b->inner->obj3->method(&local.ptrs[4],&local.values[2]);
char* temp=(char*)ap+0x490; local.flags[1]=1; val=b->inner->holder->obj.getValue(); fn_113_9CA0(temp,(short)val,temp+0x50,4,1,lbl_113_rodata_5C,&local.flags[1]); fn_27_D22D0(temp+0x50,0);
local.values[1]=4; local.ptrs[2]=temp; local.ptrs[3]=lbl_27_bss_8C4; b->inner->obj3->method(&local.ptrs[2],&local.values[1]);
c->v36(5,2); c->v36(5,1); void* t5=c->v36(5,0); char* bp=ap+0x58C; fn_27_C7744(bp,t5,1); fn_27_D22D0(bp+0x14,0); fn_113_9C84(bp+0xC0,bp,(void*)lbl_27_bss_D8C,(void*)lbl_27_bss_D8C);
local.flags[0]=0; val=b->inner->holder->obj.getValue(); fn_113_9CA0(bp+0xDC,(short)val,bp+0x14,5,1,lbl_113_rodata_5C,&local.flags[0]);
local.values[0]=0x10; local.ptrs[0]=bp+0xDC; local.ptrs[1]=bp+0xC0; b->inner->obj3->method(&local.ptrs[0],&local.values[0]); return a;
}
}