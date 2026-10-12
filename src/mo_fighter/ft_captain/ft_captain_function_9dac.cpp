// The switch table occupies a four-byte-aligned range in the original REL.
#pragma section data_type ".data$captain9DAC" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_100_8E68(Weapon*, soModuleAccesser*);
bool fn_100_9028(Weapon*, soModuleAccesser*);
}

namespace {
struct CaptainArticleStatus {
    bool flags[2];
    CaptainArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct CaptainArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        switch (Kind) {
        case 0: return fn_100_8E68(owner, accesser);
        case 1: return fn_100_9028(owner, accesser);
        default: return false;
        }
    }
};
struct CaptainArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class CaptainArticleSelector {
public:
    soArticle* article;
    CaptainArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct CaptainArticleSearch {
    bool operator()(CaptainArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct CaptainArticlePool {
    static inline Weapon* find(char*, CaptainArticleSelector&, CaptainArticleSearch) { return 0; }
};
template <> struct CaptainArticlePool<0> {
    static inline Weapon* find(char* pool, CaptainArticleSelector& selector, CaptainArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x1fd4)) == true ? reinterpret_cast<Weapon*>(pool + 0x1f4c) : 0;
        return owner;
    }
};
template <> struct CaptainArticlePool<1> {
    static inline Weapon* find(char* pool, CaptainArticleSelector& selector, CaptainArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true ? reinterpret_cast<Weapon*>(pool + 0x18) : 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const CaptainArticleActivation<Kind>& activation,
                                  const CaptainArticleDeactivation& deactivation) {
    CaptainArticleStatus status;
    if (Kind >= 2) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    CaptainArticleSelector selector;
    Weapon* owner = CaptainArticlePool<Kind>::find(pool, selector, CaptainArticleSearch());
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

extern "C" soArticle& fn_100_9DAC(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, CaptainArticleActivation<0>(), CaptainArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, CaptainArticleActivation<1>(), CaptainArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, CaptainArticleActivation<2>(), CaptainArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, CaptainArticleActivation<3>(), CaptainArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, CaptainArticleActivation<4>(), CaptainArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, CaptainArticleActivation<5>(), CaptainArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, CaptainArticleActivation<6>(), CaptainArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, CaptainArticleActivation<7>(), CaptainArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, CaptainArticleActivation<8>(), CaptainArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, CaptainArticleActivation<9>(), CaptainArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, CaptainArticleActivation<10>(), CaptainArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, CaptainArticleActivation<11>(), CaptainArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, CaptainArticleActivation<12>(), CaptainArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, CaptainArticleActivation<13>(), CaptainArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, CaptainArticleActivation<14>(), CaptainArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, CaptainArticleActivation<15>(), CaptainArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, CaptainArticleActivation<16>(), CaptainArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
