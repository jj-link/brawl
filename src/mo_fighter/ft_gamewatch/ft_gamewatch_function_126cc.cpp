#pragma force_active on
typedef struct DtorChain {
    struct DtorChain *next;
    void *dtor;
    void *obj;
} DtorChain;

struct GWObj {
    int m;
};

extern "C" void fn_107_12714(void *obj);
extern "C" void *fn_107_1268C(void *ptr, short doDelete);
extern "C" void *__register_global_object(void *object, void *destructor, DtorChain *chain);

extern GWObj lbl_107_bss_19C;
extern DtorChain lbl_107_bss_190;

extern "C" void fn_107_126CC(void)
{
    fn_107_12714(&lbl_107_bss_19C);
    __register_global_object(&lbl_107_bss_19C, (void *)fn_107_1268C, &lbl_107_bss_190);
}

__declspec(section ".ctors") extern void* const fn_107_126CC_ctor = (void*)fn_107_126CC;
