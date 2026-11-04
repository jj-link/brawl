#include <so/article/so_article.h>
#pragma force_active on
extern "C" {
extern const char lbl_121_data_7F18[], lbl_121_data_7DA8[], lbl_121_data_7C34[], lbl_121_data_7ACC[], lbl_121_data_7960[], lbl_121_data_35E4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_121_A740();
int fn_27_3A5E2C(void*, void*, int);
int fn_121_A548(void*, int);
}
extern "C" int fn_121_C7A8(void*, int operation, soArticle* article)
{
    short one = 1;
    switch (article->getArticleId()) {
    case 0: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_121_data_7F18, lbl_121_data_35E4, one);
        return 1;
    }
    case 1: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_121_data_7DA8, lbl_121_data_35E4, one);
        return fn_27_3A5E2C(fn_121_A740(), weapon, operation);
    }
    case 2: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_121_data_7C34, lbl_121_data_35E4, one);
        return fn_121_A548(weapon, operation);
    }
    case 3: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_121_data_7ACC, lbl_121_data_35E4, one);
        return 1;
    }
    case 4: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_121_data_7960, lbl_121_data_35E4, one);
        return 1;
    }
    case 5: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_121_data_7ACC, lbl_121_data_35E4, one);
        return 1;
    }
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