#pragma force_active on
extern "C" {
unsigned int fn_112_BE28(void*);
void* fn_112_16B24(void*, int);
}

namespace {
struct PitArticleCountState {
    bool first;
    bool second;
};
struct PitArticleCounter {
    unsigned int (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;

    explicit PitArticleCounter(unsigned int (*test)(void*))
        : predicate(test), accepted(0), rejected(0) {}
    void operator()(void* article) {
        if (predicate(article) == 1) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
inline PitArticleCounter countArticles(char* object) {
    PitArticleCounter counter(fn_112_BE28);
    for (int i = 0; i < 10; ++i) {
        counter(static_cast<char*>(fn_112_16B24(object + 0xC, i)) + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_112_164DC(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: {
        PitArticleCountState state = {false, false};
        return countArticles(object).accepted;
    }
    case 1: { PitArticleCountState state = {false, false}; return 0; }
    case 2: { PitArticleCountState state = {false, false}; return 0; }
    case 3: { PitArticleCountState state = {false, false}; return 0; }
    case 4: { PitArticleCountState state = {false, false}; return 0; }
    case 5: { PitArticleCountState state = {false, false}; return 0; }
    case 6: { PitArticleCountState state = {false, false}; return 0; }
    case 7: { PitArticleCountState state = {false, false}; return 0; }
    case 8: { PitArticleCountState state = {false, false}; return 0; }
    case 9: { PitArticleCountState state = {false, false}; return 0; }
    case 10: { PitArticleCountState state = {false, false}; return 0; }
    case 11: { PitArticleCountState state = {false, false}; return 0; }
    case 12: { PitArticleCountState state = {false, false}; return 0; }
    case 13: { PitArticleCountState state = {false, false}; return 0; }
    case 14: { PitArticleCountState state = {false, false}; return 0; }
    case 15: { PitArticleCountState state = {false, false}; return 0; }
    case 16: { PitArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
