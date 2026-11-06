#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
void* fn_114_BE0C();
bool fn_27_3614A4(void*, Weapon*, soModuleAccesser*);
unsigned int fn_114_BE7C(Weapon*, soModuleAccesser*);
bool fn_114_C05C(Weapon*, soModuleAccesser*);
bool fn_114_C158(Weapon*, soModuleAccesser*);
bool fn_114_C4EC(Weapon*, soModuleAccesser*);
}
namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct ArticleActivation {
    unsigned int operator()(Weapon*, soModuleAccesser*) const { return 0; }
};
template <> struct ArticleActivation<0> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_27_3614A4(fn_114_BE0C(), owner, accesser);
    }
};
template <> struct ArticleActivation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_114_BE7C(owner, accesser);
    }
};
template <> struct ArticleActivation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_114_C05C(owner, accesser);
    }
};
template <> struct ArticleActivation<3> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_114_C158(owner, accesser);
    }
};
template <> struct ArticleActivation<4> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_114_C4EC(owner, accesser);
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
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3e78c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3e704);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<1> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3c378)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3c2f0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x39f6c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x39ee4);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<2> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2c14c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2c0c4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1e338)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1e2b0);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<3> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1c718)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1c690);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1ab04)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1aa7c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x18ef0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18e68);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x172dc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x17254);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x156c8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x15640);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13ab4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x13a2c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x11ea0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x11e18);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1028c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x10204);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xe678)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xe5f0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xca64)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xc9dc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xae50)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xadc8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x923c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x91b4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7628)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x75a0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5a14)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x598c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3e00)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3d78);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x21ec)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2164);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<4> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const ArticleActivation<Kind>& activation,
                                  const ArticleDeactivation& deactivation) {
    ArticleStatus status;
    if (Kind >= 5) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
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
extern "C" soArticle& fn_114_D2E8(char* pool, unsigned kind, soModuleAccesser* accesser) {
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
