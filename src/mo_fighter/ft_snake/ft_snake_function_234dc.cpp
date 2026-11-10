#pragma force_active on
extern "C" {
unsigned int fn_122_11E3C(void*);
char* fn_122_23AC8(void*, int);
}
namespace {
struct State { bool first; bool second; };
struct Counter {
    unsigned int (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;
    explicit Counter(unsigned int (*test)(void*)) : predicate(test), accepted(0), rejected(0) {}
    void operator()(void* article) {
        if (predicate(article) == 1) ++accepted;
        else ++rejected;
    }
};
inline Counter countArticles(char* object) {
    Counter counter(fn_122_11E3C);
    for (int i = 0; i < 2; ++i) {
        counter(fn_122_23AC8(object + 0xc, i) + 0x88);
    }
    return counter;
}
}
extern "C" unsigned int fn_122_234DC(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return countArticles(object).accepted; }
    case 1: { State state = {false, false}; return 0; }
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