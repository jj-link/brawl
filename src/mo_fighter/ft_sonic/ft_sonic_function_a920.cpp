#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_123_95DC(Weapon*, soModuleAccesser*);
bool fn_123_9724(Weapon*, soModuleAccesser*);
}

namespace {
struct SonicArticleStatus {
    bool flags[2];
    SonicArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct SonicArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        if (Kind == 0) return fn_123_95DC(owner, accesser);
        return fn_123_9724(owner, accesser);
    }
};
struct SonicArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class SonicArticleSelector {
public:
    soArticle* article;
    SonicArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct SonicArticleSearch {
    bool operator()(SonicArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct SonicArticlePool {
    static inline Weapon* find(char*, SonicArticleSelector&, SonicArticleSearch) { return 0; }
};
template <> struct SonicArticlePool<0> {
    static inline Weapon* find(char* pool, SonicArticleSelector& selector, SonicArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x2ddc)) == true ? reinterpret_cast<Weapon*>(pool + 0x2d54) : 0;
        return owner;
    }
};
template <> struct SonicArticlePool<1> {
    static inline Weapon* find(char* pool, SonicArticleSelector& selector, SonicArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true ? reinterpret_cast<Weapon*>(pool + 0x18) : 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const SonicArticleActivation<Kind>& activation,
                                  const SonicArticleDeactivation& deactivation) {
    SonicArticleStatus status;
    if (Kind >= 2) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    SonicArticleSelector selector;
    Weapon* owner = SonicArticlePool<Kind>::find(pool, selector, SonicArticleSearch());
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

extern "C" soArticle& fn_123_A920(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, SonicArticleActivation<0>(), SonicArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, SonicArticleActivation<1>(), SonicArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, SonicArticleActivation<2>(), SonicArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, SonicArticleActivation<3>(), SonicArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, SonicArticleActivation<4>(), SonicArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, SonicArticleActivation<5>(), SonicArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, SonicArticleActivation<6>(), SonicArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, SonicArticleActivation<7>(), SonicArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, SonicArticleActivation<8>(), SonicArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, SonicArticleActivation<9>(), SonicArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, SonicArticleActivation<10>(), SonicArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, SonicArticleActivation<11>(), SonicArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, SonicArticleActivation<12>(), SonicArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, SonicArticleActivation<13>(), SonicArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, SonicArticleActivation<14>(), SonicArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, SonicArticleActivation<15>(), SonicArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, SonicArticleActivation<16>(), SonicArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}