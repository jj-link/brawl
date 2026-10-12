// Preserve the original REL's four-byte-aligned dispatch table.
#pragma section data_type ".data$dededeB4F8" ".bss"

#include <wn/weapon.h>

extern "C" {
Weapon& fn_117_C380(void*, int);
Weapon& fn_117_C368(void*, int);
Weapon& fn_117_C350(void*, int);
Weapon& fn_117_C308(void*, int);
Weapon& fn_117_C194(void*, int);
}

namespace {
struct DededeArticleSearchStatus {
    bool first;
    bool second;
    bool operator()(soArticle& article) const { return article.isActiveArticle(); }
};
template <unsigned Kind> struct DededeArticlePool {
    static int count() { return 0; }
    static Weapon& get(char*, int);
};
template <> struct DededeArticlePool<0> {
    static int count() { return 2; }
    static Weapon& get(char* pool, int i) { return fn_117_C380(pool + 0x3b000, i); }
};
template <> struct DededeArticlePool<1> {
    static int count() { return 1; }
    static Weapon& get(char* pool, int i) { return fn_117_C368(pool + 0x392b0, i); }
};
template <> struct DededeArticlePool<2> {
    static int count() { return 1; }
    static Weapon& get(char* pool, int i) { return fn_117_C350(pool + 0x372ec, i); }
};
template <> struct DededeArticlePool<3> {
    static int count() { return 4; }
    static Weapon& get(char* pool, int i) { return fn_117_C308(pool + 0x2f3e8, i); }
};
template <> struct DededeArticlePool<4> {
    static int count() { return 19; }
    static Weapon& get(char* pool, int i) { return fn_117_C194(pool + 0xc, i); }
};
template <unsigned Kind> inline bool allArticlesActive(char* pool, const DededeArticleSearchStatus& status) {
    for (int i = 0; i < DededeArticlePool<Kind>::count(); ++i) {
        soArticle& article = DededeArticlePool<Kind>::get(pool, i);
        if (!status(article)) return false;
    }
    return true;
}
template <unsigned Kind> inline bool articleAvailable(char* pool, const DededeArticleSearchStatus& status) {
    if (Kind >= 5) return false;
    return !allArticlesActive<Kind>(pool, status);
}
}

extern "C" bool fn_117_B4F8(char* pool, void*, unsigned kind) {
    switch (kind) {
    case 0: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<0>(pool, status); }
    case 1: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<1>(pool, status); }
    case 2: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<2>(pool, status); }
    case 3: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<3>(pool, status); }
    case 4: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<4>(pool, status); }
    case 5: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<5>(pool, status); }
    case 6: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<6>(pool, status); }
    case 7: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<7>(pool, status); }
    case 8: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<8>(pool, status); }
    case 9: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<9>(pool, status); }
    case 10: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<10>(pool, status); }
    case 11: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<11>(pool, status); }
    case 12: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<12>(pool, status); }
    case 13: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<13>(pool, status); }
    case 14: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<14>(pool, status); }
    case 15: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<15>(pool, status); }
    case 16: { DededeArticleSearchStatus status = { false, false }; return articleAvailable<16>(pool, status); }
    default: return false;
    }
}
