#pragma force_active on

extern "C" {
unsigned int fn_101_EEF0(void*);
void* fn_101_F0B8(void*, int);
void* fn_101_F090(void*, int);
void* fn_101_F064(void*, int);
void* fn_101_EF30(void*, int);
void* fn_101_EF18(void*, int);
void* fn_101_EF00(void*, int);
}

struct State {
    unsigned int (*predicate)(void*);
    int accepted;
    int rejected;
    explicit State(unsigned int (*p)(void*)) : predicate(p), accepted(0), rejected(0) {}
};

namespace {
struct Flags { bool first; bool second; };

template<unsigned Kind>
struct Counter : State {
    Counter() : State(fn_101_EEF0) {}
    inline void operator()(void* article) {
        if (predicate(article) == 1) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};

template<unsigned Kind>
inline Counter<Kind> countArticles(char* object) {
    Counter<Kind> counter;
    for (int i = 0; i < (Kind == 0 ? 1 : Kind == 1 ? 2 : Kind == 2 ? 2 : Kind == 3 ? 16 : Kind == 4 ? 1 : 1); ++i) {
        char* article;
        if (Kind == 0) article = static_cast<char*>(fn_101_F0B8(object + 0x408F0, i));
        else if (Kind == 1) article = static_cast<char*>(fn_101_F090(object + 0x3C0CC, i));
        else if (Kind == 2) article = static_cast<char*>(fn_101_F064(object + 0x20498, i));
        else if (Kind == 3) article = static_cast<char*>(fn_101_EF30(object + 0x4314, i));
        else if (Kind == 4) article = static_cast<char*>(fn_101_EF18(object + 0x21D0, i));
        else article = static_cast<char*>(fn_101_EF00(object + 0xC, i));
        counter(article + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_101_E4C4(char* object, void* unused, unsigned int kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return countArticles<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return countArticles<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return countArticles<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return countArticles<5>(object).accepted; }
    case 6: { Flags f = {false, false}; return 0; }
    case 7: { Flags f = {false, false}; return 0; }
    case 8: { Flags f = {false, false}; return 0; }
    case 9: { Flags f = {false, false}; return 0; }
    case 10: { Flags f = {false, false}; return 0; }
    case 11: { Flags f = {false, false}; return 0; }
    case 12: { Flags f = {false, false}; return 0; }
    case 13: { Flags f = {false, false}; return 0; }
    case 14: { Flags f = {false, false}; return 0; }
    case 15: { Flags f = {false, false}; return 0; }
    case 16: { Flags f = {false, false}; return 0; }
    default: return 0;
    }
}