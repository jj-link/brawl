#pragma force_active on
extern "C" int fn_802A04EC(int, int, int, int, int, void*);
extern "C" int fn_803295B0(void*, void*, int, int, float);
extern "C" void fn_8027CE3C(void*, int);
struct Hdr { unsigned char pad[6]; unsigned short h6; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual int slot3();
 unsigned char pad[0x28];
 Hdr* hdr;
};
struct Obj { int a0,a4,a8; Object_vptr_0* sub; unsigned char pad[0xC]; char type; };
struct Entry { Obj* obj; int b,c; };
struct List { Entry* data; int count; };
struct Arr { Entry* data; int count,cap; };
struct Inner { unsigned char pad[8]; float f8; };
struct Ctx { Inner* inner; int a4,a8,aC,a10,a14,a18,a1C; };
struct Result { unsigned char value; Result(int v) : value(v) {} };
extern "C" Result fn_8032A36C(Ctx* arg0, List* arg1, int arg2, Arr* arg3) {
 char sp8[0x400];
 Entry* out;
 Entry* e;
 int off;
 int i;
 Result ret(1);
 int r31;
 i=0; off=0;
 for (; i<arg1->count; off+=12,i++) {
  e=(Entry*)((char*)arg1->data+off);
  if(e->obj->type==4) {
   r31=fn_803295B0(e,sp8,fn_802A04EC(arg0->a4,e->b,arg0->aC,arg0->a1C,0x100,sp8),arg2,arg0->inner->f8);
   if(r31>=0) {
    if(!arg3) return Result(0);
    ret.value=0;
    if(arg3->count==(arg3->cap&0x3FFFFFFF)) fn_8027CE3C(arg3,12);
    int n=arg3->count;
    out=arg3->data+n;
    arg3->count=n+1;
    out->obj=e->obj;
    if(e->obj->sub->slot3()==11) {
     Object_vptr_0* s=e->obj->sub;
     out->b=(((int)s->hdr+0x37)&~0xF)+(r31<<5);
     out->c=((((int)s->hdr+0x37)&~0xF)+(s->hdr->h6<<5))+r31*20;
    } else { out->b=0; out->c=0; }
   }
  }
 }
 return ret;
}