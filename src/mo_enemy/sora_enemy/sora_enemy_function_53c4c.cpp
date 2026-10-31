#include <so/article/so_article.h>
#pragma force_active on

namespace {
struct ArticleStatus {
    bool first;
    bool second;
};
}

extern "C" {
extern const char lbl_41_data_E4[];
extern const char lbl_41_data_132C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_41_53C4C(void*, void*, soArticle* article)
{
    switch (static_cast<unsigned>(article->getArticleId())) {
    case 0: {
        ArticleStatus status = {false, false};
        __dynamic_cast(article, 0, lbl_41_data_E4, lbl_41_data_132C, 1);
        return 1;
    }
    case 1: { ArticleStatus status = {false, false}; return 1; }
    case 2: { ArticleStatus status = {false, false}; return 1; }
    case 3: { ArticleStatus status = {false, false}; return 1; }
    case 4: { ArticleStatus status = {false, false}; return 1; }
    case 5: { ArticleStatus status = {false, false}; return 1; }
    case 6: { ArticleStatus status = {false, false}; return 1; }
    case 7: { ArticleStatus status = {false, false}; return 1; }
    case 8: { ArticleStatus status = {false, false}; return 1; }
    case 9: { ArticleStatus status = {false, false}; return 1; }
    case 10: { ArticleStatus status = {false, false}; return 1; }
    case 11: { ArticleStatus status = {false, false}; return 1; }
    case 12: { ArticleStatus status = {false, false}; return 1; }
    case 13: { ArticleStatus status = {false, false}; return 1; }
    case 14: { ArticleStatus status = {false, false}; return 1; }
    case 15: { ArticleStatus status = {false, false}; return 1; }
    case 16: { ArticleStatus status = {false, false}; return 1; }
    default:
        return 0;
    }
}
