#include <so/article/so_article.h>

// The original dispatch initializes a two-byte state for each article kind.
// Its field meanings are not recovered; neither field is read on this path.
struct NessArticleOperationState {
    bool first;
    bool second;
};

extern "C" {
extern const char lbl_101_data_86A4[], lbl_101_data_853C[], lbl_101_data_83D0[];
extern const char lbl_101_data_8264[], lbl_101_data_80F8[], lbl_101_data_7F90[];
extern const char lbl_101_data_3C24[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_101_C374();
int fn_27_329944(void*, void*, int);
}

extern "C" int fn_101_EA6C(void*, int operation, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: {
        NessArticleOperationState state = {false, false};
        void* weapon = __dynamic_cast(article, 0, lbl_101_data_86A4, lbl_101_data_3C24, 1);
        return fn_27_329944(fn_101_C374(), weapon, operation);
    }
    case 1: {
        NessArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_101_data_853C, lbl_101_data_3C24, 1);
        return 1;
    }
    case 2: {
        NessArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_101_data_83D0, lbl_101_data_3C24, 1);
        return 1;
    }
    case 3: {
        NessArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_101_data_8264, lbl_101_data_3C24, 1);
        return 1;
    }
    case 4: {
        NessArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_101_data_80F8, lbl_101_data_3C24, 1);
        return 1;
    }
    case 5: {
        NessArticleOperationState state = {false, false};
        __dynamic_cast(article, 0, lbl_101_data_7F90, lbl_101_data_3C24, 1);
        return 1;
    }
    case 6: { NessArticleOperationState state = {false, false}; return 1; }
    case 7: { NessArticleOperationState state = {false, false}; return 1; }
    case 8: { NessArticleOperationState state = {false, false}; return 1; }
    case 9: { NessArticleOperationState state = {false, false}; return 1; }
    case 10: { NessArticleOperationState state = {false, false}; return 1; }
    case 11: { NessArticleOperationState state = {false, false}; return 1; }
    case 12: { NessArticleOperationState state = {false, false}; return 1; }
    case 13: { NessArticleOperationState state = {false, false}; return 1; }
    case 14: { NessArticleOperationState state = {false, false}; return 1; }
    case 15: { NessArticleOperationState state = {false, false}; return 1; }
    case 16: { NessArticleOperationState state = {false, false}; return 1; }
    default: return 0;
    }
}
