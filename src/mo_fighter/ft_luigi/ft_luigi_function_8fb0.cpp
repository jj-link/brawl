// Preserve the article dispatch table's four-byte alignment in the REL.
#pragma section data_type ".data$luigi8fb0" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_99_8054(Weapon*, soModuleAccesser*);
bool fn_99_8110(Weapon*, soModuleAccesser*);
}

namespace {
template <unsigned Kind> struct LuigiArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        if (Kind == 0) return fn_99_8054(owner, accesser);
        return fn_99_8110(owner, accesser);
    }
};
struct LuigiArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class LuigiArticleSelector {
public:
    soArticle* article;
    LuigiArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct LuigiArticleSearch {
    bool operator()(LuigiArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct LuigiArticlePool {
    static inline Weapon* find(char*, LuigiArticleSelector&, LuigiArticleSearch) { return 0; }
};
template <> struct LuigiArticlePool<0> {
    static inline Weapon* find(char* pool, LuigiArticleSelector& selector, LuigiArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4088)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x4000);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2140)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x20b8);
        else owner = 0;
        return owner;
    }
};
template <> struct LuigiArticlePool<1> {
    static inline Weapon* find(char* pool, LuigiArticleSelector& selector, LuigiArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true ? reinterpret_cast<Weapon*>(pool + 0x18) : 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const LuigiArticleActivation<Kind>& activation,
                                  const LuigiArticleDeactivation& deactivation) {
    if (Kind >= 2) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    LuigiArticleSelector selector;
    Weapon* owner = LuigiArticlePool<Kind>::find(pool, selector, LuigiArticleSearch());
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

extern "C" soArticle& fn_99_8FB0(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, LuigiArticleActivation<0>(), LuigiArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, LuigiArticleActivation<1>(), LuigiArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, LuigiArticleActivation<2>(), LuigiArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, LuigiArticleActivation<3>(), LuigiArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, LuigiArticleActivation<4>(), LuigiArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, LuigiArticleActivation<5>(), LuigiArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, LuigiArticleActivation<6>(), LuigiArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, LuigiArticleActivation<7>(), LuigiArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, LuigiArticleActivation<8>(), LuigiArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, LuigiArticleActivation<9>(), LuigiArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, LuigiArticleActivation<10>(), LuigiArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, LuigiArticleActivation<11>(), LuigiArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, LuigiArticleActivation<12>(), LuigiArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, LuigiArticleActivation<13>(), LuigiArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, LuigiArticleActivation<14>(), LuigiArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, LuigiArticleActivation<15>(), LuigiArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, LuigiArticleActivation<16>(), LuigiArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
