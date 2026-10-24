#pragma force_active on
namespace {
struct FoxArticleStatus {
    unsigned char flags[2];
};
}

extern "C" int fn_97_C430(void* p, int articleId) {
    (void)p;
    switch (articleId) {
    case 0: { FoxArticleStatus s = {{0, 0}}; return 1; }
    case 1: { FoxArticleStatus s = {{0, 0}}; return 5; }
    case 2: { FoxArticleStatus s = {{0, 0}}; return 2; }
    case 3: { FoxArticleStatus s = {{0, 0}}; return 1; }
    case 4: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 5: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 6: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 7: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 8: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 9: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 10: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 11: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 12: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 13: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 14: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 15: { FoxArticleStatus s = {{0, 0}}; return 0; }
    case 16: { FoxArticleStatus s = {{0, 0}}; return 0; }
    default: return 0;
    }
}
