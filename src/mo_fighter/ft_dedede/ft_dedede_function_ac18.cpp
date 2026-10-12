// The allocation switch table is four-byte aligned in the original REL.
#pragma section data_type ".data$dededeAC18" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#include <so/resource/so_resource_module_impl.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_117_8BE8(Weapon*, soModuleAccesser*);
bool fn_117_8E98(Weapon*, soModuleAccesser*);
void* fn_117_946C();
bool fn_27_395E34(void*, Weapon*, soModuleAccesser*, unsigned int);
bool fn_117_1FB20(Weapon*, soModuleAccesser*);
bool fn_117_8F34(Weapon*, soModuleAccesser*);
}

namespace {
struct DededeArticleStatus {
    bool flags[2];
    DededeArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct DededeArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        switch (Kind) {
        case 0: return fn_117_8BE8(owner, accesser);
        case 1: return fn_117_8E98(owner, accesser);
        case 2: {
            unsigned int resourceId = accesser->m_enumerationStart->m_resourceModule->getResourceIdAccesser()->getEtcResId();
            return fn_27_395E34(fn_117_946C(), owner, accesser, resourceId);
        }
        case 3: return fn_117_1FB20(owner, accesser);
        case 4: return fn_117_8F34(owner, accesser);
        default: return false;
        }
    }
};
struct DededeArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class DededeArticleSelector {
public:
    soArticle* article;
    DededeArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct DededeArticleSearch {
    bool operator()(DededeArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct DededeArticlePool {
    static inline Weapon* find(char*, DededeArticleSelector&, DededeArticleSearch) { return 0; }
};
template <> struct DededeArticlePool<0> {
    static inline Weapon* find(char* pool, DededeArticleSelector& selector, DededeArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3cf6c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3cee4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3b098)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3b010);
        else owner = 0;
        return owner;
    }
};
template <> struct DededeArticlePool<1> {
    static inline Weapon* find(char* pool, DededeArticleSelector& selector, DededeArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x39344)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x392bc);
        else owner = 0;
        return owner;
    }
};
template <> struct DededeArticlePool<2> {
    static inline Weapon* find(char* pool, DededeArticleSelector& selector, DededeArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x37380)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x372f8);
        else owner = 0;
        return owner;
    }
};
template <> struct DededeArticlePool<3> {
    static inline Weapon* find(char* pool, DededeArticleSelector& selector, DededeArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x353bc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x35334);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x33400)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x33378);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x31444)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x313bc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2f488)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2f400);
        else owner = 0;
        return owner;
    }
};
template <> struct DededeArticlePool<4> {
    static inline Weapon* find(char* pool, DededeArticleSelector& selector, DededeArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2ccb0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2cc28);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2a4ec)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2a464);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x27d28)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x27ca0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x25564)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x254dc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x22da0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x22d18);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x205dc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x20554);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1de18)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1dd90);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1b654)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1b5cc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x18e90)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18e08);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x166cc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x16644);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13f08)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x13e80);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x11744)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x116bc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xef80)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xeef8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xc7bc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xc734);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9ff8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x9f70);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7834)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x77ac);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5070)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x4fe8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x28ac)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2824);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xe8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x60);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const DededeArticleActivation<Kind>& activation,
                                  const DededeArticleDeactivation& deactivation) {
    DededeArticleStatus status;
    if (Kind >= 5) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    DededeArticleSelector selector;
    Weapon* owner = DededeArticlePool<Kind>::find(pool, selector, DededeArticleSearch());
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

extern "C" soArticle& fn_117_AC18(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, DededeArticleActivation<0>(), DededeArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, DededeArticleActivation<1>(), DededeArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, DededeArticleActivation<2>(), DededeArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, DededeArticleActivation<3>(), DededeArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, DededeArticleActivation<4>(), DededeArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, DededeArticleActivation<5>(), DededeArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, DededeArticleActivation<6>(), DededeArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, DededeArticleActivation<7>(), DededeArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, DededeArticleActivation<8>(), DededeArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, DededeArticleActivation<9>(), DededeArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, DededeArticleActivation<10>(), DededeArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, DededeArticleActivation<11>(), DededeArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, DededeArticleActivation<12>(), DededeArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, DededeArticleActivation<13>(), DededeArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, DededeArticleActivation<14>(), DededeArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, DededeArticleActivation<15>(), DededeArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, DededeArticleActivation<16>(), DededeArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
