#pragma force_active on

#include <so/article/so_article.h>

extern "C" {
void* fn_113_E0C0(void*, int);
void* fn_113_E0A8(void*, int);
void* fn_113_E090(void*, int);
}

namespace {
struct ArticleState {
    bool first;
    bool second;
};
}

extern "C" bool fn_113_D63C(char* object, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: {
        ArticleState state = {false, false};
        int result;
        int i;
        for (i = 0; i < 6; ++i) {
            char* article = static_cast<char*>(fn_113_E0C0(object + 0x438C, i));
            if (!reinterpret_cast<soArticle*>(article + 0x88)->isActiveArticle()) {
                result = 0;
                goto done0;
            }
        }
        result = 1;
    done0:
        return result == 0;
    }
    case 1: {
        ArticleState state = {false, false};
        int result;
        int i;
        for (i = 0; i < 1; ++i) {
            char* article = static_cast<char*>(fn_113_E0A8(object + 0x1F58, i));
            if (!reinterpret_cast<soArticle*>(article + 0x88)->isActiveArticle()) {
                result = 0;
                goto done1;
            }
        }
        result = 1;
    done1:
        return result == 0;
    }
    case 2: {
        ArticleState state = {false, false};
        int result;
        int i;
        for (i = 0; i < 1; ++i) {
            char* article = static_cast<char*>(fn_113_E090(object + 0xC, i));
            if (!reinterpret_cast<soArticle*>(article + 0x88)->isActiveArticle()) {
                result = 0;
                goto done2;
            }
        }
        result = 1;
    done2:
        return result == 0;
    }
    case 3: { ArticleState state = {false, false}; return false; }
    case 4: { ArticleState state = {false, false}; return false; }
    case 5: { ArticleState state = {false, false}; return false; }
    case 6: { ArticleState state = {false, false}; return false; }
    case 7: { ArticleState state = {false, false}; return false; }
    case 8: { ArticleState state = {false, false}; return false; }
    case 9: { ArticleState state = {false, false}; return false; }
    case 10: { ArticleState state = {false, false}; return false; }
    case 11: { ArticleState state = {false, false}; return false; }
    case 12: { ArticleState state = {false, false}; return false; }
    case 13: { ArticleState state = {false, false}; return false; }
    case 14: { ArticleState state = {false, false}; return false; }
    case 15: { ArticleState state = {false, false}; return false; }
    case 16: { ArticleState state = {false, false}; return false; }
    default:
        return false;
    }
}
