#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
extern const char lbl_116_data_6C54[];
extern const char lbl_116_data_6960[];
extern const char lbl_116_data_6AD8[];
extern const char lbl_116_data_25F4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_116_1076C(void*, unsigned int);
}

class Object_vptr_0 {
public:
    virtual void fn_116_7384();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned int slot17(unsigned int);
};

namespace {
struct ArticleStatus {
    bool flags[2];
};
}

extern "C" bool fn_116_B938(void*, void* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: {
        ArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_116_data_6C54, lbl_116_data_25F4, 1);
        return true;
    }
    case 1: {
        ArticleStatus status = {{false, false}};
        void* rock = __dynamic_cast(article, 0, lbl_116_data_6960, lbl_116_data_25F4, 1);
        void* module = *(void**)((char*)accesser + 0xD8);
        Object_vptr_0* object = (Object_vptr_0*)(*(void**)((char*)module + 0x64));
        fn_116_1076C(rock, object->slot17(0x22000013));
        return false;
    }
    case 2: {
        ArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_116_data_6AD8, lbl_116_data_25F4, 1);
        return true;
    }
    case 3: { ArticleStatus status = {{false, false}}; return true; }
    case 4: { ArticleStatus status = {{false, false}}; return true; }
    case 5: { ArticleStatus status = {{false, false}}; return true; }
    case 6: { ArticleStatus status = {{false, false}}; return true; }
    case 7: { ArticleStatus status = {{false, false}}; return true; }
    case 8: { ArticleStatus status = {{false, false}}; return true; }
    case 9: { ArticleStatus status = {{false, false}}; return true; }
    case 10: { ArticleStatus status = {{false, false}}; return true; }
    case 11: { ArticleStatus status = {{false, false}}; return true; }
    case 12: { ArticleStatus status = {{false, false}}; return true; }
    case 13: { ArticleStatus status = {{false, false}}; return true; }
    case 14: { ArticleStatus status = {{false, false}}; return true; }
    case 15: { ArticleStatus status = {{false, false}}; return true; }
    case 16: { ArticleStatus status = {{false, false}}; return true; }
    default:
        return false;
    }
}
