#include <wn/weapon.h>
#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_105_BF18(Weapon*, void*);
unsigned int fn_105_C084(Weapon*, void*);
unsigned int fn_105_C1D0(Weapon*, void*);
unsigned int fn_105_1BBCC(Weapon*, void*);
void* fn_105_B02C(void*);
unsigned int fn_27_346000(void*, Weapon*, void*, void*);
}

namespace {
class ArticleIface {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7();
    virtual void* f8();
    virtual void* f9();
    virtual void* f10();
    virtual void* f11();
    virtual void* f12();
    virtual void* f13();
    virtual void* f14();
    virtual void* f15();
};

struct ArticlePad8 {
    int pad0;
    int pad1;
};

class ArticleOuter8 : public ArticlePad8 {
public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
};

struct ArticleStatus {
    bool flags[2];
    ArticleStatus() { flags[0] = false; flags[1] = false; }
};

template <unsigned Kind> struct ArticleActivation {
    unsigned int operator()(Weapon* owner, void* accesser) const { return 0; }
};
template <> struct ArticleActivation<0> {
    unsigned int operator()(Weapon* owner, void* accesser) const { return fn_105_BF18(owner, accesser); }
};
template <> struct ArticleActivation<1> {
    unsigned int operator()(Weapon* owner, void* accesser) const {
        char* holder = *reinterpret_cast<char**>(static_cast<char*>(accesser) + 0xd8);
        void* obj = *reinterpret_cast<void**>(holder);
        void* sub = reinterpret_cast<ArticleOuter8*>(obj)->f4();
        void* temp = reinterpret_cast<ArticleIface*>(sub)->f15();
        void* result = fn_105_B02C(temp);
        return fn_27_346000(result, owner, accesser, temp);
    }
};
template <> struct ArticleActivation<2> {
    unsigned int operator()(Weapon* owner, void* accesser) const { return fn_105_C084(owner, accesser); }
};
template <> struct ArticleActivation<3> {
    unsigned int operator()(Weapon* owner, void* accesser) const { return fn_105_C1D0(owner, accesser); }
};
template <> struct ArticleActivation<4> {
    unsigned int operator()(Weapon* owner, void* accesser) const { return fn_105_1BBCC(owner, accesser); }
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
    static Weapon* find(char*, ArticleSelector&, ArticleSearch) { return 0; }
};
template <> struct ArticlePool<0> {
    static Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x15b4c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x15ac4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13bfc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x13b74);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x11cac)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x11c24);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<1> {
    static Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xf8c8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xf840);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xd4f4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xd46c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xb120)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xb098);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x8d4c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x8cc4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x6978)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x68f0);
        else owner = 0;
        return owner;
    }
};
template <> struct ArticlePool<2> {
    static Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x41e0)) == true ? reinterpret_cast<Weapon*>(pool + 0x4158) : 0;
        return owner;
    }
};
template <> struct ArticlePool<3> {
    static Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x20c8)) == true ? reinterpret_cast<Weapon*>(pool + 0x2040) : 0;
        return owner;
    }
};
template <> struct ArticlePool<4> {
    static Weapon* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true ? reinterpret_cast<Weapon*>(pool + 0x18) : 0;
        return owner;
    }
};

template <unsigned Kind>
inline void* allocateArticle(char* pool, void* accesser,
                             const ArticleActivation<Kind>& activation,
                             const ArticleDeactivation& deactivation) {
    ArticleStatus status;
    if (Kind >= 5) return lbl_27_bss_1CC;
    ArticleSelector selector;
    Weapon* owner = ArticlePool<Kind>::find(pool, selector, ArticleSearch());
    if (!owner) {
        owner = static_cast<Weapon*>(selector.article);
        if (!owner) {
            selector.release(-1);
            return lbl_27_bss_1CC;
        }
        deactivation(owner);
    }
    if (activation(owner, accesser) == true) {
        selector.release(-1);
        return reinterpret_cast<char*>(owner) + 0x88;
    }
    selector.release(-1);
    return lbl_27_bss_1CC;
}
}

extern "C" void* fn_105_E1DC(char* pool, unsigned kind, void* accesser) {
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
    default: return lbl_27_bss_1CC;
    }
}
