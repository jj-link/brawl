#pragma force_active on
#include <types.h>
class Object_vptr_0 { public: virtual short slot0(void*); };
struct soEventSystem;
extern "C" soEventSystem* getInstance__13soEventSystemFv();
extern "C" Object_vptr_0* getManager__13soEventSystemFl(soEventSystem*, long);
class soLinkEventObserver;
template<class T> struct soInstanceUnitFullProperty {
 unsigned char d[12];
 soInstanceUnitFullProperty();
 ~soInstanceUnitFullProperty();
};
template<class T,int N> struct soArrayVector { static unsigned char __vt[]; };
template<class T,int N> struct soInstanceManagerFullPropertyVector { static unsigned char __vt[]; };
template<class T> struct soEventUnitWrapper {
 void* vt; short m,e; static unsigned char __vt[];
 soEventUnitWrapper(short a,short b) {
 m=a; vt=__vt; e=b;
 if(a!=-1) { short id=getManager__13soEventSystemFl(getInstance__13soEventSystemFv(),m)->slot0(this); if(id>-1)e=id; }
 }
};
template<class T,int N> struct WorkBase {
 void* vt; unsigned char flag; void* t14;void* t18;void* t1c;void* t20; unsigned int flags;
 WorkBase() {
 flag=0;
 unsigned char* av=soArrayVector<soInstanceUnitFullProperty<T*>,N>::__vt;
 unsigned char* v=soInstanceManagerFullPropertyVector<T*,N>::__vt;
 vt=v;t14=v+0x34;t18=v+0x40;t1c=av;t20=av+0x48;flags&=0x7FFFF;
 }
};
template<class T,int N> struct Work:WorkBase<T,N> {
 soInstanceUnitFullProperty<T*> arr[N]; unsigned char end;
 Work(int){end=0;} ~Work();
};
template<class T,int N> struct EventImpl:soEventUnitWrapper<T> {
 void* wp;
 EventImpl(short a,short b):soEventUnitWrapper<T>(a,b) {wp=(unsigned char*)this+12;}
};
template<class T,int N> struct soEventUnitWithWorkArea:EventImpl<T,N> {
 Work<T,N> w; static unsigned char __vt[];
 soEventUnitWithWorkArea(short,short);
};
template<class T,int N>
soEventUnitWithWorkArea<T,N>::soEventUnitWithWorkArea(short a,short b)
 :EventImpl<T,N>(a,b),w((this->vt=__vt,0)) {}
template soEventUnitWithWorkArea<soLinkEventObserver,4>::soEventUnitWithWorkArea(short,short);
