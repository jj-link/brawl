#pragma force_active on
namespace {
struct DonkeyArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_92_A780(void*, unsigned int articleId) {
    switch (articleId) {
    case 0: { DonkeyArticleStatus status = {{false, false}}; return 1; }
    case 1: { DonkeyArticleStatus status = {{false, false}}; return 4; }
    case 2: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 3: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 4: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 5: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 6: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 7: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 8: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 9: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 10: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 11: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 12: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 13: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 14: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 15: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    case 16: { DonkeyArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}