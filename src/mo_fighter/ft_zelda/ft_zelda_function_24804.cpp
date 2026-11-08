#include <so/so_module_accesser.h>
#pragma force_active on
#define TEN(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7(); virtual void n##8(); virtual void n##9();
struct Prefix { char pad[8]; };
struct Physics : Prefix {
 TEN(a) TEN(b)
 virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8();
 virtual void set1(int);
 virtual void set3(float,float,float);
 virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8();
 virtual void set8(int);
 TEN(e)
 virtual void f0(); virtual void f1(); virtual void f2();
 virtual void finish();
};
struct W0 { TEN(a) TEN(b) virtual void c0(); virtual void c1(); virtual void call(); };
struct W1 { TEN(a) TEN(b) TEN(c) TEN(d) TEN(e) TEN(f) TEN(g) TEN(h)
 virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4(); virtual void i5(); virtual void i6(); virtual void call(int);
};
struct WWork { TEN(a) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3(); virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7(); virtual void b8(); virtual void call(unsigned int); };
struct CastResult { char pad[0x20e4]; float* data; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1DA698(void*, int, int, int);
extern const char lbl_104_data_BEC4[], lbl_104_data_2EDC[];
}
extern "C" void fn_104_24804(void*, soModuleAccesser* accesser) {
 float* data;
 CastResult* object = static_cast<CastResult*>(__dynamic_cast(*reinterpret_cast<void**>(reinterpret_cast<char*>(accesser)+8), 0x3c, lbl_104_data_BEC4, lbl_104_data_2EDC, 1));
 data = object->data;
 reinterpret_cast<W1*>(accesser->m_enumerationStart->m_linkModule)->call(1);
 fn_27_1DA698(object,-1,-1,-1);
 Physics* physics = static_cast<Physics*>(accesser->m_enumerationStart->m_physicsModule);
 reinterpret_cast<W0*>(accesser->m_enumerationStart->m_postureModule)->call();
 physics->finish();
 static_cast<Physics*>(accesser->m_enumerationStart->m_physicsModule)->set8(8);
 static_cast<Physics*>(accesser->m_enumerationStart->m_physicsModule)->set1(1);
 static_cast<Physics*>(accesser->m_enumerationStart->m_physicsModule)->set3(data[1],data[2],data[3]);
 reinterpret_cast<WWork*>(accesser->m_enumerationStart->m_workManageModule)->call(0x12000004);
}