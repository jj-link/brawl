#include <so/article/so_article.h>

namespace {
// Each supported kind initializes the original two-byte operation state.
// These fields are not read by this dispatcher.
struct NessThunderArticleOperationState {
    bool first;
    bool second;
};
}

extern "C" {
extern const char lbl_101_data_A8A0[], lbl_101_data_3C24[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_101_19D10(void*, int, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: {
        NessThunderArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_101_data_A8A0, lbl_101_data_3C24, 1);
        return 1;
    }
    case 1: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 2: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 3: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 4: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 5: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 6: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 7: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 8: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 9: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 10: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 11: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 12: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 13: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 14: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 15: { NessThunderArticleOperationState state = {false, false}; return 1; }
    case 16: { NessThunderArticleOperationState state = {false, false}; return 1; }
    default: return 0;
    }
}
