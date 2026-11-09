#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
void* fn_120_B018(void*, int);
void* fn_120_AFF0(char*, int);
void* fn_120_AFD8(void*, int);
void* fn_120_AFC0(void*, int);
}

namespace {
struct RobotArticleState {
    bool first;
    bool second;
};

template<unsigned Kind>
inline bool allArticlesActive(char* object, int count) {
    for (int i = 0; i < count; ++i) {
        void* article;
        if (Kind == 0) article = fn_120_B018(object + 0x7E80, i);
        else if (Kind == 1) article = fn_120_AFF0(object + 0x3E2C, i);
        else if (Kind == 2) article = fn_120_AFD8(object + 0x2224, i);
        else article = fn_120_AFC0(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(article) + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_120_A468(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { RobotArticleState state = {false, false}; return !allArticlesActive<0>(object, 1); }
    case 1: { RobotArticleState state = {false, false}; return !allArticlesActive<1>(object, 2); }
    case 2: { RobotArticleState state = {false, false}; return !allArticlesActive<2>(object, 1); }
    case 3: { RobotArticleState state = {false, false}; return !allArticlesActive<3>(object, 1); }
    case 4: { RobotArticleState state = {false, false}; return false; }
    case 5: { RobotArticleState state = {false, false}; return false; }
    case 6: { RobotArticleState state = {false, false}; return false; }
    case 7: { RobotArticleState state = {false, false}; return false; }
    case 8: { RobotArticleState state = {false, false}; return false; }
    case 9: { RobotArticleState state = {false, false}; return false; }
    case 10: { RobotArticleState state = {false, false}; return false; }
    case 11: { RobotArticleState state = {false, false}; return false; }
    case 12: { RobotArticleState state = {false, false}; return false; }
    case 13: { RobotArticleState state = {false, false}; return false; }
    case 14: { RobotArticleState state = {false, false}; return false; }
    case 15: { RobotArticleState state = {false, false}; return false; }
    case 16: { RobotArticleState state = {false, false}; return false; }
    default: return false;
    }
}
