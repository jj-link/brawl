#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#include <so/resource/so_resource_module_impl.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
void* fn_116_17F48();
bool fn_27_372724(void*, Weapon*, soModuleAccesser*, unsigned int);
}

namespace {
struct PokeArticleStatus {
    bool flags[2];

    PokeArticleStatus() {
        flags[0] = false;
        flags[1] = false;
    }
};

template <unsigned Kind>
struct PokeArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        switch (Kind) {
        case 0: {
            unsigned int resourceId =
                accesser->m_enumerationStart->m_resourceModule
                    ->getResourceIdAccesser()->getEtcResId();
            return fn_27_372724(fn_116_17F48(), owner, accesser, resourceId);
        }
        default:
            return false;
        }
    }
};

struct PokeArticleDeactivation {
    void operator()(Weapon* owner) const {
        owner->deactivateArticle();
    }
};

class PokeArticleSelector {
public:
    soArticle* article;

    PokeArticleSelector() {
        fn_27_8D7C4(this);
    }

    void release(short destroy) {
        fn_27_8D7D0(this, destroy);
    }

    bool select(soArticle* candidate) {
        return fn_27_8D810(this, candidate);
    }
};

struct PokeArticleSearch {
    bool operator()(PokeArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};

template <unsigned Kind>
struct PokeArticlePool {
    static inline Weapon* find(char*, PokeArticleSelector&, PokeArticleSearch) {
        return 0;
    }
};

template <>
struct PokeArticlePool<0> {
    static inline Weapon* find(char* pool, PokeArticleSelector& selector,
                               PokeArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xcbf8)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0xcb70);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xb564)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0xb4dc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9ed0)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x9e48);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x883c)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x87b4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x71a8)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x7120);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5b14)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x5a8c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4480)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x43f8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2dec)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x2d64);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1758)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x16d0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xc4)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x3c);
        else
            owner = 0;
        return owner;
    }
};

template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const PokeArticleActivation<Kind>& activation,
                                  const PokeArticleDeactivation& deactivation) {
    PokeArticleStatus status;
    if (Kind >= 1)
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);

    PokeArticleSelector selector;
    Weapon* owner = PokeArticlePool<Kind>::find(pool, selector, PokeArticleSearch());
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

extern "C" soArticle& fn_116_18A48(char* pool, unsigned kind,
                                   soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, PokeArticleActivation<0>(), PokeArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, PokeArticleActivation<1>(), PokeArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, PokeArticleActivation<2>(), PokeArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, PokeArticleActivation<3>(), PokeArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, PokeArticleActivation<4>(), PokeArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, PokeArticleActivation<5>(), PokeArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, PokeArticleActivation<6>(), PokeArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, PokeArticleActivation<7>(), PokeArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, PokeArticleActivation<8>(), PokeArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, PokeArticleActivation<9>(), PokeArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, PokeArticleActivation<10>(), PokeArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, PokeArticleActivation<11>(), PokeArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, PokeArticleActivation<12>(), PokeArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, PokeArticleActivation<13>(), PokeArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, PokeArticleActivation<14>(), PokeArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, PokeArticleActivation<15>(), PokeArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, PokeArticleActivation<16>(), PokeArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
