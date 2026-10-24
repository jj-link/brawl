#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_94_data_965C[];
extern const char lbl_94_data_94F4[];
extern const char lbl_94_data_937C[];
extern const char lbl_94_data_90A0[];
extern const char lbl_94_data_8F38[];
extern const char lbl_94_data_8DD0[];
extern const char lbl_94_data_920C[];
extern const char lbl_94_data_8C6C[];
extern const char lbl_94_data_4904[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
bool fn_94_95CC(void*, soModuleAccesser*);
bool fn_94_978C(void*, soModuleAccesser*);
bool fn_94_98D0(void*, soModuleAccesser*);
bool fn_94_9B48(void*, soModuleAccesser*);
bool fn_94_9CB0(void*, soModuleAccesser*);
bool fn_94_9A0C(void*, soModuleAccesser*);
}

namespace {
template <unsigned Kind>
inline bool handle(soModuleAccesser* accesser, soArticle* article) {
    bool flags[2] = { false, false };
    if (Kind == 0) return fn_94_95CC(__dynamic_cast(article, 0, lbl_94_data_965C, lbl_94_data_4904, 1), accesser);
    if (Kind == 1) return fn_94_978C(__dynamic_cast(article, 0, lbl_94_data_94F4, lbl_94_data_4904, 1), accesser);
    if (Kind == 2) return fn_94_98D0(__dynamic_cast(article, 0, lbl_94_data_937C, lbl_94_data_4904, 1), accesser);
    if (Kind == 3) return fn_94_9B48(__dynamic_cast(article, 0, lbl_94_data_90A0, lbl_94_data_4904, 1), accesser);
    if (Kind == 4) return fn_94_9CB0(__dynamic_cast(article, 0, lbl_94_data_8F38, lbl_94_data_4904, 1), accesser);
    if (Kind == 5) { __dynamic_cast(article, 0, lbl_94_data_8DD0, lbl_94_data_4904, 1); return true; }
    if (Kind == 6) return fn_94_9A0C(__dynamic_cast(article, 0, lbl_94_data_920C, lbl_94_data_4904, 1), accesser);
    if (Kind == 7) { __dynamic_cast(article, 0, lbl_94_data_8C6C, lbl_94_data_4904, 1); return true; }
    return true;
}
}

extern "C" bool fn_94_C824(void*, soModuleAccesser* accesser, soArticle* article)
{
    switch (article->getArticleId()) {
    case 0: return handle<0>(accesser, article);
    case 1: return handle<1>(accesser, article);
    case 2: return handle<2>(accesser, article);
    case 3: return handle<3>(accesser, article);
    case 4: return handle<4>(accesser, article);
    case 5: return handle<5>(accesser, article);
    case 6: return handle<6>(accesser, article);
    case 7: return handle<7>(accesser, article);
    case 8: return handle<8>(accesser, article);
    case 9: return handle<9>(accesser, article);
    case 10: return handle<10>(accesser, article);
    case 11: return handle<11>(accesser, article);
    case 12: return handle<12>(accesser, article);
    case 13: return handle<13>(accesser, article);
    case 14: return handle<14>(accesser, article);
    case 15: return handle<15>(accesser, article);
    case 16: return handle<16>(accesser, article);
    default: return false;
    }
}
