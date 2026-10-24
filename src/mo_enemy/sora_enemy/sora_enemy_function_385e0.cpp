#pragma force_active on
extern "C" {
unsigned int fn_41_36AC8(void*);
void* fn_41_38BB4(void*, int);
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
inline SoraEnemyCounter countEnemies(char* object) {
    SoraEnemyCounter counter(fn_41_36AC8);
    for (int i = 0; i < 5; ++i) {
        counter(fn_41_38BB4(object + 0xC, i));
    }
    return counter;
}
}

extern "C" int fn_41_385E0(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { SoraEnemyState state = {false, false}; return countEnemies(object).matched; }
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
