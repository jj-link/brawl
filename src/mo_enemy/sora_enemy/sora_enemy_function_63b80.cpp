#include <so/article/so_article.h>
#pragma force_active on

struct ArticleOperationState {
    bool first;
    bool second;
};

extern "C" {
extern const char lbl_41_data_E4[], lbl_41_data_132C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_41_63B80(void*, int, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: {
        ArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_41_data_E4, lbl_41_data_132C, 1);
        return 1;
    }
    case 1: { ArticleOperationState state = {false, false}; return 1; }
    case 2: { ArticleOperationState state = {false, false}; return 1; }
    case 3: { ArticleOperationState state = {false, false}; return 1; }
    case 4: { ArticleOperationState state = {false, false}; return 1; }
    case 5: { ArticleOperationState state = {false, false}; return 1; }
    case 6: { ArticleOperationState state = {false, false}; return 1; }
    case 7: { ArticleOperationState state = {false, false}; return 1; }
    case 8: { ArticleOperationState state = {false, false}; return 1; }
    case 9: { ArticleOperationState state = {false, false}; return 1; }
    case 10: { ArticleOperationState state = {false, false}; return 1; }
    case 11: { ArticleOperationState state = {false, false}; return 1; }
    case 12: { ArticleOperationState state = {false, false}; return 1; }
    case 13: { ArticleOperationState state = {false, false}; return 1; }
    case 14: { ArticleOperationState state = {false, false}; return 1; }
    case 15: { ArticleOperationState state = {false, false}; return 1; }
    case 16: { ArticleOperationState state = {false, false}; return 1; }
    default: return 0;
    }
}
