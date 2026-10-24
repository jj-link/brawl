#include <so/article/so_article.h>
#pragma force_active on

namespace {
struct SonicArticleOperationState {
    bool first;
    bool second;
};
}

extern "C" {
extern const char lbl_123_data_6020[];
extern const char lbl_123_data_1AF4[];
extern const char lbl_123_data_5EA0[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_123_134C4(void*);
}

extern "C" int fn_123_B2B8(void*, int, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: {
        SonicArticleOperationState state = {false, false};
        fn_123_134C4(__dynamic_cast(
            article, 0, lbl_123_data_6020, lbl_123_data_1AF4, 1));
        return 1;
    }
    case 1: {
        SonicArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_123_data_5EA0, lbl_123_data_1AF4, 1);
        return 1;
    }
    case 2: { SonicArticleOperationState state = {false, false}; return 1; }
    case 3: { SonicArticleOperationState state = {false, false}; return 1; }
    case 4: { SonicArticleOperationState state = {false, false}; return 1; }
    case 5: { SonicArticleOperationState state = {false, false}; return 1; }
    case 6: { SonicArticleOperationState state = {false, false}; return 1; }
    case 7: { SonicArticleOperationState state = {false, false}; return 1; }
    case 8: { SonicArticleOperationState state = {false, false}; return 1; }
    case 9: { SonicArticleOperationState state = {false, false}; return 1; }
    case 10: { SonicArticleOperationState state = {false, false}; return 1; }
    case 11: { SonicArticleOperationState state = {false, false}; return 1; }
    case 12: { SonicArticleOperationState state = {false, false}; return 1; }
    case 13: { SonicArticleOperationState state = {false, false}; return 1; }
    case 14: { SonicArticleOperationState state = {false, false}; return 1; }
    case 15: { SonicArticleOperationState state = {false, false}; return 1; }
    case 16: { SonicArticleOperationState state = {false, false}; return 1; }
    default:
        return 0;
    }
}
