#pragma force_active on
extern "C" {
unsigned int fn_41_36AC8(void*);
char* fn_41_36B00(char*, int);
char* fn_41_36AD8(char*, int);
}
namespace {
struct State { bool first; bool second; };
template <unsigned Kind> struct Counter {
    unsigned int (*predicate)(void*);
    int matched;
    int rejected;
    explicit Counter(unsigned int (*test)(void*)) : predicate(test), matched(0), rejected(0) {}
    void operator()(void* element) {
        if (predicate(element) == 1) {
            ++matched;
        } else {
            ++rejected;
        }
    }
};
template <unsigned Kind> inline Counter<Kind> countEnemies(char* object) {
    Counter<Kind> counter(fn_41_36AC8);
    for (int i = 0; i < 2; ++i) {
        counter(Kind == 0 ? fn_41_36B00(object + 0x70, i) + 0x94 : fn_41_36AD8(object + 0xC, i));
    }
    return counter;
}
}
extern "C" unsigned int fn_41_36438(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State state = {false, false}; return countEnemies<0>(object).matched; }
    case 1: { State state = {false, false}; return countEnemies<1>(object).matched; }
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
