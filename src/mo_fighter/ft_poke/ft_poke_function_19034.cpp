#pragma force_active on
extern "C" {
unsigned int fn_116_BCD8(void*);
void* fn_116_1964C(void*, int);
}

namespace {
struct PokeArticleCountState {
    bool first;
    bool second;
};
struct PokeArticleCounter {
    unsigned int (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;

    explicit PokeArticleCounter(unsigned int (*test)(void*))
        : predicate(test), accepted(0), rejected(0) {}
    void operator()(void* article) {
        if (predicate(article) == 1) {
            ++accepted;
        } else {
            ++rejected;
        }
    }
};
inline PokeArticleCounter countArticles(char* object) {
    PokeArticleCounter counter(fn_116_BCD8);
    for (int i = 0; i < 10; ++i) {
        counter(static_cast<char*>(fn_116_1964C(object + 0xC, i)) + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_116_19034(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: {
        PokeArticleCountState state = {false, false};
        return countArticles(object).accepted;
    }
    case 1: { PokeArticleCountState state = {false, false}; return 0; }
    case 2: { PokeArticleCountState state = {false, false}; return 0; }
    case 3: { PokeArticleCountState state = {false, false}; return 0; }
    case 4: { PokeArticleCountState state = {false, false}; return 0; }
    case 5: { PokeArticleCountState state = {false, false}; return 0; }
    case 6: { PokeArticleCountState state = {false, false}; return 0; }
    case 7: { PokeArticleCountState state = {false, false}; return 0; }
    case 8: { PokeArticleCountState state = {false, false}; return 0; }
    case 9: { PokeArticleCountState state = {false, false}; return 0; }
    case 10: { PokeArticleCountState state = {false, false}; return 0; }
    case 11: { PokeArticleCountState state = {false, false}; return 0; }
    case 12: { PokeArticleCountState state = {false, false}; return 0; }
    case 13: { PokeArticleCountState state = {false, false}; return 0; }
    case 14: { PokeArticleCountState state = {false, false}; return 0; }
    case 15: { PokeArticleCountState state = {false, false}; return 0; }
    case 16: { PokeArticleCountState state = {false, false}; return 0; }
    default: break;
    }
    return 0;
}
