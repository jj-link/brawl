#pragma force_active on
extern "C" {
unsigned int fn_41_36AC8(void*);
void* fn_41_63DC4(void*, int);
}

namespace {
struct SoraEnemyFlags {
    bool first;
    bool second;
};

struct SoraEnemyCounter {
    unsigned int (*predicate)(void*);
    int matched;
    int rejected;

    explicit SoraEnemyCounter(unsigned int (*test)(void*)) : predicate(test), matched(0), rejected(0) {}
    void operator()(void* element) {
        if (predicate(element) == 1) {
            matched++;
        } else {
            rejected++;
        }
    }
};

SoraEnemyCounter countEnemies(char* object) {
    SoraEnemyCounter counter(fn_41_36AC8);
    for (int i = 0; i < 0x14; i++) {
        counter(fn_41_63DC4(object + 0xC, i));
    }
    return counter;
}
}

extern "C" int fn_41_637F0(char* object, int operation, unsigned int kind) {
    switch (kind) {
    case 0: {
        SoraEnemyFlags flags = {false, false};
        return countEnemies(object).matched;
    }
    case 1: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 2: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 3: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 4: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 5: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 6: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 7: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 8: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 9: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 10: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 11: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 12: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 13: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 14: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 15: { SoraEnemyFlags flags = {false, false}; return 0; }
    case 16: { SoraEnemyFlags flags = {false, false}; return 0; }
    default: return 0;
    }
}
