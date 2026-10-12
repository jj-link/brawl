#pragma section data_type ".data$pikachu18E2C" ".bss"

#include <so/article/so_article.h>

extern "C" {
extern const char lbl_98_data_7F08[], lbl_98_data_2844[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
// The article-pool acceptance policy retains its two bookkeeping flags.
struct ArticlePoolStatus {
    bool flags[2];
};

template <unsigned Kind>
inline int acceptsArticle(const ArticlePoolStatus&, soArticle* article) {
    if (Kind == 0) {
        __dynamic_cast(article, 0, lbl_98_data_7F08, lbl_98_data_2844, 1);
    }
    return 1;
}
}

// Only the article argument is used; preserve the owner's event-dispatch ABI.
extern "C" int fn_98_18E2C(void*, const void*, void* payload) {
    soArticle* article = static_cast<soArticle*>(payload);
    switch (static_cast<unsigned>(article->getArticleId())) {
    case 0: { ArticlePoolStatus status = { false, false }; return acceptsArticle<0>(status, article); }
    case 1: { ArticlePoolStatus status = { false, false }; return acceptsArticle<1>(status, article); }
    case 2: { ArticlePoolStatus status = { false, false }; return acceptsArticle<2>(status, article); }
    case 3: { ArticlePoolStatus status = { false, false }; return acceptsArticle<3>(status, article); }
    case 4: { ArticlePoolStatus status = { false, false }; return acceptsArticle<4>(status, article); }
    case 5: { ArticlePoolStatus status = { false, false }; return acceptsArticle<5>(status, article); }
    case 6: { ArticlePoolStatus status = { false, false }; return acceptsArticle<6>(status, article); }
    case 7: { ArticlePoolStatus status = { false, false }; return acceptsArticle<7>(status, article); }
    case 8: { ArticlePoolStatus status = { false, false }; return acceptsArticle<8>(status, article); }
    case 9: { ArticlePoolStatus status = { false, false }; return acceptsArticle<9>(status, article); }
    case 10: { ArticlePoolStatus status = { false, false }; return acceptsArticle<10>(status, article); }
    case 11: { ArticlePoolStatus status = { false, false }; return acceptsArticle<11>(status, article); }
    case 12: { ArticlePoolStatus status = { false, false }; return acceptsArticle<12>(status, article); }
    case 13: { ArticlePoolStatus status = { false, false }; return acceptsArticle<13>(status, article); }
    case 14: { ArticlePoolStatus status = { false, false }; return acceptsArticle<14>(status, article); }
    case 15: { ArticlePoolStatus status = { false, false }; return acceptsArticle<15>(status, article); }
    case 16: { ArticlePoolStatus status = { false, false }; return acceptsArticle<16>(status, article); }
    default: return 0;
    }
}
