#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
extern const char lbl_96_data_ADBC[], lbl_96_data_AC4C[], lbl_96_data_AAD8[];
extern const char lbl_96_data_A96C[], lbl_96_data_A804[], lbl_96_data_A69C[];
extern const char lbl_96_data_A538[], lbl_96_data_6194[], lbl_96_data_608[], lbl_96_data_68D8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
class Class_5B50 {
public:
 virtual void fn_96_28D0(); virtual void fn_96_23A8(); virtual void fn_96_F31C(); virtual void fn_96_F314();
 virtual bool fn_96_F30C(soArticle*, soModuleAccesser*);
 virtual void fn_96_F304(); virtual void fn_96_F2FC();
};
struct Accesser { char pad[8]; void* object; };
inline bool invoke(Class_5B50* p, soArticle* a, Accesser* b) { return p->fn_96_F30C(a, (soModuleAccesser*)b); }
extern "C" bool fn_96_11000(void*, Accesser* accesser, soArticle* article) {
 switch ((unsigned)article->getArticleId()) {
 case 0: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_ADBC, lbl_96_data_6194, 1); return true; }
 case 1: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_AC4C, lbl_96_data_6194, 1); return true; }
 case 2: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_AAD8, lbl_96_data_6194, 1); return true; }
 case 3: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A96C, lbl_96_data_6194, 1); return true; }
 case 4: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A804, lbl_96_data_6194, 1); return true; }
 case 5: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A69C, lbl_96_data_6194, 1); return true; }
 case 6: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A538, lbl_96_data_6194, 1); return true; }
 case 7: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A538, lbl_96_data_6194, 1); return true; }
 case 8: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A538, lbl_96_data_6194, 1); return true; }
 case 9: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A538, lbl_96_data_6194, 1); return true; }
 case 10: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_96_data_A538, lbl_96_data_6194, 1); return true; }
 case 11: {
  bool flags[2] = {false, false};
  void* p = __dynamic_cast(accesser->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 0);
  if (!p) return false;
  return invoke((Class_5B50*)((char*)p + 0x1b72c), article, accesser);
 }
 case 12: { bool flags[2] = {false, false}; return true; }
 case 13: { bool flags[2] = {false, false}; return true; }
 case 14: { bool flags[2] = {false, false}; return true; }
 case 15: { bool flags[2] = {false, false}; return true; }
 case 16: { bool flags[2] = {false, false}; return true; }
 default: return false;
 }
}