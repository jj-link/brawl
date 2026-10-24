#pragma force_active on
namespace {
struct SnakeArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_122_11584(void*, int articleId) {
    switch (articleId) {
    case 0: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 1: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 2: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 3: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 4: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 5: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 6: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 7: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 8: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 9: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 10: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 11: { SnakeArticleStatus status = {{false, false}}; return 1; }
    case 12: { SnakeArticleStatus status = {{false, false}}; return 2; }
    case 13: { SnakeArticleStatus status = {{false, false}}; return 0; }
    case 14: { SnakeArticleStatus status = {{false, false}}; return 0; }
    case 15: { SnakeArticleStatus status = {{false, false}}; return 0; }
    case 16: { SnakeArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
