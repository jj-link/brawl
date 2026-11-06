#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_115_data_729C[], lbl_115_data_7138[], lbl_115_data_6FCC[];
extern const char lbl_115_data_6E60[], lbl_115_data_2AF4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
bool fn_115_8F24(void*, void*);
}

namespace {
struct DiddyArticleStatus {
    bool flags[2];
};
}

extern "C" bool fn_115_B630(void*, void* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: {
        DiddyArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_115_data_729C, lbl_115_data_2AF4, 1);
        return true;
    }
    case 1: {
        DiddyArticleStatus status = {{false, false}};
        return fn_115_8F24(__dynamic_cast(article, 0, lbl_115_data_7138, lbl_115_data_2AF4, 1), accesser);
    }
    case 2: {
        DiddyArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_115_data_6FCC, lbl_115_data_2AF4, 1);
        return true;
    }
    case 3: {
        DiddyArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_115_data_6E60, lbl_115_data_2AF4, 1);
        return true;
    }
    case 4: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 5: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 6: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 7: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 8: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 9: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 10: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 11: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 12: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 13: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 14: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 15: { DiddyArticleStatus status = {{false, false}}; return true; }
    case 16: { DiddyArticleStatus status = {{false, false}}; return true; }
    default: return false;
    }
}
