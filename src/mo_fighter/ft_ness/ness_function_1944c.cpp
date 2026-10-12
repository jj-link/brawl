#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_101_19140(Weapon*, soModuleAccesser*);
}

namespace {
template <unsigned Kind> struct NessThunderArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_101_19140(owner, accesser);
    }
};
struct NessThunderArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class NessThunderArticleSelector {
public:
    soArticle* article;
    NessThunderArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct NessThunderArticleSearch {
    bool operator()(NessThunderArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
static inline Weapon* recoverArticleOwner(NessThunderArticleSelector& selector) {
    return static_cast<Weapon*>(selector.article);
}
static inline Weapon* findArticle(char* pool, NessThunderArticleSelector& selector,
                                  NessThunderArticleSearch search) {
    Weapon* owner;
    if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9e34)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x9dac);
    else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7eb4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7e2c);
    else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5f34)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x5eac);
    else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3fb4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3f2c);
    else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2034)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1fac);
    else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xb4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2c);
    else owner = 0;
    return owner;
}
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const NessThunderArticleActivation<Kind>& activation,
                                  const NessThunderArticleDeactivation& deactivation) {
    if (Kind >= 1) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    NessThunderArticleSelector selector;
    Weapon* owner = findArticle(pool, selector, NessThunderArticleSearch());
    if (!owner) {
        owner = recoverArticleOwner(selector);
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

extern "C" soArticle& fn_101_1944C(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, NessThunderArticleActivation<0>(), NessThunderArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, NessThunderArticleActivation<1>(), NessThunderArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, NessThunderArticleActivation<2>(), NessThunderArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, NessThunderArticleActivation<3>(), NessThunderArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, NessThunderArticleActivation<4>(), NessThunderArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, NessThunderArticleActivation<5>(), NessThunderArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, NessThunderArticleActivation<6>(), NessThunderArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, NessThunderArticleActivation<7>(), NessThunderArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, NessThunderArticleActivation<8>(), NessThunderArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, NessThunderArticleActivation<9>(), NessThunderArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, NessThunderArticleActivation<10>(), NessThunderArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, NessThunderArticleActivation<11>(), NessThunderArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, NessThunderArticleActivation<12>(), NessThunderArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, NessThunderArticleActivation<13>(), NessThunderArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, NessThunderArticleActivation<14>(), NessThunderArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, NessThunderArticleActivation<15>(), NessThunderArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, NessThunderArticleActivation<16>(), NessThunderArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
