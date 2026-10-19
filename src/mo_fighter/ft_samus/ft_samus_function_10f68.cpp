#pragma force_active on
class Article {
public:
    virtual int isNull();
};

class ArticleManager {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual Article* get(int, bool, bool);
    virtual void slot18();
    virtual void remove(int, int, int);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void act(Article*);
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual int exists(int);
};

class StatusModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual int getStatusKind();
};

class WorkModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual int isFlag(int);
    virtual void slot50();
    virtual void offFlag(int);
};

struct Modules {
    char pad00[0x64];
    WorkModule* work;
    char pad68[8];
    StatusModule* status;
    char pad74[0x10];
    ArticleManager* articles;
};

struct Accesser {
    char pad00[0xD8];
    Modules* modules;
};

extern "C" void fn_94_10F68(void*, Accesser* accesser) {
    if (accesser->modules->status->getStatusKind() == 0x113)
        return;

    int status = accesser->modules->status->getStatusKind();
    if (accesser->modules->work->isFlag(0x22000010)) {
        Article* article;
        int kind;
        ArticleManager& manager = *accesser->modules->articles;

        switch (status) {
        case 0x124:
        case 0x125:
            kind = 6;
            break;
        default:
            kind = 2;
            break;
        }

        if (manager.exists(kind)) {
            article = manager.get(kind, false, false);
            if (!article->isNull()) {
                manager.act(article);
                manager.remove(kind, 0, 1);
            }
        }

        accesser->modules->work->offFlag(0x22000010);
    }
}
