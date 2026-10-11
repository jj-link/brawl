// The mediator has generator and operator interfaces, each with a destructor
// and article-object getter. Its callback follows both interface tables.
class PikachuArticleGenerator {
public:
    virtual ~PikachuArticleGenerator();
    virtual void* getArticleObject();
};
class PikachuArticleOperator {
public:
    virtual ~PikachuArticleOperator();
    virtual void* getArticleObject();
};
class PikachuArticleMediatorInterface : public PikachuArticleGenerator, public PikachuArticleOperator {
public:
    virtual ~PikachuArticleMediatorInterface();
    virtual void* getArticleObject();
    virtual void callback();
};

struct PikachuArticleMediator;
struct PikachuArticleMediatorVtable {
    void* type;
    unsigned int reserved;
    void* destructor;
    void* generate;
    void* operatorType;
    int operatorAdjustment;
    void* operatorDestructor;
    void* operatorGenerate;
    void (*callback)(PikachuArticleMediator*);
};
struct PikachuArticleMediator {
    PikachuArticleMediatorVtable* vtable;
    void* operatorVtable;
};

extern "C" {
extern signed char lbl_98_bss_36C;
extern PikachuArticleMediator lbl_98_bss_370;
extern char lbl_98_bss_400[];
extern char lbl_98_data_2914[], lbl_98_data_28E8[], lbl_98_data_2880[];
extern PikachuArticleMediatorVtable lbl_98_data_82F8;
void* fn_98_14D3C(void*, short);
void __register_global_object(void*, void*, void*);

void fn_98_1BAD4(void*) {
    if (lbl_98_bss_36C == 0) {
        lbl_98_bss_370.vtable = reinterpret_cast<PikachuArticleMediatorVtable*>(lbl_98_data_2914);
        lbl_98_bss_370.operatorVtable = lbl_98_data_28E8;
        lbl_98_bss_370.vtable = reinterpret_cast<PikachuArticleMediatorVtable*>(lbl_98_data_2880);
        lbl_98_bss_370.operatorVtable = lbl_98_data_2880 + 0x10;
        lbl_98_bss_370.vtable = &lbl_98_data_82F8;
        lbl_98_bss_370.operatorVtable = reinterpret_cast<char*>(&lbl_98_data_82F8) + 0x10;
        __register_global_object(&lbl_98_bss_370, reinterpret_cast<void*>(fn_98_14D3C), lbl_98_bss_400);
        lbl_98_bss_36C = 1;
    }
    reinterpret_cast<PikachuArticleMediatorInterface*>(&lbl_98_bss_370)->callback();
}
}
