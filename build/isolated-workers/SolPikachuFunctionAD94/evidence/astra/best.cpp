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

#pragma always_inline on
#pragma inline_depth(8)
namespace {
struct PikachuArticleStatus {
    bool flags[2];
    inline PikachuArticleStatus();
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
inline PikachuArticleStatus::PikachuArticleStatus() {
    flags[0] = false;
    flags[1] = false;
}
template <unsigned Kind>
inline void visitArticles(char* pool, PikachuArticleCounter& counter) {
    for (int index = 0; index < PikachuArticlePool<Kind>::size(); ++index)
        counter(&static_cast<soArticle&>(*PikachuArticlePool<Kind>::at(pool, index)));
}
template <unsigned Kind>
inline unsigned countArticles(char* pool, const PikachuArticleStatus&) {
    if (Kind >= 4) return 0;
    PikachuArticleCounter counter(fn_98_B61C);
    visitArticles<Kind>(pool, counter);
    return counter.matches;
}
} // namespace

// Count active articles in the selected fixed-capacity weapon pool.
extern "C" unsigned fn_98_AD94(char* pool, soModuleAccesser*, unsigned kind) {
    switch (kind) {
    case 0: return countArticles<0>(pool, PikachuArticleStatus());
    case 1: return countArticles<1>(pool, PikachuArticleStatus());
    case 2: return countArticles<2>(pool, PikachuArticleStatus());
    case 3: return countArticles<3>(pool, PikachuArticleStatus());
    case 4: return countArticles<4>(pool, PikachuArticleStatus());
    case 5: return countArticles<5>(pool, PikachuArticleStatus());
    case 6: return countArticles<6>(pool, PikachuArticleStatus());
    case 7: return countArticles<7>(pool, PikachuArticleStatus());
    case 8: return countArticles<8>(pool, PikachuArticleStatus());
    case 9: return countArticles<9>(pool, PikachuArticleStatus());
    case 10: return countArticles<10>(pool, PikachuArticleStatus());
    case 11: return countArticles<11>(pool, PikachuArticleStatus());
    case 12: return countArticles<12>(pool, PikachuArticleStatus());
    case 13: return countArticles<13>(pool, PikachuArticleStatus());
    case 14: return countArticles<14>(pool, PikachuArticleStatus());
    case 15: return countArticles<15>(pool, PikachuArticleStatus());
    case 16: return countArticles<16>(pool, PikachuArticleStatus());
    default: return 0;
    }
}

