#pragma force_active on
extern "C" {
bool fn_91_BDBC(void*);
void* fn_91_141A0(void*, int);
}

namespace {
struct MarioArticleCountState {
    bool first;
    bool second;
};
struct MarioArticleCounter {
    bool (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;

    explicit MarioArticleCounter(bool (*test)(void*))
        : predicate(test), accepted(0), rejected(0) {}
    void operator()(void* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
inline MarioArticleCounter countArticles(char* object) {
    MarioArticleCounter counter(fn_91_BDBC);
    for (int i = 0; i < 12; ++i) {
        counter(static_cast<char*>(fn_91_141A0(object + 0xC, i)) + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_91_13B58(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { MarioArticleCountState state = {false, false}; return countArticles(object).accepted; }
    case 1: { MarioArticleCountState state = {false, false}; return 0; }
    case 2: { MarioArticleCountState state = {false, false}; return 0; }
    case 3: { MarioArticleCountState state = {false, false}; return 0; }
    case 4: { MarioArticleCountState state = {false, false}; return 0; }
    case 5: { MarioArticleCountState state = {false, false}; return 0; }
    case 6: { MarioArticleCountState state = {false, false}; return 0; }
    case 7: { MarioArticleCountState state = {false, false}; return 0; }
    case 8: { MarioArticleCountState state = {false, false}; return 0; }
    case 9: { MarioArticleCountState state = {false, false}; return 0; }
    case 10: { MarioArticleCountState state = {false, false}; return 0; }
    case 11: { MarioArticleCountState state = {false, false}; return 0; }
    case 12: { MarioArticleCountState state = {false, false}; return 0; }
    case 13: { MarioArticleCountState state = {false, false}; return 0; }
    case 14: { MarioArticleCountState state = {false, false}; return 0; }
    case 15: { MarioArticleCountState state = {false, false}; return 0; }
    case 16: { MarioArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
