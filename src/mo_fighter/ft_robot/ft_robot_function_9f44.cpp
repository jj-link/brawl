#include <wn/weapon.h>
#include <so/article/so_article.h>
#pragma force_active on

class Object_vptr_0 {
public:
 virtual void fn_120_5CB0();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual int slot15();
};
struct Base { int a; int b; };
class MainObj : public Base {
public:
 virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
 virtual Object_vptr_0* m4();
};
struct Wrapper { MainObj* obj; };
struct RobotInput { char pad[0xd8]; Wrapper* wrapper; };
extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_120_85D4(Weapon*, RobotInput*);
unsigned int fn_120_8728(Weapon*, RobotInput*);
unsigned int fn_120_8878(Weapon*, RobotInput*);
int* fn_120_7F08();
unsigned int fn_27_3A313C(void*, Weapon*, RobotInput*, int);
}
namespace {
struct Status { bool flags[2]; Status() { flags[0]=false; flags[1]=false; } };
template <unsigned Kind> struct Activation {
 unsigned int operator()(Weapon* owner, RobotInput* input) const {
  if (Kind == 0) return fn_120_85D4(owner,input);
  if (Kind == 1) {
   int id = input->wrapper->obj->m4()->slot15();
   return fn_27_3A313C(fn_120_7F08(),owner,input,id);
  }
  if (Kind == 2) return fn_120_8728(owner,input);
  return fn_120_8878(owner,input);
 }
};
struct Deactivation { void operator()(Weapon* owner) const { owner->deactivateArticle(); } };
class Selector {
public:
 soArticle* article;
 Selector() { fn_27_8D7C4(this); }
 void release(short destroy) { fn_27_8D7D0(this,destroy); }
 bool select(soArticle* candidate) { return fn_27_8D810(this,candidate); }
};
struct Search { bool operator()(Selector& selector, soArticle* candidate) const { return selector.select(candidate); } };
template <unsigned Kind> struct Pool { static inline Weapon* find(char*, Selector&, Search) { return 0; } };
template <> struct Pool<0> {
 static inline Weapon* find(char* p, Selector& s, Search f) {
  if (f(s,reinterpret_cast<soArticle*>(p+0x7f14)) == true) return reinterpret_cast<Weapon*>(p+0x7e8c);
  return 0;
 }
};
template <> struct Pool<1> {
 static inline Weapon* find(char* p, Selector& s, Search f) {
  if (f(s,reinterpret_cast<soArticle*>(p+0x5ee8)) == true) return reinterpret_cast<Weapon*>(p+0x5e60);
  if (f(s,reinterpret_cast<soArticle*>(p+0x3ec4)) == true) return reinterpret_cast<Weapon*>(p+0x3e3c);
  return 0;
 }
};
template <> struct Pool<2> {
 static inline Weapon* find(char* p, Selector& s, Search f) {
  return f(s,reinterpret_cast<soArticle*>(p+0x22b8)) == true ? reinterpret_cast<Weapon*>(p+0x2230) : 0;
 }
};
template <> struct Pool<3> {
 static inline Weapon* find(char* p, Selector& s, Search f) {
  return f(s,reinterpret_cast<soArticle*>(p+0xa0)) == true ? reinterpret_cast<Weapon*>(p+0x18) : 0;
 }
};
template <unsigned Kind>
inline soArticle* allocate(char* p, RobotInput* input, const Activation<Kind>& activation, const Deactivation& deactivation) {
 Status status;
 if (Kind >= 4) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
 Selector selector;
 Weapon* owner = Pool<Kind>::find(p,selector,Search());
 if (!owner) {
  owner = reinterpret_cast<Weapon*>(selector.article);
  if (owner) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
  if (!owner) { selector.release(-1); return reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
  deactivation(owner);
 }
 if (activation(owner,input) == 1) {
  selector.release(-1);
  return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner)+0x88);
 }
 selector.release(-1);
 return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}
extern "C" soArticle* fn_120_9F44(char* p, unsigned kind, RobotInput* input) {
 switch(kind) {
 case 0: return allocate<0>(p,input,Activation<0>(),Deactivation());
 case 1: return allocate<1>(p,input,Activation<1>(),Deactivation());
 case 2: return allocate<2>(p,input,Activation<2>(),Deactivation());
 case 3: return allocate<3>(p,input,Activation<3>(),Deactivation());
 case 4: return allocate<4>(p,input,Activation<4>(),Deactivation());
 case 5: return allocate<5>(p,input,Activation<5>(),Deactivation());
 case 6: return allocate<6>(p,input,Activation<6>(),Deactivation());
 case 7: return allocate<7>(p,input,Activation<7>(),Deactivation());
 case 8: return allocate<8>(p,input,Activation<8>(),Deactivation());
 case 9: return allocate<9>(p,input,Activation<9>(),Deactivation());
 case 10: return allocate<10>(p,input,Activation<10>(),Deactivation());
 case 11: return allocate<11>(p,input,Activation<11>(),Deactivation());
 case 12: return allocate<12>(p,input,Activation<12>(),Deactivation());
 case 13: return allocate<13>(p,input,Activation<13>(),Deactivation());
 case 14: return allocate<14>(p,input,Activation<14>(),Deactivation());
 case 15: return allocate<15>(p,input,Activation<15>(),Deactivation());
 case 16: return allocate<16>(p,input,Activation<16>(),Deactivation());
 default: return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
 }
}
