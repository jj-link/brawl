#pragma force_active on
namespace {
struct DiddyArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_115_B4AC(void*, int articleId) {
    switch (articleId) {
    case 0: { DiddyArticleStatus status = {{false, false}}; return 2; }
    case 1: { DiddyArticleStatus status = {{false, false}}; return 2; }
    case 2: { DiddyArticleStatus status = {{false, false}}; return 10; }
    case 3: { DiddyArticleStatus status = {{false, false}}; return 1; }
    case 4: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 5: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 6: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 7: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 8: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 9: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 10: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 11: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 12: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 13: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 14: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 15: { DiddyArticleStatus status = {{false, false}}; return 0; }
    case 16: { DiddyArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
