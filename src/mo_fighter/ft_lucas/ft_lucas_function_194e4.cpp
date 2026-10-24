#pragma force_active on
extern "C" {
bool fn_114_E768(void*);
char* fn_114_19B2C(void*, int);
}

namespace {
struct LucasArticleCountState {
    bool first;
    bool second;
};
struct LucasArticleCounter {
    bool (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;

    explicit LucasArticleCounter(bool (*test)(void*))
        : predicate(test), accepted(0), rejected(0) {}
    void operator()(void* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
inline LucasArticleCounter countArticles(char* object) {
    LucasArticleCounter counter(fn_114_E768);
    for (int i = 0; i < 6; ++i) {
        char* weapon = fn_114_19B2C(object + 0xC, i);
        counter(weapon + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_114_194E4(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { LucasArticleCountState state = {false, false}; return countArticles(object).accepted; }
    case 1: { LucasArticleCountState state = {false, false}; return 0; }
    case 2: { LucasArticleCountState state = {false, false}; return 0; }
    case 3: { LucasArticleCountState state = {false, false}; return 0; }
    case 4: { LucasArticleCountState state = {false, false}; return 0; }
    case 5: { LucasArticleCountState state = {false, false}; return 0; }
    case 6: { LucasArticleCountState state = {false, false}; return 0; }
    case 7: { LucasArticleCountState state = {false, false}; return 0; }
    case 8: { LucasArticleCountState state = {false, false}; return 0; }
    case 9: { LucasArticleCountState state = {false, false}; return 0; }
    case 10: { LucasArticleCountState state = {false, false}; return 0; }
    case 11: { LucasArticleCountState state = {false, false}; return 0; }
    case 12: { LucasArticleCountState state = {false, false}; return 0; }
    case 13: { LucasArticleCountState state = {false, false}; return 0; }
    case 14: { LucasArticleCountState state = {false, false}; return 0; }
    case 15: { LucasArticleCountState state = {false, false}; return 0; }
    case 16: { LucasArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
