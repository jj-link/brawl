#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
extern const char lbl_114_data_7E94[], lbl_114_data_7D2C[], lbl_114_data_7BC0[], lbl_114_data_7A4C[], lbl_114_data_78DC[], lbl_114_data_3570[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_114_BE0C();
int fn_27_3615D0(void*, void*, int);
}
extern "C" int fn_114_E338(void*, int operation, soArticle* article) {
    short one = 1;
    switch (article->getArticleId()) {
    case 0: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_114_data_7E94, lbl_114_data_3570, one);
        return fn_27_3615D0(fn_114_BE0C(), weapon, operation);
    }
    case 1: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_114_data_7D2C, lbl_114_data_3570, one); return 1; }
    case 2: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_114_data_7BC0, lbl_114_data_3570, one); return 1; }
    case 3: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_114_data_7A4C, lbl_114_data_3570, one); return 1; }
    case 4: { bool flags[2] = {false, false}; __dynamic_cast(article, 0, lbl_114_data_78DC, lbl_114_data_3570, one); return 1; }
    case 5: { bool flags[2] = {false, false}; return 1; }
    case 6: { bool flags[2] = {false, false}; return 1; }
    case 7: { bool flags[2] = {false, false}; return 1; }
    case 8: { bool flags[2] = {false, false}; return 1; }
    case 9: { bool flags[2] = {false, false}; return 1; }
    case 10: { bool flags[2] = {false, false}; return 1; }
    case 11: { bool flags[2] = {false, false}; return 1; }
    case 12: { bool flags[2] = {false, false}; return 1; }
    case 13: { bool flags[2] = {false, false}; return 1; }
    case 14: { bool flags[2] = {false, false}; return 1; }
    case 15: { bool flags[2] = {false, false}; return 1; }
    case 16: { bool flags[2] = {false, false}; return 1; }
    default: return 0;
    }
}