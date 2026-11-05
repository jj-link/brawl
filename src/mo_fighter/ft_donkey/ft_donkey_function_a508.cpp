#pragma force_active on
extern "C" {
unsigned int fn_92_AC10(void*);
char* fn_92_AC20(void*, int);
char* fn_92_AC68(void*, int);
}
namespace {
struct State { bool first; bool second; };
template <unsigned Kind> struct Counter {
    unsigned int (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;
    explicit Counter(unsigned int (*test)(void*)) : predicate(test), accepted(0), rejected(0) {}
    void operator()(void* article) {
        if (predicate(article) == 1) ++accepted;
        else ++rejected;
    }
};
template <unsigned Kind> inline Counter<Kind> countArticles(char* object) {
    Counter<Kind> counter(fn_92_AC10);
    for (int i = 0; i < (Kind == 0 ? 1 : 4); ++i) {
        char* weapon = Kind == 0 ? fn_92_AC68(object + 0x7f60, i) : fn_92_AC20(object + 0xc, i);
        counter(weapon + 0x88);
    }
    return counter;
}
}
extern "C" unsigned int fn_92_A508(char* object, unsigned int operation, unsigned int kind) {
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