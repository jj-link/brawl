#include <wn/weapon.h>
#include <so/article/so_article.h>

#pragma force_active on

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
    virtual int slot10();
};

struct Base {
    int a;
    int b;
};

class MainObj : public Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual Object_vptr_0* m4();
};

struct Wrapper {
    MainObj* obj;
};

struct SamusInput {
    char padding[0xd8];
    Wrapper* wrapper;
};

extern "C" {
extern unsigned char lbl_27_bss_1CC[];

void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);

void* fn_94_17EEC();
unsigned int fn_94_17F5C(Weapon*, SamusInput*);
unsigned int fn_94_1820C(Weapon*, SamusInput*);
unsigned int fn_27_300930(void*, Weapon*, SamusInput*, int);
unsigned int fn_27_3009CC(void*, Weapon*, SamusInput*);
}

namespace {

struct Status {
    bool flags[2];

    Status() {
        flags[0] = false;
        flags[1] = false;
    }
};

template <unsigned Kind>
struct Activation {
    unsigned int operator()(Weapon* owner, SamusInput* input) const {
        if (Kind == 0) {
            int value = input->wrapper->obj->m4()->slot10();
            return fn_27_300930(fn_94_17EEC(), owner, input, value);
        }
        if (Kind == 1) {
            return fn_27_3009CC(fn_94_17EEC(), owner, input);
        }
        if (Kind == 2) {
            return fn_94_17F5C(owner, input);
        }
        return fn_94_1820C(owner, input);
    }
};

struct Deactivation {
    void operator()(Weapon* owner) const {
        owner->deactivateArticle();
    }
};

class Selector {
public:
    soArticle* article;

    Selector() {
        fn_27_8D7C4(this);
    }

    void release(short destroy) {
        fn_27_8D7D0(this, destroy);
    }

    bool select(soArticle* candidate) {
        return fn_27_8D810(this, candidate);
    }
};

struct Search {
    bool operator()(Selector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};

template <unsigned Kind>
struct Pool {
    static inline Weapon* find(char*, Selector&, Search) {
        return 0;
    }
};

template <>
struct Pool<0> {
    static inline Weapon* find(char* p, Selector& selector, Search search) {
        return search(selector, reinterpret_cast<soArticle*>(p + 0xfccc)) == true
            ? reinterpret_cast<Weapon*>(p + 0xfc44)
            : 0;
    }
};

template <>
struct Pool<1> {
    static inline Weapon* find(char* p, Selector& selector, Search search) {
        if (search(selector, reinterpret_cast<soArticle*>(p + 0xe4d4)) == true)
            return reinterpret_cast<Weapon*>(p + 0xe44c);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0xcce4)) == true)
            return reinterpret_cast<Weapon*>(p + 0xcc5c);
        return 0;
    }
};

template <>
struct Pool<2> {
    static inline Weapon* find(char* p, Selector& selector, Search search) {
        return search(selector, reinterpret_cast<soArticle*>(p + 0xaf84)) == true
            ? reinterpret_cast<Weapon*>(p + 0xaefc)
            : 0;
    }
};

template <>
struct Pool<3> {
    static inline Weapon* find(char* p, Selector& selector, Search search) {
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x99a4)) == true)
            return reinterpret_cast<Weapon*>(p + 0x991c);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x83cc)) == true)
            return reinterpret_cast<Weapon*>(p + 0x8344);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x6df4)) == true)
            return reinterpret_cast<Weapon*>(p + 0x6d6c);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x581c)) == true)
            return reinterpret_cast<Weapon*>(p + 0x5794);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x4244)) == true)
            return reinterpret_cast<Weapon*>(p + 0x41bc);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x2c6c)) == true)
            return reinterpret_cast<Weapon*>(p + 0x2be4);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0x1694)) == true)
            return reinterpret_cast<Weapon*>(p + 0x160c);
        if (search(selector, reinterpret_cast<soArticle*>(p + 0xbc)) == true)
            return reinterpret_cast<Weapon*>(p + 0x34);
        return 0;
    }
};

template <unsigned Kind>
inline soArticle* allocate(
    char* p,
    SamusInput* input,
    const Activation<Kind>& activation,
    const Deactivation& deactivation
) {
    Status status;

    if (Kind >= 4)
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);

    Selector selector;
    p = reinterpret_cast<char*>(Pool<Kind>::find(p, selector, Search()));
    Weapon* owner = reinterpret_cast<Weapon*>(p);

    if (!owner) {
        owner = reinterpret_cast<Weapon*>(selector.article);
        if (owner)
            owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
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

extern "C" soArticle* fn_94_188C0(char* p, unsigned kind, SamusInput* input) {
    switch (kind) {
    case 0: return allocate<0>(p, input, Activation<0>(), Deactivation());
    case 1: return allocate<1>(p, input, Activation<1>(), Deactivation());
    case 2: return allocate<2>(p, input, Activation<2>(), Deactivation());
    case 3: return allocate<3>(p, input, Activation<3>(), Deactivation());
    case 4: return allocate<4>(p, input, Activation<4>(), Deactivation());
    case 5: return allocate<5>(p, input, Activation<5>(), Deactivation());
    case 6: return allocate<6>(p, input, Activation<6>(), Deactivation());
    case 7: return allocate<7>(p, input, Activation<7>(), Deactivation());
    case 8: return allocate<8>(p, input, Activation<8>(), Deactivation());
    case 9: return allocate<9>(p, input, Activation<9>(), Deactivation());
    case 10: return allocate<10>(p, input, Activation<10>(), Deactivation());
    case 11: return allocate<11>(p, input, Activation<11>(), Deactivation());
    case 12: return allocate<12>(p, input, Activation<12>(), Deactivation());
    case 13: return allocate<13>(p, input, Activation<13>(), Deactivation());
    case 14: return allocate<14>(p, input, Activation<14>(), Deactivation());
    case 15: return allocate<15>(p, input, Activation<15>(), Deactivation());
    case 16: return allocate<16>(p, input, Activation<16>(), Deactivation());
    default: return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
