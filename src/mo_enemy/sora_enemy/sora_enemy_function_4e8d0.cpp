#pragma force_active on
#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_41_4E748(void*, soModuleAccesser*);
unsigned int fn_41_4E81C(void*, soModuleAccesser*);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
};

namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
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
template <unsigned Kind> struct ArticleTraits {
    typedef soArticle Owner;
    static Owner* recover(soArticle* article) { return article; }
    static void deactivate(Owner* owner) { reinterpret_cast<Object_vptr_0*>(owner)->slot21(); }
    static unsigned int activate(Owner* owner, soModuleAccesser* accesser) { return fn_41_4E748(owner, accesser); }
    static soArticle& article(Owner* owner) { return *owner; }
};
template <> struct ArticleTraits<0> {
    typedef char Owner;
    static Owner* recover(soArticle* article) {
        char* owner = reinterpret_cast<char*>(article);
        if (owner) owner -= 0x94;
        return owner;
    }
    static void deactivate(Owner* owner) { reinterpret_cast<Weapon*>(owner + 0xc)->deactivateArticle(); }
    static unsigned int activate(Owner* owner, soModuleAccesser* accesser) { return fn_41_4E81C(owner, accesser); }
    static soArticle& article(Owner* owner) { return *reinterpret_cast<soArticle*>(owner + 0x94); }
};
template <unsigned Kind> struct ArticleActivation {
    unsigned int operator()(typename ArticleTraits<Kind>::Owner* owner, soModuleAccesser* accesser) const {
        return ArticleTraits<Kind>::activate(owner, accesser);
    }
};
template <unsigned Kind> struct ArticleDeactivation {
    void operator()(typename ArticleTraits<Kind>::Owner* owner) const { ArticleTraits<Kind>::deactivate(owner); }
};
template <unsigned Kind> struct ArticlePool {
    static inline typename ArticleTraits<Kind>::Owner* find(char*, ArticleSelector&, ArticleSearch) { return 0; }
};
template <> struct ArticlePool<0> {
    static inline char* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        char* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xe0)) == true ? pool + 0x4c : 0;
        return owner;
    }
};
template <> struct ArticlePool<1> {
    static inline soArticle* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        soArticle* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x18)) == true ? reinterpret_cast<soArticle*>(pool + 0x18) : 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const ArticleActivation<Kind>& activation,
                                  const ArticleDeactivation<Kind>& deactivation) {
    ArticleStatus status;
    if (Kind >= 2) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    ArticleSelector selector;
    typename ArticleTraits<Kind>::Owner* owner = ArticlePool<Kind>::find(pool, selector, ArticleSearch());
    if (!owner) {
        owner = ArticleTraits<Kind>::recover(selector.article);
        if (!owner) {
            selector.release(-1);
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    if (activation(owner, accesser) == true) {
        selector.release(-1);
        return ArticleTraits<Kind>::article(owner);
    }
    selector.release(-1);
    return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}
extern "C" soArticle& fn_41_4E8D0(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, ArticleActivation<0>(), ArticleDeactivation<0>());
    case 1: return allocateArticle<1>(pool, accesser, ArticleActivation<1>(), ArticleDeactivation<1>());
    case 2: return allocateArticle<2>(pool, accesser, ArticleActivation<2>(), ArticleDeactivation<2>());
    case 3: return allocateArticle<3>(pool, accesser, ArticleActivation<3>(), ArticleDeactivation<3>());
    case 4: return allocateArticle<4>(pool, accesser, ArticleActivation<4>(), ArticleDeactivation<4>());
    case 5: return allocateArticle<5>(pool, accesser, ArticleActivation<5>(), ArticleDeactivation<5>());
    case 6: return allocateArticle<6>(pool, accesser, ArticleActivation<6>(), ArticleDeactivation<6>());
    case 7: return allocateArticle<7>(pool, accesser, ArticleActivation<7>(), ArticleDeactivation<7>());
    case 8: return allocateArticle<8>(pool, accesser, ArticleActivation<8>(), ArticleDeactivation<8>());
    case 9: return allocateArticle<9>(pool, accesser, ArticleActivation<9>(), ArticleDeactivation<9>());
    case 10: return allocateArticle<10>(pool, accesser, ArticleActivation<10>(), ArticleDeactivation<10>());
    case 11: return allocateArticle<11>(pool, accesser, ArticleActivation<11>(), ArticleDeactivation<11>());
    case 12: return allocateArticle<12>(pool, accesser, ArticleActivation<12>(), ArticleDeactivation<12>());
    case 13: return allocateArticle<13>(pool, accesser, ArticleActivation<13>(), ArticleDeactivation<13>());
    case 14: return allocateArticle<14>(pool, accesser, ArticleActivation<14>(), ArticleDeactivation<14>());
    case 15: return allocateArticle<15>(pool, accesser, ArticleActivation<15>(), ArticleDeactivation<15>());
    case 16: return allocateArticle<16>(pool, accesser, ArticleActivation<16>(), ArticleDeactivation<16>());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
