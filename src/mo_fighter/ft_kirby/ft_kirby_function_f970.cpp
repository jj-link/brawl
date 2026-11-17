#include <wn/weapon.h>
#include <so/article/so_article.h>
#pragma force_active on

class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4();
    virtual int fn_96_23CE4(int);
};

struct KirbyInputA {
    char pad[0x28];
    int unk28;
    int getId() const { return unk28; }
};

struct KirbyInputB {
    char pad[0x84];
    Class_CD28* obj84;
};

struct KirbyInput {
    char pad0[0x8];
    KirbyInputA* unk8;
    char pad1[0xCC];
    KirbyInputB* unkD8;
};

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
int fn_27_8D6EC(int, int, int);
void* fn_27_8D78C();
unsigned int fn_96_B5A4(Weapon*, KirbyInput*);
unsigned int fn_96_B638(Weapon*, KirbyInput*);
unsigned int fn_96_B8A4(Weapon*, KirbyInput*);
unsigned int fn_96_B494(Weapon*, KirbyInput*);
unsigned int fn_96_BC74(Weapon*, KirbyInput*);
unsigned int fn_96_BDE0(Weapon*, KirbyInput*);
unsigned int fn_96_BEC0(Weapon*, KirbyInput*);
}

namespace {
struct Status {
    bool flags[2];
    Status() {
        flags[0] = false;
        flags[1] = false;
    }
};

struct StatusBig : Status {
    char pad[12];
};

template <unsigned Kind>
struct Activation {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_BEC0(owner, input);
    }
};

template <>
struct Activation<0> {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_B5A4(owner, input);
    }
};

template <>
struct Activation<1> {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_B638(owner, input);
    }
};

template <>
struct Activation<2> {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_B8A4(owner, input);
    }
};

template <>
struct Activation<3> {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_B494(owner, input);
    }
};

template <>
struct Activation<4> {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_BC74(owner, input);
    }
};

template <>
struct Activation<5> {
    unsigned int operator()(Weapon* owner, KirbyInput* input) const {
        return fn_96_BDE0(owner, input);
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

class SelectorBig {
public:
    soArticle* article;

    SelectorBig() {
        fn_27_8D7C4(&article);
    }

    void release(short destroy) {
        fn_27_8D7D0(&article, destroy);
    }

    bool select(soArticle* candidate) {
        return fn_27_8D810(&article, candidate);
    }
};

template <unsigned Kind>
struct SelectorType {
    typedef Selector Type;
};

template <>
struct SelectorType<0> {
    typedef SelectorBig Type;
};

struct Search {
    bool operator()(Selector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }

    bool operator()(SelectorBig& selector, soArticle* candidate) const {
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
    static inline Weapon* find(char* p, SelectorBig& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x11008)) == true
            ? reinterpret_cast<Weapon*>(p + 0x10F80) : 0;
    }
};

template <>
struct Pool<1> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0xF020)) == true
            ? reinterpret_cast<Weapon*>(p + 0xEF98) : 0;
    }
};

template <>
struct Pool<2> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0xD03C)) == true
            ? reinterpret_cast<Weapon*>(p + 0xCFB4) : 0;
    }
};

template <>
struct Pool<3> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0xAF34)) == true
            ? reinterpret_cast<Weapon*>(p + 0xAEAC) : 0;
    }
};

template <>
struct Pool<4> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x8EB0)) == true
            ? reinterpret_cast<Weapon*>(p + 0x8E28) : 0;
    }
};

template <>
struct Pool<5> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x72C4)) == true
            ? reinterpret_cast<Weapon*>(p + 0x723C) : 0;
    }
};

template <>
struct Pool<6> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x5BF0)) == true
            ? reinterpret_cast<Weapon*>(p + 0x5B68) : 0;
    }
};

template <>
struct Pool<7> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x451C)) == true
            ? reinterpret_cast<Weapon*>(p + 0x4494) : 0;
    }
};

template <>
struct Pool<8> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x2E48)) == true
            ? reinterpret_cast<Weapon*>(p + 0x2DC0) : 0;
    }
};

template <>
struct Pool<9> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0x1774)) == true
            ? reinterpret_cast<Weapon*>(p + 0x16EC) : 0;
    }
};

template <>
struct Pool<10> {
    static inline Weapon* find(char* p, Selector& s, Search f) {
        return f(s, reinterpret_cast<soArticle*>(p + 0xA0)) == true
            ? reinterpret_cast<Weapon*>(p + 0x18) : 0;
    }
};

template <unsigned Kind>
inline soArticle* allocate(char* p, KirbyInput* input, Status& status,
                           const Activation<Kind>& activation,
                           const Deactivation& deactivation) {
    if (Kind == 11) {
        if (input->unkD8->obj84->fn_96_23CE4(11) >= 2)
            return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        if (fn_27_8D6EC(0x59, 0xB, input->unk8->getId()) == 0)
            return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        return reinterpret_cast<soArticle*>(fn_27_8D78C());
    }
    if (Kind >= 12) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    typename SelectorType<Kind>::Type selector;
    Weapon* owner = Pool<Kind>::find(p, selector, Search());

    if (!owner) {
        owner = reinterpret_cast<Weapon*>(selector.article);
        if (owner) {
            owner = reinterpret_cast<Weapon*>(
                reinterpret_cast<char*>(owner) - 0x88);
        }
        if (!owner) {
            selector.release(-1);
            return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }

    if (activation(owner, input) == 1) {
        selector.release(-1);
        return reinterpret_cast<soArticle*>(
            reinterpret_cast<char*>(owner) + 0x88);
    }

    selector.release(-1);
    return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}

extern "C" soArticle* fn_96_F970(char* p, unsigned kind, KirbyInput* input) {
    switch (kind) {
    case 0: {
        Status status;
        return allocate<0>(p, input, status, Activation<0>(), Deactivation());
    }
    case 1: {
        Status status;
        return allocate<1>(p, input, status, Activation<1>(), Deactivation());
    }
    case 2: {
        Status status;
        return allocate<2>(p, input, status, Activation<2>(), Deactivation());
    }
    case 3: {
        Status status;
        return allocate<3>(p, input, status, Activation<3>(), Deactivation());
    }
    case 4: {
        Status status;
        return allocate<4>(p, input, status, Activation<4>(), Deactivation());
    }
    case 5: {
        Status status;
        return allocate<5>(p, input, status, Activation<5>(), Deactivation());
    }
    case 6: {
        Status status;
        return allocate<6>(p, input, status, Activation<6>(), Deactivation());
    }
    case 7: {
        Status status;
        return allocate<7>(p, input, status, Activation<7>(), Deactivation());
    }
    case 8: {
        Status status;
        return allocate<8>(p, input, status, Activation<8>(), Deactivation());
    }
    case 9: {
        Status status;
        return allocate<9>(p, input, status, Activation<9>(), Deactivation());
    }
    case 10: {
        Status status;
        return allocate<10>(p, input, status, Activation<10>(), Deactivation());
    }
    case 11: {
        Status status;
        return allocate<11>(p, input, status, Activation<11>(), Deactivation());
    }
    case 12: {
        Status status;
        return allocate<12>(p, input, status, Activation<12>(), Deactivation());
    }
    case 13: {
        Status status;
        return allocate<13>(p, input, status, Activation<13>(), Deactivation());
    }
    case 14: {
        Status status;
        return allocate<14>(p, input, status, Activation<14>(), Deactivation());
    }
    case 15: {
        Status status;
        return allocate<15>(p, input, status, Activation<15>(), Deactivation());
    }
    case 16: {
        Status status;
        return allocate<16>(p, input, status, Activation<16>(), Deactivation());
    }
    default:
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
