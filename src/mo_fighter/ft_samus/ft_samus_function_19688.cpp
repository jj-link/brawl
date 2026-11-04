#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_94_data_C4A8[], lbl_94_data_C328[], lbl_94_data_C1B0[];
extern const char lbl_94_data_C044[], lbl_94_data_4904[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
bool fn_94_18384(void*, void*);
}

namespace {
struct SamusArticleStatus {
    bool flags[2];
};
}

extern "C" bool fn_94_19688(void* self, soModuleAccesser* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: {
        SamusArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_94_data_C4A8, lbl_94_data_4904, 1);
        return true;
    }
    case 1: {
        SamusArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_94_data_C328, lbl_94_data_4904, 1);
        return true;
    }
    case 2: {
        SamusArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_94_data_C1B0, lbl_94_data_4904, 1);
        return true;
    }
    case 3: {
        SamusArticleStatus status = {{false, false}};
        return fn_94_18384(__dynamic_cast(article, 0, lbl_94_data_C044, lbl_94_data_4904, 1), accesser);
    }
    case 4: { SamusArticleStatus status = {{false, false}}; return true; }
    case 5: { SamusArticleStatus status = {{false, false}}; return true; }
    case 6: { SamusArticleStatus status = {{false, false}}; return true; }
    case 7: { SamusArticleStatus status = {{false, false}}; return true; }
    case 8: { SamusArticleStatus status = {{false, false}}; return true; }
    case 9: { SamusArticleStatus status = {{false, false}}; return true; }
    case 10: { SamusArticleStatus status = {{false, false}}; return true; }
    case 11: { SamusArticleStatus status = {{false, false}}; return true; }
    case 12: { SamusArticleStatus status = {{false, false}}; return true; }
    case 13: { SamusArticleStatus status = {{false, false}}; return true; }
    case 14: { SamusArticleStatus status = {{false, false}}; return true; }
    case 15: { SamusArticleStatus status = {{false, false}}; return true; }
    case 16: { SamusArticleStatus status = {{false, false}}; return true; }
    default: return false;
    }
}
