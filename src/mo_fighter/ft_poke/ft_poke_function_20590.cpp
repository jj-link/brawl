#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_116_1FE44(Weapon*, void*);
unsigned int fn_116_200AC(Weapon*, void*);
unsigned int fn_116_20134(Weapon*, void*);
}

namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct ArticleActivation {
    unsigned int operator()(Weapon* owner, void* input) const {
        if (Kind == 0) return fn_116_1FE44(owner, input);
        if (Kind == 1) return fn_116_200AC(owner, input);
        return fn_116_20134(owner, input);
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
    static inline Weapon* find(char* self, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x7B44)) == true) owner = reinterpret_cast<Weapon*>(self + 0x7ABC);
        else if (search(selector, reinterpret_cast<soArticle*>(self + 0x6440)) == true) owner = reinterpret_cast<Weapon*>(self + 0x63B8);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<1> {
    static inline Weapon* find(char* self, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x4D88)) == true) owner = reinterpret_cast<Weapon*>(self + 0x4D00);
        else if (search(selector, reinterpret_cast<soArticle*>(self + 0x36DC)) == true) owner = reinterpret_cast<Weapon*>(self + 0x3654);
        else if (search(selector, reinterpret_cast<soArticle*>(self + 0x2030)) == true) owner = reinterpret_cast<Weapon*>(self + 0x1FA8);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<2> {
    static inline Weapon* find(char* self, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(self + 0xA0)) == true ? reinterpret_cast<Weapon*>(self + 0x18) : 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle* allocateArticle(char* self, void* input,
                                  const ArticleActivation<Kind>& activation,
                                  const ArticleDeactivation& deactivation) {
    ArticleStatus status;
    if (Kind >= 3) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    ArticleSelector selector;
    Weapon* owner = ArticlePool<Kind>::find(self, selector, ArticleSearch());
    if (!owner) {
        owner = reinterpret_cast<Weapon*>(selector.article);
        if (owner) {
            owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
        }
        if (!owner) {
            selector.release(-1);
            return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    if (activation(owner, input) == 1) {
        selector.release(-1);
        return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
    }
    selector.release(-1);
    return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}

extern "C" soArticle* fn_116_20590(char* self, unsigned kind, void* input) {
    switch (kind) {
    case 0: return allocateArticle<0>(self, input, ArticleActivation<0>(), ArticleDeactivation());
    case 1: return allocateArticle<1>(self, input, ArticleActivation<1>(), ArticleDeactivation());
    case 2: return allocateArticle<2>(self, input, ArticleActivation<2>(), ArticleDeactivation());
    case 3: return allocateArticle<3>(self, input, ArticleActivation<3>(), ArticleDeactivation());
    case 4: return allocateArticle<4>(self, input, ArticleActivation<4>(), ArticleDeactivation());
    case 5: return allocateArticle<5>(self, input, ArticleActivation<5>(), ArticleDeactivation());
    case 6: return allocateArticle<6>(self, input, ArticleActivation<6>(), ArticleDeactivation());
    case 7: return allocateArticle<7>(self, input, ArticleActivation<7>(), ArticleDeactivation());
    case 8: return allocateArticle<8>(self, input, ArticleActivation<8>(), ArticleDeactivation());
    case 9: return allocateArticle<9>(self, input, ArticleActivation<9>(), ArticleDeactivation());
    case 10: return allocateArticle<10>(self, input, ArticleActivation<10>(), ArticleDeactivation());
    case 11: return allocateArticle<11>(self, input, ArticleActivation<11>(), ArticleDeactivation());
    case 12: return allocateArticle<12>(self, input, ArticleActivation<12>(), ArticleDeactivation());
    case 13: return allocateArticle<13>(self, input, ArticleActivation<13>(), ArticleDeactivation());
    case 14: return allocateArticle<14>(self, input, ArticleActivation<14>(), ArticleDeactivation());
    case 15: return allocateArticle<15>(self, input, ArticleActivation<15>(), ArticleDeactivation());
    case 16: return allocateArticle<16>(self, input, ArticleActivation<16>(), ArticleDeactivation());
    default: return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
