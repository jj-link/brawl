#pragma force_active on
#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
int fn_41_AE14(void*, soModuleAccesser*);
}
namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
};
struct ArticleActivation {
    void operator()(char* owner, soModuleAccesser* accesser) const { fn_41_AE14(owner, accesser); }
};
struct ArticleDeactivation {
    void operator()(char* owner) const { reinterpret_cast<Weapon*>(owner + 0xc)->deactivateArticle(); }
};
class ArticleSelector {
public:
    soArticle* article;
    ArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct ArticleSearch {
    bool operator()(ArticleSelector& selector, soArticle* candidate) const { return selector.select(candidate); }
};
template <unsigned Kind> struct ArticlePool {
    static inline char* find(char*, ArticleSelector&, ArticleSearch) { return 0; }
};
template <> struct ArticlePool<0> {
    static inline char* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        char* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2428)) == true) owner = pool + 0x2394;
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xb0)) == true) owner = pool + 0x1c;
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const ArticleActivation& activation,
                                  const ArticleDeactivation& deactivation) {
    ArticleStatus status;
    if (Kind >= 1) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    ArticleSelector selector;
    char* owner = ArticlePool<Kind>::find(pool, selector, ArticleSearch());
    if (!owner) {
        owner = reinterpret_cast<char*>(selector.article);
        if (owner) owner -= 0x94;
        if (!owner) {
            selector.release(-1);
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    activation(owner, accesser);
    selector.release(-1);
    return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}
extern "C" soArticle& fn_41_3E890(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, ArticleActivation(), ArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
