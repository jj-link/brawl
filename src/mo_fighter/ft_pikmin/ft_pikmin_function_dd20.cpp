#include <so/article/so_article.h>
#pragma force_active on

namespace {
// Each supported kind initializes the original two-byte operation state.
// These fields are not read by this dispatcher.
struct PikminArticleOperationState {
    bool first;
    bool second;
};
}

extern "C" {
extern const char lbl_113_data_68B4[], lbl_113_data_6718[], lbl_113_data_65B0[], lbl_113_data_2244[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_113_DD20(void*, int, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: {
        PikminArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_113_data_68B4, lbl_113_data_2244, 1);
        return 1;
    }
    case 1: {
        PikminArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_113_data_6718, lbl_113_data_2244, 1);
        return 1;
    }
    case 2: {
        PikminArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_113_data_65B0, lbl_113_data_2244, 1);
        return 1;
    }
    case 3: { PikminArticleOperationState state = {false, false}; return 1; }
    case 4: { PikminArticleOperationState state = {false, false}; return 1; }
    case 5: { PikminArticleOperationState state = {false, false}; return 1; }
    case 6: { PikminArticleOperationState state = {false, false}; return 1; }
    case 7: { PikminArticleOperationState state = {false, false}; return 1; }
    case 8: { PikminArticleOperationState state = {false, false}; return 1; }
    case 9: { PikminArticleOperationState state = {false, false}; return 1; }
    case 10: { PikminArticleOperationState state = {false, false}; return 1; }
    case 11: { PikminArticleOperationState state = {false, false}; return 1; }
    case 12: { PikminArticleOperationState state = {false, false}; return 1; }
    case 13: { PikminArticleOperationState state = {false, false}; return 1; }
    case 14: { PikminArticleOperationState state = {false, false}; return 1; }
    case 15: { PikminArticleOperationState state = {false, false}; return 1; }
    case 16: { PikminArticleOperationState state = {false, false}; return 1; }
    }
    return 0;
}
