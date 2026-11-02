#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
unsigned fn_27_8D810(void*, void*);
unsigned fn_41_40610(void*, void*);
unsigned fn_41_404F0(void*, void*);
}

namespace {

struct BaseData {
    char pad[0x3C];
};

struct Module : BaseData {
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
};

struct ArticleVt {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
};

struct ArticleStatus {
    unsigned char flags[2];
    ArticleStatus() { flags[0] = 0; flags[1] = 0; }
};

class ArticleSelector {
public:
    void* article;
    ArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    unsigned select(void* candidate) { return fn_27_8D810(this, candidate); }
};

struct ArticleSearch {
    unsigned operator()(ArticleSelector& selector, void* candidate) const {
        return selector.select(candidate);
    }
};

template <unsigned Kind>
struct Pool {
    static inline void* find(char*, ArticleSelector&, ArticleSearch) { return 0; }
};

template <>
struct Pool<0> {
    static inline void* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        void* owner;
        if (search(selector, pool + 0x254c) == 1)
            owner = pool + 0x24b8;
        else if (search(selector, pool + 0x1d4) == 1)
            owner = pool + 0x140;
        else
            owner = 0;
        return owner;
    }
};

template <>
struct Pool<1> {
    static inline void* find(char* pool, ArticleSelector& selector, ArticleSearch search) {
        void* owner;
        if (search(selector, pool + 0x108) == 1)
            owner = pool + 0x108;
        else if (search(selector, pool + 0xdc) == 1)
            owner = pool + 0xdc;
        else if (search(selector, pool + 0xb0) == 1)
            owner = pool + 0xb0;
        else if (search(selector, pool + 0x84) == 1)
            owner = pool + 0x84;
        else if (search(selector, pool + 0x58) == 1)
            owner = pool + 0x58;
        else if (search(selector, pool + 0x2c) == 1)
            owner = pool + 0x2c;
        else
            owner = 0;
        return owner;
    }
};

template <unsigned Kind>
struct Activation {
    unsigned operator()(void* object, void* accesser) const {
        if (Kind == 0) return fn_41_40610(object, accesser);
        if (Kind == 1) return fn_41_404F0(object, accesser);
        return 0;
    }
};

template <unsigned Kind>
struct Deactivation {
    void operator()(void* object) const {
        if (Kind == 0) {
            ((Module*)((char*)object + 0xC))->v1f8();
        } else if (Kind == 1) {
            ((ArticleVt*)object)->s21();
        }
    }
};

template <unsigned Kind>
inline void* allocateArticle(char* pool, void* accesser,
                             const Activation<Kind>& activation,
                             const Deactivation<Kind>& deactivation) {
    ArticleStatus status;
    if (Kind >= 2) return (void*)lbl_27_bss_1CC;

    ArticleSelector selector;
    void* object = Pool<Kind>::find(pool, selector, ArticleSearch());
    if (!object) {
        object = selector.article;
        if (Kind == 0 && object) object = (char*)object - 0x94;
        if (!object) {
            selector.release(-1);
            return (void*)lbl_27_bss_1CC;
        }
        deactivation(object);
    }

    if (activation(object, accesser) == 1) {
        selector.release(-1);
        if (Kind == 0) return (char*)object + 0x94;
        return object;
    }

    selector.release(-1);
    return (void*)lbl_27_bss_1CC;
}

}

extern "C" void* fn_41_40820(char* pool, unsigned kind, void* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, Activation<0>(), Deactivation<0>());
    case 1: return allocateArticle<1>(pool, accesser, Activation<1>(), Deactivation<1>());
    case 2: return allocateArticle<2>(pool, accesser, Activation<2>(), Deactivation<2>());
    case 3: return allocateArticle<3>(pool, accesser, Activation<3>(), Deactivation<3>());
    case 4: return allocateArticle<4>(pool, accesser, Activation<4>(), Deactivation<4>());
    case 5: return allocateArticle<5>(pool, accesser, Activation<5>(), Deactivation<5>());
    case 6: return allocateArticle<6>(pool, accesser, Activation<6>(), Deactivation<6>());
    case 7: return allocateArticle<7>(pool, accesser, Activation<7>(), Deactivation<7>());
    case 8: return allocateArticle<8>(pool, accesser, Activation<8>(), Deactivation<8>());
    case 9: return allocateArticle<9>(pool, accesser, Activation<9>(), Deactivation<9>());
    case 10: return allocateArticle<10>(pool, accesser, Activation<10>(), Deactivation<10>());
    case 11: return allocateArticle<11>(pool, accesser, Activation<11>(), Deactivation<11>());
    case 12: return allocateArticle<12>(pool, accesser, Activation<12>(), Deactivation<12>());
    case 13: return allocateArticle<13>(pool, accesser, Activation<13>(), Deactivation<13>());
    case 14: return allocateArticle<14>(pool, accesser, Activation<14>(), Deactivation<14>());
    case 15: return allocateArticle<15>(pool, accesser, Activation<15>(), Deactivation<15>());
    case 16: return allocateArticle<16>(pool, accesser, Activation<16>(), Deactivation<16>());
    default: return (void*)lbl_27_bss_1CC;
    }
}
