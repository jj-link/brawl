#pragma section data_type ".data$pikachuAD94" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
unsigned fn_98_B61C(soArticle*);
Weapon* fn_98_B6A8(void*, int);
Weapon* fn_98_B67C(void*, int);
Weapon* fn_98_B664(void*, int);
Weapon* fn_98_B62C(void*, int);
}

namespace {
struct PikachuArticleStatus {
    bool flags[2];
    PikachuArticleStatus() { flags[0] = false; flags[1] = false; }
};
struct PikachuArticleCounter {
    unsigned (*predicate)(soArticle*);
    unsigned matches, other;
    PikachuArticleCounter(unsigned (*test)(soArticle*))
        : predicate(test), matches(0), other(0) {}
    inline void operator()(soArticle* article) {
        if (predicate(article) == 1) ++matches;
        else ++other;
    }
};
template <unsigned Kind> struct PikachuArticlePool {
    static inline int size() { return 0; }
    static inline Weapon* at(char*, int) { return 0; }
};
template <> struct PikachuArticlePool<0> {
    static inline int size() { return 3; }
    static inline Weapon* at(char* pool, int index) { return fn_98_B6A8(pool + 0x1cb54, index); }
};
template <> struct PikachuArticlePool<1> {
    static inline int size() { return 2; }
    static inline Weapon* at(char* pool, int index) { return fn_98_B67C(pool + 0x7f48, index); }
};
template <> struct PikachuArticlePool<2> {
    static inline int size() { return 1; }
    static inline Weapon* at(char* pool, int index) { return fn_98_B664(pool + 0x5f74, index); }
};
template <> struct PikachuArticlePool<3> {
    static inline int size() { return 3; }
    static inline Weapon* at(char* pool, int index) { return fn_98_B62C(pool + 0xc, index); }
};
template <unsigned Kind>
inline unsigned countArticles(char* pool) {
    PikachuArticleStatus status;
    if (Kind >= 4) return 0;
    PikachuArticleCounter counter(fn_98_B61C);
    for (int index = 0; index < PikachuArticlePool<Kind>::size(); ++index)
        counter(&static_cast<soArticle&>(*PikachuArticlePool<Kind>::at(pool, index)));
    return counter.matches;
}
}

// Count active articles in the selected fixed-capacity weapon pool.
extern "C" unsigned fn_98_AD94(char* pool, soModuleAccesser*, unsigned kind) {
    switch (kind) {
    case 0: return countArticles<0>(pool);
    case 1: return countArticles<1>(pool);
    case 2: return countArticles<2>(pool);
    case 3: return countArticles<3>(pool);
    case 4: return countArticles<4>(pool);
    case 5: return countArticles<5>(pool);
    case 6: return countArticles<6>(pool);
    case 7: return countArticles<7>(pool);
    case 8: return countArticles<8>(pool);
    case 9: return countArticles<9>(pool);
    case 10: return countArticles<10>(pool);
    case 11: return countArticles<11>(pool);
    case 12: return countArticles<12>(pool);
    case 13: return countArticles<13>(pool);
    case 14: return countArticles<14>(pool);
    case 15: return countArticles<15>(pool);
    case 16: return countArticles<16>(pool);
    default: return 0;
    }
}
