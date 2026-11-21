#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* fn_8027EA20(void*, unsigned int, int);
extern void* lbl_805A0EC8;
struct Elem { char pad[0x44]; int state; };
struct Vec { Elem** data; int size; union { struct { unsigned int noFree:1; unsigned int b:1; unsigned int cap:30; } bf; unsigned int raw; }; bool isOwned() const { return (raw & 0x80000000) == 0; } void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15); } };
struct Obj { char pad[0x4dc]; Vec v; };
extern Obj* lbl_20_bss_8;
inline void copyElements(Vec& dstVec, const Vec& srcVec) { dstVec.size=srcVec.size; int i=0; int* src=(int*)srcVec.data; int* dst=(int*)dstVec.data; for(;i<dstVec.size;i++) dst[i]=src[i]; }
inline int countElements(const Vec& v,int size) { int count=0; if(size!=0) { for(int j=0;j<size;++j) { int s=v.data[j]->state; if(s==4) continue; if(s==3) ++count; } } return count; }
extern "C" int fn_20_2AF4() {
 Obj* obj=lbl_20_bss_8; Vec v; v.data=0; v.size=0; v.raw=0x80000000;
 if((int)v.bf.cap<obj->v.size) { if(!(v.raw&0x80000000)) fn_8027EABC(lbl_805A0EC8,v.data,v.bf.cap<<2,0x15); v.data=(Elem**)fn_8027EA20(lbl_805A0EC8,obj->v.size<<2,0x15); v.raw=obj->v.size|(v.raw&0x40000000); }
 copyElements(v,obj->v); int count=countElements(v,obj->v.size);
 if (v.isOwned()) v.dealloc();
 return count;
}