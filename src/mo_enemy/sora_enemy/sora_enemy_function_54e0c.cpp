#include <so/article/so_article.h>
#pragma force_active on

namespace {
struct SoraEnemyArticleOperationState {
    bool first;
    bool second;
};
}

extern "C" {
extern const char lbl_41_data_E4[], lbl_41_data_132C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" int fn_41_54E0C(void*, int, soArticle* article)
{
    switch (static_cast<unsigned>(article->getArticleId())) {
    case 0: {
        SoraEnemyArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_41_data_E4, lbl_41_data_132C, 1);
        return 1;
    }
    case 1: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 2: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 3: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 4: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 5: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 6: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 7: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 8: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 9: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 10: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 11: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 12: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 13: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 14: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 15: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    case 16: { SoraEnemyArticleOperationState state = {false, false}; return 1; }
    default: return 0;
    }
}
