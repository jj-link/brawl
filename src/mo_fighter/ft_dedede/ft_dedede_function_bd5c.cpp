// The original article dispatch table has four-byte alignment.
#pragma section data_type ".data$dededeBD5C" ".bss"

#include <so/article/so_article.h>

extern "C" {
extern const char lbl_117_data_8200[], lbl_117_data_8094[], lbl_117_data_7F20[];
extern const char lbl_117_data_7DAC[], lbl_117_data_3254[], lbl_117_data_3A3C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
bool fn_117_92BC(void*, soModuleAccesser*);
}

namespace {
struct DededeArticleStatus {
    bool flags[2];
};
}

extern "C" bool fn_117_BD5C(void*, soModuleAccesser* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: {
        DededeArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_117_data_8200, lbl_117_data_3A3C, 1);
        return true;
    }
    case 1: {
        DededeArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_117_data_8094, lbl_117_data_3A3C, 1);
        return false;
    }
    case 2: {
        DededeArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_117_data_7F20, lbl_117_data_3A3C, 1);
        return true;
    }
    case 3: {
        DededeArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_117_data_7DAC, lbl_117_data_3A3C, 1);
        return true;
    }
    case 4: {
        DededeArticleStatus status = {{false, false}};
        return fn_117_92BC(__dynamic_cast(article, 0, lbl_117_data_3254, lbl_117_data_3A3C, 1), accesser);
    }
    case 5: { DededeArticleStatus status = {{false, false}}; return true; }
    case 6: { DededeArticleStatus status = {{false, false}}; return true; }
    case 7: { DededeArticleStatus status = {{false, false}}; return true; }
    case 8: { DededeArticleStatus status = {{false, false}}; return true; }
    case 9: { DededeArticleStatus status = {{false, false}}; return true; }
    case 10: { DededeArticleStatus status = {{false, false}}; return true; }
    case 11: { DededeArticleStatus status = {{false, false}}; return true; }
    case 12: { DededeArticleStatus status = {{false, false}}; return true; }
    case 13: { DededeArticleStatus status = {{false, false}}; return true; }
    case 14: { DededeArticleStatus status = {{false, false}}; return true; }
    case 15: { DededeArticleStatus status = {{false, false}}; return true; }
    case 16: { DededeArticleStatus status = {{false, false}}; return true; }
    default: return false;
    }
}
