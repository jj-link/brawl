#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" unsigned fn_98_B61C(soArticle*);
extern "C" Weapon* fn_98_19088(char*, int);

struct ArticleStatus {
    bool first;
    bool second;
};
struct ArticleCounter {
    unsigned (*predicate)(soArticle*);
    unsigned matches;
    unsigned other;
    explicit ArticleCounter(unsigned (*test)(soArticle*)) : predicate(test), matches(0), other(0) {}
    inline void operator()(soArticle* article) {
        if (predicate(article) == 1) {
            ++matches;
            return;
        }
        ++other;
    }
};
static inline ArticleCounter countArticles(char* pool, unsigned (*test)(soArticle*)) {
    ArticleCounter counter(test);
    for (int i = 0; i < 4; ++i) {
        counter(&static_cast<soArticle&>(*fn_98_19088(pool + 0xc, i)));
    }
    return counter;
}

extern "C" unsigned fn_98_18A98(char* pool, soModuleAccesser*, unsigned kind) {
    switch (kind) {
    case 0: {
        ArticleStatus status = { false, false };
        return countArticles(pool, fn_98_B61C).matches;
    }
    case 1: { ArticleStatus status = { false, false }; return 0; }
    case 2: { ArticleStatus status = { false, false }; return 0; }
    case 3: { ArticleStatus status = { false, false }; return 0; }
    case 4: { ArticleStatus status = { false, false }; return 0; }
    case 5: { ArticleStatus status = { false, false }; return 0; }
    case 6: { ArticleStatus status = { false, false }; return 0; }
    case 7: { ArticleStatus status = { false, false }; return 0; }
    case 8: { ArticleStatus status = { false, false }; return 0; }
    case 9: { ArticleStatus status = { false, false }; return 0; }
    case 10: { ArticleStatus status = { false, false }; return 0; }
    case 11: { ArticleStatus status = { false, false }; return 0; }
    case 12: { ArticleStatus status = { false, false }; return 0; }
    case 13: { ArticleStatus status = { false, false }; return 0; }
    case 14: { ArticleStatus status = { false, false }; return 0; }
    case 15: { ArticleStatus status = { false, false }; return 0; }
    case 16: { ArticleStatus status = { false, false }; return 0; }
    default: return 0;
    }
}
