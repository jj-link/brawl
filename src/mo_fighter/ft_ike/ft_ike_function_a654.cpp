#include <so/article/so_article.h>
#pragma force_active on

struct IkeArticleState {
    bool first;
    bool second;
};

extern "C" {
extern unsigned char lbl_119_data_5A6C[8];
extern unsigned char lbl_119_data_1708[8];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_119_7980(void*, int);
}

extern "C" int fn_119_A654(int arg1, int arg2, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: {
        IkeArticleState state = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_119_data_5A6C, lbl_119_data_1708, 1);
        return fn_119_7980(weapon, arg2);
    }
    case 1: { IkeArticleState state = {false, false}; return 1; }
    case 2: { IkeArticleState state = {false, false}; return 1; }
    case 3: { IkeArticleState state = {false, false}; return 1; }
    case 4: { IkeArticleState state = {false, false}; return 1; }
    case 5: { IkeArticleState state = {false, false}; return 1; }
    case 6: { IkeArticleState state = {false, false}; return 1; }
    case 7: { IkeArticleState state = {false, false}; return 1; }
    case 8: { IkeArticleState state = {false, false}; return 1; }
    case 9: { IkeArticleState state = {false, false}; return 1; }
    case 10: { IkeArticleState state = {false, false}; return 1; }
    case 11: { IkeArticleState state = {false, false}; return 1; }
    case 12: { IkeArticleState state = {false, false}; return 1; }
    case 13: { IkeArticleState state = {false, false}; return 1; }
    case 14: { IkeArticleState state = {false, false}; return 1; }
    case 15: { IkeArticleState state = {false, false}; return 1; }
    case 16: { IkeArticleState state = {false, false}; return 1; }
    default: return 0;
    }
}
