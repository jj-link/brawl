#pragma force_active on

extern "C" {
extern const char lbl_100_data_5F88[];
extern const char lbl_100_data_5E18[];
extern const char lbl_100_data_1A68[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

namespace {
struct CaptainArticleState {
    bool first;
    bool second;
};

class Article {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual unsigned int kind();
};
}

extern "C" int fn_100_A744(void*, void*, void* self)
{
    Article* article = reinterpret_cast<Article*>(self);
    switch (article->kind()) {
    case 0: {
        CaptainArticleState state = {false, false};
        __dynamic_cast(self, 0, lbl_100_data_5F88, lbl_100_data_1A68, 1);
        return 1;
    }
    case 1: {
        CaptainArticleState state = {false, false};
        __dynamic_cast(self, 0, lbl_100_data_5E18, lbl_100_data_1A68, 1);
        return 1;
    }
    case 2: { CaptainArticleState state = {false, false}; return 1; }
    case 3: { CaptainArticleState state = {false, false}; return 1; }
    case 4: { CaptainArticleState state = {false, false}; return 1; }
    case 5: { CaptainArticleState state = {false, false}; return 1; }
    case 6: { CaptainArticleState state = {false, false}; return 1; }
    case 7: { CaptainArticleState state = {false, false}; return 1; }
    case 8: { CaptainArticleState state = {false, false}; return 1; }
    case 9: { CaptainArticleState state = {false, false}; return 1; }
    case 10: { CaptainArticleState state = {false, false}; return 1; }
    case 11: { CaptainArticleState state = {false, false}; return 1; }
    case 12: { CaptainArticleState state = {false, false}; return 1; }
    case 13: { CaptainArticleState state = {false, false}; return 1; }
    case 14: { CaptainArticleState state = {false, false}; return 1; }
    case 15: { CaptainArticleState state = {false, false}; return 1; }
    case 16: { CaptainArticleState state = {false, false}; return 1; }
    default: return 0;
    }
}
