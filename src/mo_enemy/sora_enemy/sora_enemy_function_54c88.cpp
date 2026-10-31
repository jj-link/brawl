#pragma force_active on
#pragma section data_type ".data" ".bss"
namespace {
struct ArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_41_54C88(void*, unsigned int kind) {
    switch (kind) {
    case 0: { ArticleStatus status = {{false, false}}; return 1; }
    case 1: { ArticleStatus status = {{false, false}}; return 0; }
    case 2: { ArticleStatus status = {{false, false}}; return 0; }
    case 3: { ArticleStatus status = {{false, false}}; return 0; }
    case 4: { ArticleStatus status = {{false, false}}; return 0; }
    case 5: { ArticleStatus status = {{false, false}}; return 0; }
    case 6: { ArticleStatus status = {{false, false}}; return 0; }
    case 7: { ArticleStatus status = {{false, false}}; return 0; }
    case 8: { ArticleStatus status = {{false, false}}; return 0; }
    case 9: { ArticleStatus status = {{false, false}}; return 0; }
    case 10: { ArticleStatus status = {{false, false}}; return 0; }
    case 11: { ArticleStatus status = {{false, false}}; return 0; }
    case 12: { ArticleStatus status = {{false, false}}; return 0; }
    case 13: { ArticleStatus status = {{false, false}}; return 0; }
    case 14: { ArticleStatus status = {{false, false}}; return 0; }
    case 15: { ArticleStatus status = {{false, false}}; return 0; }
    case 16: { ArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
