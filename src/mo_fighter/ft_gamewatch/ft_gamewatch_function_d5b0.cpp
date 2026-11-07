#pragma force_active on
extern "C" {
unsigned int fn_107_E07C(void*);
void* fn_107_E11C(void*, int);
void* fn_107_E104(void*, int);
void* fn_107_E0EC(void*, int);
void* fn_107_E0D4(void*, int);
void* fn_107_E0BC(void*, int);
void* fn_107_E0A4(void*, int);
void* fn_107_E08C(void*, int);
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
    Counter() : State(fn_107_E07C) {}
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
    for (int i = 0; i < (Kind == 0 ? 5 : 1); ++i) {
        char* article;
        if (Kind == 0) article = static_cast<char*>(fn_107_E11C(object + 0xCDEC, i));
        else if (Kind == 1) article = static_cast<char*>(fn_107_E104(object + 0xAD00, i));
        else if (Kind == 2) article = static_cast<char*>(fn_107_E0EC(object + 0x8C14, i));
        else if (Kind == 3) article = static_cast<char*>(fn_107_E0D4(object + 0x6B0C, i));
        else if (Kind == 4) article = static_cast<char*>(fn_107_E0BC(object + 0x4A20, i));
        else if (Kind == 5) article = static_cast<char*>(fn_107_E0A4(object + 0x20F8, i));
        else article = static_cast<char*>(fn_107_E08C(object + 0xC, i));
        counter(article + 0x88);
    }
    return counter;
}
}
extern "C" unsigned int fn_107_D5B0(char* object, void* unused, unsigned int kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return countArticles<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return countArticles<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return countArticles<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return countArticles<5>(object).accepted; }
    case 6: { Flags f = {false, false}; return countArticles<6>(object).accepted; }
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
