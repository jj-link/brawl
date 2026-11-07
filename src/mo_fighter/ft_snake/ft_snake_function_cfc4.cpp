#include <so/so_module_accesser.h>
#pragma force_active on
struct Article {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual int task(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual unsigned status(int);
};
struct Manager {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual int exists(int); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual Article* get(int);
};
struct Link {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void send(int,int,void*);
};
struct Info { int id; char flag; };
extern "C" {
void fn_27_13138C(void*, int, int, void*, soModuleAccesser*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_122_22F08(char*);
extern char lbl_122_data_7CF8[], lbl_122_data_7B8C[], lbl_122_data_8554[];
}
extern "C" void fn_122_CFC4(void* self, int a, int b, void* c, soModuleAccesser* acc) {
 fn_27_13138C(self,a,b,c,acc);
 if (a == 0x32) {
  Article* p = ((Manager*)acc->m_enumerationStart->m_generateArticleManageModule)->get(1);
  char* q = (char*)__dynamic_cast(p,0,lbl_122_data_7CF8,lbl_122_data_8554,0);
  if (q) *(float*)(q+0x7ce4) = acc->getWorkManageModule().getFloat(0x21000000);
 } else if (a == 0x121) {
  Article* p = ((Manager*)acc->m_enumerationStart->m_generateArticleManageModule)->get(6);
  char* q = (char*)__dynamic_cast(p,0,lbl_122_data_7B8C,lbl_122_data_8554,0);
  if (q) fn_122_22F08(q);
 }
 if (b == 0x12f) {
  if (((Manager*)(*(soModuleAccesser**)((char*)self+0x60))->m_enumerationStart->m_generateArticleManageModule)->exists(4)) {
   acc = (soModuleAccesser*)((Manager*)(*(soModuleAccesser**)((char*)self+0x60))->m_enumerationStart->m_generateArticleManageModule)->get(4);
   if (acc && ((Article*)acc)->status(0)==1) {
    Info info; info.id=0x839; info.flag=0;
    Link* link=(Link*)(*(soModuleAccesser**)((char*)self+0x60))->m_enumerationStart->m_linkModule;
    link->send(3,((Article*)acc)->task(),&info);
   }
  }
 }
}