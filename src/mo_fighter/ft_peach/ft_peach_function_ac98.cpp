#pragma force_active on
extern "C" {
unsigned int fn_103_B3A8(void*);
char* fn_103_B3B8(void*, int);
char* fn_103_B3D0(void*, int);
}
namespace {
struct State { bool first; bool second; };
template <unsigned Kind> struct Counter {
    unsigned int (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;
    explicit Counter(unsigned int (*test)(void*)) : predicate(test), accepted(0), rejected(0) {}
    inline void operator()(void* article) {
        if (predicate(article) == 1) ++accepted;
        else ++rejected;
    }
};
template <unsigned Kind> inline Counter<Kind> countArticles(char* object) {
    Counter<Kind> counter(fn_103_B3A8);
    for (int i = 0; i < 1; ++i) {
        char* weapon = Kind == 0 ? fn_103_B3D0(object + 0xDD10, i) : fn_103_B3B8(object + 0xC, i);
        counter(weapon + 0x88);
    }
    return counter;
}
}
extern "C" unsigned int fn_103_AC98(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { State state = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { State state = {false, false}; return 0; }
    case 3: { State state = {false, false}; return 0; }
    case 4: { State state = {false, false}; return 0; }
    case 5: { State state = {false, false}; return 0; }
    case 6: { State state = {false, false}; return 0; }
    case 7: { State state = {false, false}; return 0; }
    case 8: { State state = {false, false}; return 0; }
    case 9: { State state = {false, false}; return 0; }
    case 10: { State state = {false, false}; return 0; }
    case 11: { State state = {false, false}; return 0; }
    case 12: { State state = {false, false}; return 0; }
    case 13: { State state = {false, false}; return 0; }
    case 14: { State state = {false, false}; return 0; }
    case 15: { State state = {false, false}; return 0; }
    case 16: { State state = {false, false}; return 0; }
    default: return 0;
    }
}