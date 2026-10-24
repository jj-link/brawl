#pragma section data_type ".data" ".bss"

#include <so/article/so_article.h>
#pragma force_active on

extern "C" char* fn_112_16B24(void*, int);

namespace {
struct State { bool first; bool second; };
inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 10; ++i) {
        if (!reinterpret_cast<soArticle*>(fn_112_16B24(object + 0xC, i) + 0x88)->isActiveArticle()) return false;
    }
    return true;
}
}

extern "C" int fn_112_162EC(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { State s = {false, false}; return !allArticlesActive(object); }
    case 1: { State s = {false, false}; return 0; }
    case 2: { State s = {false, false}; return 0; }
    case 3: { State s = {false, false}; return 0; }
    case 4: { State s = {false, false}; return 0; }
    case 5: { State s = {false, false}; return 0; }
    case 6: { State s = {false, false}; return 0; }
    case 7: { State s = {false, false}; return 0; }
    case 8: { State s = {false, false}; return 0; }
    case 9: { State s = {false, false}; return 0; }
    case 10: { State s = {false, false}; return 0; }
    case 11: { State s = {false, false}; return 0; }
    case 12: { State s = {false, false}; return 0; }
    case 13: { State s = {false, false}; return 0; }
    case 14: { State s = {false, false}; return 0; }
    case 15: { State s = {false, false}; return 0; }
    case 16: { State s = {false, false}; return 0; }
    default: return 0;
    }
}
