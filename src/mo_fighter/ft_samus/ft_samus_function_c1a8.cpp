#pragma force_active on

extern "C" {
unsigned int fn_94_CD5C(void*);
void* fn_94_CE94(void*, int);
void* fn_94_CE5C(void*, int);
void* fn_94_CE24(void*, int);
void* fn_94_CE0C(void*, int);
void* fn_94_CDC4(void*, int);
void* fn_94_CDAC(void*, int);
void* fn_94_CD84(void*, int);
void* fn_94_CD6C(void*, int);
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
    Counter() : State(fn_94_CD5C) {}
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
    for (int i = 0; i < (Kind == 0 ? 4 : Kind == 1 ? 3 : Kind == 2 ? 3 : Kind == 3 ? 1 : Kind == 4 ? 4 : Kind == 5 ? 1 : Kind == 6 ? 2 : 1); ++i) {
        char* article;
        if (Kind == 0) article = static_cast<char*>(fn_94_CE94(object + 0x175F0, i));
        else if (Kind == 1) article = static_cast<char*>(fn_94_CE5C(object + 0x1260C, i));
        else if (Kind == 2) article = static_cast<char*>(fn_94_CE24(object + 0xDA84, i));
        else if (Kind == 3) article = static_cast<char*>(fn_94_CE0C(object + 0xC184, i));
        else if (Kind == 4) article = static_cast<char*>(fn_94_CDC4(object + 0x6240, i));
        else if (Kind == 5) article = static_cast<char*>(fn_94_CDAC(object + 0x4A00, i));
        else if (Kind == 6) article = static_cast<char*>(fn_94_CD84(object + 0x17A4, i));
        else article = static_cast<char*>(fn_94_CD6C(object + 0xC, i));
        counter(article + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_94_C1A8(char* object, void* unused, unsigned int kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return countArticles<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return countArticles<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return countArticles<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return countArticles<5>(object).accepted; }
    case 6: { Flags f = {false, false}; return countArticles<6>(object).accepted; }
    case 7: { Flags f = {false, false}; return countArticles<7>(object).accepted; }
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
