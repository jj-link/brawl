#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
bool fn_111_9874(soArticle*);
char* fn_111_9884(void*, int);
}

namespace {
struct MkState {
    bool first;
    bool second;
};
struct MkCounter {
    bool (*predicate)(soArticle*);
    unsigned int accepted;
    unsigned int rejected;

    MkCounter() : predicate(fn_111_9874), accepted(0), rejected(0) {}
    void operator()(char* element) {
        if (predicate(reinterpret_cast<soArticle*>(element + 0x88)) == true)
            ++accepted;
        else
            ++rejected;
    }
};
inline MkCounter countArticles(char* object) {
    MkCounter counter;
    for (int i = 0; i < 1; ++i)
        counter(fn_111_9884(object + 0xC, i));
    return counter;
}
}

extern "C" unsigned int fn_111_922C(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { MkState state = {false, false}; return countArticles(object).accepted; }
    case 1: { MkState state = {false, false}; return 0; }
    case 2: { MkState state = {false, false}; return 0; }
    case 3: { MkState state = {false, false}; return 0; }
    case 4: { MkState state = {false, false}; return 0; }
    case 5: { MkState state = {false, false}; return 0; }
    case 6: { MkState state = {false, false}; return 0; }
    case 7: { MkState state = {false, false}; return 0; }
    case 8: { MkState state = {false, false}; return 0; }
    case 9: { MkState state = {false, false}; return 0; }
    case 10: { MkState state = {false, false}; return 0; }
    case 11: { MkState state = {false, false}; return 0; }
    case 12: { MkState state = {false, false}; return 0; }
    case 13: { MkState state = {false, false}; return 0; }
    case 14: { MkState state = {false, false}; return 0; }
    case 15: { MkState state = {false, false}; return 0; }
    case 16: { MkState state = {false, false}; return 0; }
    default: return 0;
    }
}
