#pragma force_active on
extern "C" {
unsigned int fn_41_36AC8(void*);
char* fn_41_5A630(char*, int);
}

namespace {
struct SoraEnemyState {
    bool first;
    bool second;
};
struct SoraEnemyCounter {
    unsigned int (*predicate)(void*);
    int matched;
    int rejected;
    explicit SoraEnemyCounter(unsigned int (*test)(void*))
        : predicate(test), matched(0), rejected(0) {}
    void operator()(void* element) {
        if (predicate(element) == 1) {
            ++matched;
        } else {
            ++rejected;
        }
    }
};
inline SoraEnemyCounter countSoraEnemies(char* object) {
    SoraEnemyCounter counter(fn_41_36AC8);
    for (int i = 0; i < 2; ++i) {
        counter(fn_41_5A630(object + 0xC, i) + 0x94);
    }
    return counter;
}
}

extern "C" unsigned int fn_41_5A054(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { SoraEnemyState state = {false, false}; return countSoraEnemies(object).matched; }
    case 1: { SoraEnemyState state = {false, false}; return 0; }
    case 2: { SoraEnemyState state = {false, false}; return 0; }
    case 3: { SoraEnemyState state = {false, false}; return 0; }
    case 4: { SoraEnemyState state = {false, false}; return 0; }
    case 5: { SoraEnemyState state = {false, false}; return 0; }
    case 6: { SoraEnemyState state = {false, false}; return 0; }
    case 7: { SoraEnemyState state = {false, false}; return 0; }
    case 8: { SoraEnemyState state = {false, false}; return 0; }
    case 9: { SoraEnemyState state = {false, false}; return 0; }
    case 10: { SoraEnemyState state = {false, false}; return 0; }
    case 11: { SoraEnemyState state = {false, false}; return 0; }
    case 12: { SoraEnemyState state = {false, false}; return 0; }
    case 13: { SoraEnemyState state = {false, false}; return 0; }
    case 14: { SoraEnemyState state = {false, false}; return 0; }
    case 15: { SoraEnemyState state = {false, false}; return 0; }
    case 16: { SoraEnemyState state = {false, false}; return 0; }
    default: return 0;
    }
}
