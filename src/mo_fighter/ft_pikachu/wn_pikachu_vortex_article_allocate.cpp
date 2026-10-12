// The original allocator owns a four-byte-aligned 17-entry switch table.
#pragma section data_type ".data$pikachu185A8" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_98_17B44(Weapon*, soModuleAccesser*);
}

namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct ArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_98_17B44(owner, accesser);
    }
};
struct ArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class ArticleSelector {
public:
    soArticle* article;
    ArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct ArticleSearch {
    bool operator()(ArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct ArticlePool {
    static inline Weapon* find(char*, ArticleSelector&, ArticleSearch) { return 0; }
};
template <> struct ArticlePool<0> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x6538)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x64b0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x43b4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x432c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2230)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x21a8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xac)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x24);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const ArticleActivation<Kind>& activation,
                                  const ArticleDeactivation& deactivation) {
    ArticleStatus status;
    if (Kind >= 1) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    ArticleSelector selector;
    Weapon* owner = ArticlePool<Kind>::find(pool, selector, ArticleSearch());
    if (!owner) {
        owner = static_cast<Weapon*>(selector.article);
        if (!owner) {
            selector.release(-1);
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    if (activation(owner, accesser) == true) {
        selector.release(-1);
        return static_cast<soArticle&>(*owner);
    }
    selector.release(-1);
    return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}

extern "C" soArticle& fn_98_185A8(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, ArticleActivation<0>(), ArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, ArticleActivation<1>(), ArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, ArticleActivation<2>(), ArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, ArticleActivation<3>(), ArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, ArticleActivation<4>(), ArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, ArticleActivation<5>(), ArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, ArticleActivation<6>(), ArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, ArticleActivation<7>(), ArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, ArticleActivation<8>(), ArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, ArticleActivation<9>(), ArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, ArticleActivation<10>(), ArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, ArticleActivation<11>(), ArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, ArticleActivation<12>(), ArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, ArticleActivation<13>(), ArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, ArticleActivation<14>(), ArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, ArticleActivation<15>(), ArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, ArticleActivation<16>(), ArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
