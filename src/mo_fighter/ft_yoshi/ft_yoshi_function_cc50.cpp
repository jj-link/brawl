#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_95_data_78E0[], lbl_95_data_777C[], lbl_95_data_7614[];
extern const char lbl_95_data_74AC[], lbl_95_data_733C[], lbl_95_data_2FCC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
bool fn_95_A67C(void*, soModuleAccesser*);
}

namespace {
struct FighterArticleFlags {
    bool flags[2];
};
}

extern "C" bool fn_95_CC50(void*, soModuleAccesser* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: {
        FighterArticleFlags status = {{false, false}};
        __dynamic_cast(article, 0, lbl_95_data_78E0, lbl_95_data_2FCC, 1);
        return true;
    }
    case 1: {
        FighterArticleFlags status = {{false, false}};
        return fn_95_A67C(__dynamic_cast(article, 0, lbl_95_data_777C, lbl_95_data_2FCC, 1), accesser);
    }
    case 2: {
        FighterArticleFlags status = {{false, false}};
        __dynamic_cast(article, 0, lbl_95_data_7614, lbl_95_data_2FCC, 1);
        return true;
    }
    case 3: {
        FighterArticleFlags status = {{false, false}};
        __dynamic_cast(article, 0, lbl_95_data_74AC, lbl_95_data_2FCC, 1);
        return true;
    }
    case 4: {
        FighterArticleFlags status = {{false, false}};
        __dynamic_cast(article, 0, lbl_95_data_733C, lbl_95_data_2FCC, 1);
        return true;
    }
    case 5: { FighterArticleFlags status = {{false, false}}; return true; }
    case 6: { FighterArticleFlags status = {{false, false}}; return true; }
    case 7: { FighterArticleFlags status = {{false, false}}; return true; }
    case 8: { FighterArticleFlags status = {{false, false}}; return true; }
    case 9: { FighterArticleFlags status = {{false, false}}; return true; }
    case 10: { FighterArticleFlags status = {{false, false}}; return true; }
    case 11: { FighterArticleFlags status = {{false, false}}; return true; }
    case 12: { FighterArticleFlags status = {{false, false}}; return true; }
    case 13: { FighterArticleFlags status = {{false, false}}; return true; }
    case 14: { FighterArticleFlags status = {{false, false}}; return true; }
    case 15: { FighterArticleFlags status = {{false, false}}; return true; }
    case 16: { FighterArticleFlags status = {{false, false}}; return true; }
    default: return false;
    }
}
