#pragma section data_type ".data$luigi9330" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>

extern "C" {
Weapon* fn_99_9CCC(void*, int);
Weapon* fn_99_9CB4(void*, int);
}

namespace {
template <unsigned Kind> struct ArticleActive {
    bool operator()(soArticle& article) const { return article.isActiveArticle(); }
};
template <unsigned Kind> struct ArticleAvailable {
    bool operator()(soArticle& article) const { return !ArticleActive<Kind>()(article); }
};
template <unsigned Kind> struct ArticlePool {
    static inline bool allActive(char*, const ArticleActive<Kind>&) { return true; }
};
template <> struct ArticlePool<0> {
    static inline bool allActive(char* pool, const ArticleActive<0>& active) {
        for (int i = 0; i < 2; ++i) {
            if (!active(*fn_99_9CCC(pool + 0x20a8, i))) return false;
        }
        return true;
    }
};
template <> struct ArticlePool<1> {
    static inline bool allActive(char* pool, const ArticleActive<1>& active) {
        for (int i = 0; i < 1; ++i) {
            if (!active(*fn_99_9CB4(pool + 0xc, i))) return false;
        }
        return true;
    }
};
template <unsigned Kind>
inline bool available(char* pool, const ArticleActive<Kind>& active,
                      const ArticleAvailable<Kind>&) {
    return !ArticlePool<Kind>::allActive(pool, active);
}
}

extern "C" bool fn_99_9330(char* pool, unsigned unused, unsigned kind) {
    switch (kind) {
    case 0: return available<0>(pool, ArticleActive<0>(), ArticleAvailable<0>());
    case 1: return available<1>(pool, ArticleActive<1>(), ArticleAvailable<1>());
    case 2: return available<2>(pool, ArticleActive<2>(), ArticleAvailable<2>());
    case 3: return available<3>(pool, ArticleActive<3>(), ArticleAvailable<3>());
    case 4: return available<4>(pool, ArticleActive<4>(), ArticleAvailable<4>());
    case 5: return available<5>(pool, ArticleActive<5>(), ArticleAvailable<5>());
    case 6: return available<6>(pool, ArticleActive<6>(), ArticleAvailable<6>());
    case 7: return available<7>(pool, ArticleActive<7>(), ArticleAvailable<7>());
    case 8: return available<8>(pool, ArticleActive<8>(), ArticleAvailable<8>());
    case 9: return available<9>(pool, ArticleActive<9>(), ArticleAvailable<9>());
    case 10: return available<10>(pool, ArticleActive<10>(), ArticleAvailable<10>());
    case 11: return available<11>(pool, ArticleActive<11>(), ArticleAvailable<11>());
    case 12: return available<12>(pool, ArticleActive<12>(), ArticleAvailable<12>());
    case 13: return available<13>(pool, ArticleActive<13>(), ArticleAvailable<13>());
    case 14: return available<14>(pool, ArticleActive<14>(), ArticleAvailable<14>());
    case 15: return available<15>(pool, ArticleActive<15>(), ArticleAvailable<15>());
    case 16: return available<16>(pool, ArticleActive<16>(), ArticleAvailable<16>());
    default: return false;
    }
}
