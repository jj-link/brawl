#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

class LucasArticle {
public:
    virtual int isNull() const;
};

class LucasArticleModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual LucasArticle* generate(int, int, bool);
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void remove(LucasArticle*);
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual int count(int);
};

struct LucasModules {
    char pad0[0x64];
    soWorkManageModule* work;
    char pad1[0x1C];
    LucasArticleModule* articles;
};

struct LucasObject {
    char pad[0xD8];
    LucasModules* modules;
};

extern "C" void fn_114_19F40(void*, LucasObject* object) {
    LucasModules* modules = object->modules;
    LucasArticleModule* articles = modules->articles;
    soWorkManageModule* work = modules->work;
    int value = work->getInt(0x20000000);

    if (articles->count(0) < 6 && value % 2 == 0) {
        LucasArticle* article = articles->generate(0, 0, false);
        if (article->isNull() == 0) {
            articles->remove(article);
        }
    }

    work->setInt(value + 1, 0x20000000);
}
