#include <ft/ft_common_data_accesser.h>
#pragma force_active on
class Class_CF88 {
public:
 virtual void fn_94_6CF8();
 virtual void fn_94_1CAF0();
 virtual void fn_94_1DAE0();
 virtual void fn_94_1DAD8();
 virtual void fn_94_1DAD0();
 virtual void fn_94_1DAC8();
 virtual void fn_94_1DAC0();
 virtual void fn_94_1DAB8();
 virtual void fn_94_1DAB0();
 virtual void fn_94_1DAA8();
 virtual void fn_94_1DAA0();
 virtual void fn_94_1DA98();
 virtual void fn_94_1DA90();
 virtual void fn_94_1DA88();
 virtual void fn_94_1DA38();
 virtual void fn_94_1DA80();
 virtual void fn_94_1DA70();
 virtual int fn_94_1DA60(unsigned long);
 virtual void fn_94_1DA50();
 virtual void fn_94_1DA40(unsigned long);
 virtual int fn_94_1DA28(unsigned long);
};
class SitView {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual int getKind();
};
class Mod5cView {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual float getValue();
};
class Mod70View {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void setKind(int, void*);
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual int getKind();
};
class ResultView { public: virtual int check(); };
class Mod84View {
public:
 virtual void s0(); virtual void s1(); virtual void s2();
 virtual ResultView* get(int, int, bool);
 virtual void s4(); virtual void set(int, int, bool);
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
 virtual void s10(); virtual void s11(); virtual void s12();
 virtual void add(ResultView*);
 virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
 virtual void s18(); virtual void s19(); virtual int check(int);
};
struct DataStruct { void* pad[0x2C / 4]; float value; };
struct GetDataResult { void* pad[0x84 / 4]; DataStruct* data; };
struct Mods {
 void* pad00_14[5]; SitView* sit; void* pad18_5C[17]; Mod5cView* mod5c;
 void* pad60_64[1]; Class_CF88* snd; void* pad68_70[2]; Mod70View* mod70;
 void* pad74_84[4]; Mod84View* mod84;
};
struct Holder { void* pad[0xD8 / 4]; Mods* mods; };
extern "C" void fn_94_10144(void* arg1, void* arg2) {
 Holder* holder = static_cast<Holder*>(arg2);
 int kind70 = holder->mods->mod70->getKind();
 Class_CF88* snd = holder->mods->snd;
 int sitKind = holder->mods->sit->getKind();
 if (sitKind == 0) {
  if (snd->fn_94_1DA60(0x22000013) != 0) {
   Mod70View* mod70;
   DataStruct* data;
   data = static_cast<GetDataResult*>((void*)g_ftCommonDataAccesser.getData((ftKind)3))->data;
   mod70 = holder->mods->mod70;
   float value = holder->mods->mod5c->getValue();
   if (value < data->value) {
    snd->fn_94_1DA40(0x22000013);
    mod70->setKind(0x12, arg2);
   }
  }
 }
 if (kind70 != 0x120) {
  if (snd->fn_94_1DA60(0x22000014) != 0) {
   ResultView* result;
   Mod84View* mod84;
   int one = 1;
   int zero = 0;
   mod84 = holder->mods->mod84;
   if (mod84->check(1) != 0) {
    result = mod84->get(one, zero, false);
    if (result->check() == 0) {
     mod84->add(result);
     mod84->set(one, zero, one);
    }
   }
   snd->fn_94_1DA40(0x22000014);
  }
 }
}
