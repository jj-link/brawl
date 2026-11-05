#pragma force_active on
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_41_51E20(void*, void*);
}
namespace {
class soNullable {
public:
 virtual void isNull(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21();
};
class Class_6E20 {
public:
 virtual void fn_41_3516C(); virtual void fn_41_34F30(); virtual void fn_41_350A4();
 virtual void fn_41_350AC(); virtual void fn_41_350B4(); virtual void fn_41_350BC();
 virtual void fn_41_350DC(); virtual void fn_41_350C4(); virtual void fn_41_35120();
 virtual void fn_41_350CC(); virtual void fn_41_350D4(); virtual void fn_41_350E4();
 virtual void fn_41_350EC(); virtual void fn_41_350F0(); virtual void fn_41_350F4();
 virtual void fn_41_350F8(); virtual void fn_41_350FC(); virtual void fn_41_35108();
 virtual void fn_41_3510C(); virtual void fn_41_13638(); virtual void fn_41_34F38();
 virtual void fn_41_34F98();
};
struct ArticleStatus {
 bool flags[2];
 ArticleStatus() { flags[0] = false; flags[1] = false; }
};
struct ArticleActivation {
 unsigned int operator()(soArticle* owner, soModuleAccesser* accesser) const {
  return fn_41_51E20(owner, accesser);
 }
};
struct ArticleDeactivation {
 void operator()(soArticle* owner) const { reinterpret_cast<soNullable*>(owner)->slot21(); }
};
class ArticleSelector {
public:
 soArticle* article;
 ArticleSelector() { fn_27_8D7C4(this); }
 void release(short destroy) { fn_27_8D7D0(this, destroy); }
 bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct ArticleSearch {
 bool operator()(ArticleSelector& selector, soArticle* candidate) const { return selector.select(candidate); }
};
template <unsigned Kind> struct ArticlePool {
 static inline soArticle* find(char*, ArticleSelector&, ArticleSearch) { return 0; }
};
template <> struct ArticlePool<0> {
 static inline soArticle* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
  soArticle* owner;
  if (search(selector, reinterpret_cast<soArticle*>(pool + 0xd8)) == true) owner = reinterpret_cast<soArticle*>(pool + 0xd8);
  else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xac)) == true) owner = reinterpret_cast<soArticle*>(pool + 0xac);
  else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x80)) == true) owner = reinterpret_cast<soArticle*>(pool + 0x80);
  else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x54)) == true) owner = reinterpret_cast<soArticle*>(pool + 0x54);
  else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x28)) == true) owner = reinterpret_cast<soArticle*>(pool + 0x28);
  else owner = 0;
  return owner;
 }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
 const ArticleActivation& activation, const ArticleDeactivation& deactivation) {
 ArticleStatus status;
 if (Kind >= 1) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
 ArticleSelector selector;
 soArticle* owner = ArticlePool<Kind>::find(pool, selector, ArticleSearch());
 if (!owner) {
  owner = selector.article;
  if (!owner) {
   selector.release(-1);
   return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
  }
  deactivation(owner);
 }
 if (activation(owner, accesser) == true) {
  selector.release(-1);
  return *owner;
 }
 selector.release(-1);
 return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}
extern "C" soArticle& fn_41_51F2C(char* pool, unsigned kind, soModuleAccesser* accesser) {
 switch (kind) {
 case 0: return allocateArticle<0>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 1: return allocateArticle<1>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 2: return allocateArticle<2>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 3: return allocateArticle<3>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 4: return allocateArticle<4>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 5: return allocateArticle<5>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 6: return allocateArticle<6>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 7: return allocateArticle<7>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 8: return allocateArticle<8>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 9: return allocateArticle<9>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 10: return allocateArticle<10>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 11: return allocateArticle<11>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 12: return allocateArticle<12>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 13: return allocateArticle<13>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 14: return allocateArticle<14>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 15: return allocateArticle<15>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 case 16: return allocateArticle<16>(pool, accesser, ArticleActivation(), ArticleDeactivation());
 default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
 }
}