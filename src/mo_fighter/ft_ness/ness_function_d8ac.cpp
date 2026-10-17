#include <wn/weapon.h>
#include <so/stageobject.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
void* fn_101_C374();
bool fn_27_329818(void*, StageObject*, void*);
int fn_101_C3E4(void*, soModuleAccesser*);
bool fn_101_C5C4(Weapon*, soModuleAccesser*);
bool fn_101_C6C0(StageObject*, void*);
bool fn_101_CA3C(StageObject*, void*);
bool fn_101_CB28(void*, soModuleAccesser*);
}

namespace {
// Stateless operations preserve each article kind's allocation policy.
template <unsigned Kind> struct NessArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        switch (Kind) {
        case 0: return fn_27_329818(fn_101_C374(), owner, accesser);
        case 1: return fn_101_C3E4(owner, accesser);
        case 2: return fn_101_C5C4(owner, accesser);
        case 3: return fn_101_C6C0(owner, accesser);
        case 4: return fn_101_CA3C(owner, accesser);
        case 5: return fn_101_CB28(owner, accesser);
        default: return false;
        }
    }
};
struct NessArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class NessArticleSelector {
public:
    soArticle* article;
    NessArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct NessArticleSearch {
    bool operator()(NessArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
static inline Weapon* recoverArticleOwner(NessArticleSelector& selector) {
    return static_cast<Weapon*>(selector.article);
}
template <unsigned Kind> struct NessArticlePool {
    static inline Weapon* find(char*, NessArticleSelector&, NessArticleSearch) { return 0; }
};
template <> struct NessArticlePool<0> {
    static inline Weapon* find(char* pool, NessArticleSelector& selector, NessArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x40984)) == true ? reinterpret_cast<Weapon*>(pool + 0x408fc) : 0;
        return owner;
    }
};
template <> struct NessArticlePool<1> {
    static inline Weapon* find(char* pool, NessArticleSelector& selector, NessArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3e570)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3e4e8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3c164)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3c0dc);
        else owner = 0;
        return owner;
    }
};
template <> struct NessArticlePool<2> {
    static inline Weapon* find(char* pool, NessArticleSelector& selector, NessArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2e344)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2e2bc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x20530)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x204a8);
        else owner = 0;
        return owner;
    }
};
template <> struct NessArticlePool<3> {
    static inline Weapon* find(char* pool, NessArticleSelector& selector, NessArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1e910)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1e888);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1ccfc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1cc74);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1b0e8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1b060);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x194d4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1944c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x178c0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x17838);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x15cac)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x15c24);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x14098)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x14010);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x12484)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x123fc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x10870)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x107e8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xec5c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xebd4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xd048)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xcfc0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xb434)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xb3ac);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9820)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x9798);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7c0c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7b84);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5ff8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x5f70);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x43e4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x435c);
        else owner = 0;
        return owner;
    }
};
template <> struct NessArticlePool<4> {
    static inline Weapon* find(char* pool, NessArticleSelector& selector, NessArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x2264)) == true ? reinterpret_cast<Weapon*>(pool + 0x21dc) : 0;
        return owner;
    }
};
template <> struct NessArticlePool<5> {
    static inline Weapon* find(char* pool, NessArticleSelector& selector, NessArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true ? reinterpret_cast<Weapon*>(pool + 0x18) : 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const NessArticleActivation<Kind>& activation,
                                  const NessArticleDeactivation& deactivation) {
    if (Kind >= 6) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    NessArticleSelector selector;
    Weapon* owner = NessArticlePool<Kind>::find(pool, selector, NessArticleSearch());
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

extern "C" soArticle& fn_101_D8AC(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, NessArticleActivation<0>(), NessArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, NessArticleActivation<1>(), NessArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, NessArticleActivation<2>(), NessArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, NessArticleActivation<3>(), NessArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, NessArticleActivation<4>(), NessArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, NessArticleActivation<5>(), NessArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, NessArticleActivation<6>(), NessArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, NessArticleActivation<7>(), NessArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, NessArticleActivation<8>(), NessArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, NessArticleActivation<9>(), NessArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, NessArticleActivation<10>(), NessArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, NessArticleActivation<11>(), NessArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, NessArticleActivation<12>(), NessArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, NessArticleActivation<13>(), NessArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, NessArticleActivation<14>(), NessArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, NessArticleActivation<15>(), NessArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, NessArticleActivation<16>(), NessArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
