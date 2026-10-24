#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_118_data_601C[], lbl_118_data_5EAC[], lbl_118_data_1B44[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_118_8E00();
int fn_27_39B34C(void*, void*, int);
}

extern "C" int fn_118_B2DC(void*, int operation, soArticle* article)
{
    unsigned int id = article->getArticleId();
    short one = 1;
    switch (id) {
    case 0: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_118_data_601C, lbl_118_data_1B44, one);
        return fn_27_39B34C(fn_118_8E00(), weapon, operation);
    }
    case 1: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_118_data_5EAC, lbl_118_data_1B44, one);
        return 0;
    }
    case 2: { bool flags[2] = {false, false}; return 1; }
    case 3: { bool flags[2] = {false, false}; return 1; }
    case 4: { bool flags[2] = {false, false}; return 1; }
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
