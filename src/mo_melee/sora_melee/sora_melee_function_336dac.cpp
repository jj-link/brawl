#pragma force_active on

extern "C" {
unsigned int fn_27_318C34(void*);
}

namespace {
struct SoraCounter {
    unsigned int (*predicate)(void*);
    int matched;
    int rejected;

    explicit SoraCounter(unsigned int (*test)(void*))
        : predicate(test), matched(0), rejected(0) {}

    void operator()(void* element) {
        if (predicate(element) == 1) {
            ++matched;
        } else {
            ++rejected;
        }
    }
};
}

extern "C" int fn_27_336DAC(char* object, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: {
        SoraCounter counter(fn_27_318C34);
        SoraCounter* pc = &counter;
        for (int i = 0; i < 6; ++i) {
            char* e;
            if (i == 5) e = object + 0x9CA8;
            else if (i == 4) e = object + 0x7D5C;
            else if (i == 3) e = object + 0x5E10;
            else if (i == 2) e = object + 0x3EC4;
            else if (i == 1) e = object + 0x1F78;
            else if (i == 0) e = object + 0x2C;
            else e = 0;
            (*pc)(e + 0x88);
        }
        return pc->matched;
    }
    case 1: return 0;
    case 2: return 0;
    case 3: return 0;
    case 4: return 0;
    case 5: return 0;
    case 6: return 0;
    case 7: return 0;
    case 8: return 0;
    case 9: return 0;
    case 10: return 0;
    case 11: return 0;
    case 12: return 0;
    case 13: return 0;
    case 14: return 0;
    case 15: return 0;
    case 16: return 0;
    default: return 0;
    }
}
