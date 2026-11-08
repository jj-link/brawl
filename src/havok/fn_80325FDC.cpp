#pragma force_active on
class SoHeapAllocator {
public:
virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
virtual void* alloc(int, int);
};
extern SoHeapAllocator* lbl_805A0EB8;
extern "C" char lbl_80488630[];
extern "C" char lbl_80488CF4[];
extern "C" char lbl_80488D38[];
extern "C" void __ct__14Class_802F0BECFi(void*);
struct Vtable_Class_802F0BEC {
void* vtable;
Vtable_Class_802F0BEC():vtable(lbl_80488630){}
};
class Class_802F0BEC:public Vtable_Class_802F0BEC {
public:

Class_802F0BEC(int);
~Class_802F0BEC() {}
void fn_80080A64();
void fn_802F12D8();
void fn_802F0C48();
void fn_802F0DAC();
char pad04[8];
int m_0C;
char pad10[24];
};
class Class_80326098 {
public:
Class_80326098(){}
~Class_80326098(){}
int m_28,m_2C,m_30;
};
struct Vtable_Class_80325FDC {
Vtable_Class_80325FDC(){*(void**)this=lbl_80488CF4;}
};
class Class_80326078 {
public:
static void operator delete(void*);
static void* operator new(unsigned long size) {
Class_80326078* p=(Class_80326078*)lbl_805A0EB8->alloc(size,0x13);
((unsigned short*)p)[2]=size;
return p;
}
};
struct Vtable_Class_8032BBE8 {
void* vtable;
Vtable_Class_8032BBE8():vtable(lbl_80488D38){}
};
class Class_8032BBE8:public Vtable_Class_8032BBE8,public Class_80326078 {
public:
Class_8032BBE8();
unsigned short type;
char pad[6];
};
class Class_80325FDC:public Class_802F0BEC,public Vtable_Class_80325FDC {
public:
Class_80325FDC();
~Class_80325FDC();
Class_80326098 m_28;
Class_8032BBE8* m_34;
int m_38;
};
inline int unspecified() { int x; return x; }
Class_80325FDC::Class_80325FDC():Class_802F0BEC(unspecified()) {
vtable=lbl_80488CF4;
m_28.m_28=0;
m_28.m_2C=0;
m_28.m_30=0x80000000;
m_0C=1;
Class_8032BBE8* object0=new Class_8032BBE8();
m_34=object0;
m_38=0;
}
