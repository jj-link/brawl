#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_112_data_66F0[], lbl_112_data_658C[], lbl_112_data_6424[], lbl_112_data_2080[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_112_A0A4();
int fn_27_35A64C(void*, void*, int);
}

extern "C" int fn_112_BAA4(void*, int operation, soArticle* article)
{
    short one = 1;
    switch (article->getArticleId()) {
    case 0: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_112_data_66F0, lbl_112_data_2080, one);
        return 1;
    }
    case 1: {
        bool flags[2] = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_112_data_658C, lbl_112_data_2080, one);
        return fn_27_35A64C(fn_112_A0A4(), weapon, operation);
    }
    case 2: {
        bool flags[2] = {false, false};
        __dynamic_cast(article, 0, lbl_112_data_6424, lbl_112_data_2080, one);
        return 1;
    }
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
