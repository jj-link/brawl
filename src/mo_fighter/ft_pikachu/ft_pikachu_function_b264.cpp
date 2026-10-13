#pragma section data_type ".data$pikachuB264" ".bss"

#include <so/article/so_article.h>

extern "C" {
extern const char lbl_98_data_6ED0[], lbl_98_data_6D5C[];
extern const char lbl_98_data_6BF0[], lbl_98_data_7048[], lbl_98_data_2844[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
// Each article pool starts with the same two bookkeeping flags.
struct ArticlePoolStatus {
    bool flags[2];
    ArticlePoolStatus() { flags[0] = false; flags[1] = false; }
};

template <unsigned Kind>
inline bool acceptsArticle(soArticle* article) {
    ArticlePoolStatus status;
    switch (Kind) {
    case 0: __dynamic_cast(article, 0, lbl_98_data_6ED0, lbl_98_data_2844, 1); break;
    case 1: __dynamic_cast(article, 0, lbl_98_data_6D5C, lbl_98_data_2844, 1); break;
    case 2: __dynamic_cast(article, 0, lbl_98_data_6BF0, lbl_98_data_2844, 1); break;
    case 3: __dynamic_cast(article, 0, lbl_98_data_7048, lbl_98_data_2844, 1); break;
    }
    return true;
}
}

// Dispatch by article kind; empty pools also accept the request.
extern "C" bool fn_98_B264(void*, void*, soArticle* article) {
    switch (static_cast<unsigned>(article->getArticleId())) {
    case 0: return acceptsArticle<0>(article);
    case 1: return acceptsArticle<1>(article);
    case 2: return acceptsArticle<2>(article);
    case 3: return acceptsArticle<3>(article);
    case 4: return acceptsArticle<4>(article);
    case 5: return acceptsArticle<5>(article);
    case 6: return acceptsArticle<6>(article);
    case 7: return acceptsArticle<7>(article);
    case 8: return acceptsArticle<8>(article);
    case 9: return acceptsArticle<9>(article);
    case 10: return acceptsArticle<10>(article);
    case 11: return acceptsArticle<11>(article);
    case 12: return acceptsArticle<12>(article);
    case 13: return acceptsArticle<13>(article);
    case 14: return acceptsArticle<14>(article);
    case 15: return acceptsArticle<15>(article);
    case 16: return acceptsArticle<16>(article);
    default: return false;
    }
}
