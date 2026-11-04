#pragma force_active on

extern "C" {
unsigned int fn_41_36AC8(void*);
int fn_41_43B8C(void* self, void* arg);
void* fn_41_43BEC(void*, int);
void* fn_41_43C04(void*, int);
void* fn_41_43C3C(void*, int);
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
};
}

extern "C" int fn_41_434A4(char* object, int operation, unsigned int kind) {
    switch (kind) {
    case 0: {
        SoraEnemyState state = {false, false};
        SoraEnemyCounter counter;
        counter.predicate = fn_41_36AC8;
        counter.matched = 0;
        counter.rejected = 0;
        int i;
        for (i = 0; i < 1; i++) {
            if (fn_41_43B8C(&counter, fn_41_43C3C(object + 0xD4, i)) == 0) {
                break;
            }
        }
        return counter.matched;
    }
    case 1: {
        SoraEnemyState state = {false, false};
        SoraEnemyCounter counter;
        counter.predicate = fn_41_36AC8;
        counter.matched = 0;
        counter.rejected = 0;
        int i;
        for (i = 0; i < 3; i++) {
            if (fn_41_43B8C(&counter, fn_41_43C04(object + 0x40, i)) == 0) {
                break;
            }
        }
        return counter.matched;
    }
    case 2: {
        SoraEnemyState state = {false, false};
        SoraEnemyCounter counter;
        counter.predicate = fn_41_36AC8;
        counter.matched = 0;
        counter.rejected = 0;
        int i;
        for (i = 0; i < 1; i++) {
            if (fn_41_43B8C(&counter, fn_41_43BEC(object + 0xC, i)) == 0) {
                break;
            }
        }
        return counter.matched;
    }
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
    default:
        return 0;
    }
}
