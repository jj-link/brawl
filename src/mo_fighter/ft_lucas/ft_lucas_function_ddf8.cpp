#pragma force_active on
extern "C" {
unsigned int fn_114_E768(void*);
void* fn_114_E778(void*, int);
void* fn_114_E790(void*, int);
void* fn_114_E8C4(void*, int);
void* fn_114_E8F0(void*, int);
void* fn_114_E918(void*, int);
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
    Counter() : State(fn_114_E768) {}
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
    for (int i = 0; i < (Kind == 0 ? 1 : Kind == 1 ? 2 : Kind == 2 ? 2 : Kind == 3 ? 0x10 : 1); ++i) {
        char* article;
        if (Kind == 0) article = static_cast<char*>(fn_114_E918(object + 0x3E6F8, i));
        else if (Kind == 1) article = static_cast<char*>(fn_114_E8F0(object + 0x39ED4, i));
        else if (Kind == 2) article = static_cast<char*>(fn_114_E8C4(object + 0x1E2A0, i));
        else if (Kind == 3) article = static_cast<char*>(fn_114_E790(object + 0x211C, i));
        else article = static_cast<char*>(fn_114_E778(object + 0xC, i));
        counter(article + 0x88);
    }
    return counter;
}
}
extern "C" unsigned int fn_114_DDF8(char* object, void* unused, unsigned int kind) {
    switch (kind) {
    case 0: { Flags f = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { Flags f = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { Flags f = {false, false}; return countArticles<2>(object).accepted; }
    case 3: { Flags f = {false, false}; return countArticles<3>(object).accepted; }
    case 4: { Flags f = {false, false}; return countArticles<4>(object).accepted; }
    case 5: { Flags f = {false, false}; return 0; }
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