#include <wn/weapon.h>
#pragma force_active on

extern "C" Weapon* fn_121_18624(char*, int);

namespace {
struct ArticleSearchStatus {
    bool first;
    bool second;
    bool operator()(soArticle& article) const { return article.isActiveArticle(); }
};
inline bool allArticlesActive(char* pool, const ArticleSearchStatus& status) {
    for (int i = 0; i < 1; ++i) {
        if (!status(*fn_121_18624(pool + 0xc, i))) return false;
    }
    return true;
}
template <unsigned Kind> inline bool articleAvailable(char* pool, const ArticleSearchStatus& status) {
    if (Kind != 0) return false;
    return !allArticlesActive(pool, status);
}
}

extern "C" bool fn_121_17DF0(char* pool, void*, unsigned kind) {
    switch (kind) {
    case 0: { ArticleSearchStatus status = { false, false }; return articleAvailable<0>(pool, status); }
    case 1: { ArticleSearchStatus status = { false, false }; return articleAvailable<1>(pool, status); }
    case 2: { ArticleSearchStatus status = { false, false }; return articleAvailable<2>(pool, status); }
    case 3: { ArticleSearchStatus status = { false, false }; return articleAvailable<3>(pool, status); }
    case 4: { ArticleSearchStatus status = { false, false }; return articleAvailable<4>(pool, status); }
    case 5: { ArticleSearchStatus status = { false, false }; return articleAvailable<5>(pool, status); }
    case 6: { ArticleSearchStatus status = { false, false }; return articleAvailable<6>(pool, status); }
    case 7: { ArticleSearchStatus status = { false, false }; return articleAvailable<7>(pool, status); }
    case 8: { ArticleSearchStatus status = { false, false }; return articleAvailable<8>(pool, status); }
    case 9: { ArticleSearchStatus status = { false, false }; return articleAvailable<9>(pool, status); }
    case 10: { ArticleSearchStatus status = { false, false }; return articleAvailable<10>(pool, status); }
    case 11: { ArticleSearchStatus status = { false, false }; return articleAvailable<11>(pool, status); }
    case 12: { ArticleSearchStatus status = { false, false }; return articleAvailable<12>(pool, status); }
    case 13: { ArticleSearchStatus status = { false, false }; return articleAvailable<13>(pool, status); }
    case 14: { ArticleSearchStatus status = { false, false }; return articleAvailable<14>(pool, status); }
    case 15: { ArticleSearchStatus status = { false, false }; return articleAvailable<15>(pool, status); }
    case 16: { ArticleSearchStatus status = { false, false }; return articleAvailable<16>(pool, status); }
    default: return false;
    }
}
