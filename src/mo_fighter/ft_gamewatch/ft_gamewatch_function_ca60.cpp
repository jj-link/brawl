#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_107_B64C(Weapon*, soModuleAccesser*);
bool fn_107_B6FC(Weapon*, soModuleAccesser*);
bool fn_107_B828(Weapon*, soModuleAccesser*);
bool fn_107_B930(Weapon*, soModuleAccesser*);
bool fn_107_BA90(Weapon*, soModuleAccesser*);
bool fn_107_BB98(Weapon*, soModuleAccesser*);
bool fn_107_BD14(Weapon*, soModuleAccesser*);
}

namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct ArticleActivation;
template <> struct ArticleActivation<0> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_B64C(owner, accesser);
    }
};
template <> struct ArticleActivation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_B6FC(owner, accesser);
    }
};
template <> struct ArticleActivation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_B828(owner, accesser);
    }
};
template <> struct ArticleActivation<3> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_B930(owner, accesser);
    }
};
template <> struct ArticleActivation<4> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_BA90(owner, accesser);
    }
};
template <> struct ArticleActivation<5> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_BB98(owner, accesser);
    }
};
template <> struct ArticleActivation<6> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_107_BD14(owner, accesser);
    }
};
template <unsigned Kind> struct ArticleActivation {
    unsigned int operator()(Weapon*, soModuleAccesser*) const { return 0; }
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
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x15540)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x154b8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13394)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1330c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x111e8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x11160);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xf03c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xefb4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xce90)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xce08);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<1> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xad94)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xad0c);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<2> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x8ca8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x8c20);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<3> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x6ba0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x6b18);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<4> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4ab4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x4a2c);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<5> {
    static inline Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x218c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2104);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<6> {
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
    if (Kind >= 7) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
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

extern "C" soArticle& fn_107_CA60(char* pool, unsigned kind, soModuleAccesser* accesser) {
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
