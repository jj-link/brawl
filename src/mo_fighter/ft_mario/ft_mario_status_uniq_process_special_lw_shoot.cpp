#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/article/so_article.h>

struct ShootProcess { void* vtable; };
struct ShootRegistration { void* next; void* object; void* destructor; };
struct ShootTypeInfo { const char* name; const void* bases; const void* end; };
struct ShootBaseInfo { const void* type; int adjustment; const void* end; };
typedef void (*ShootMethod)();
struct ShootVtable { const ShootTypeInfo* type; unsigned long reserved; ShootMethod methods[14]; };
// Only the article lookup entry is exposed here: the common headers leave
// the generate-article manager opaque. Its preceding virtual entries retain
// their original positions and are not invoked by this process.
class ShootArticleManager {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5C() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
public:
    virtual soArticle* getArticle(int) = 0;
};
extern "C" {
extern const char lbl_91_data_719C[], lbl_91_data_2C90[], lbl_91_data_779C[];
extern ShootVtable lbl_91_data_77A8;
extern const float lbl_91_rodata_18[2] = { 0.0f, 0.0f };
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __register_global_object(void*, void*, void*);
void fn_91_13334(void*, float);
void fn_91_E10C(); void fn_91_E150(); void fn_91_E108();
void fn_91_E104(); void fn_91_E100(); void fn_91_E0FC();
void fn_91_E0F8(); void fn_91_E0F0(); void fn_91_E0EC();
void fn_91_E0E4(); void fn_91_E0E0(); void fn_91_E0D8();
ShootProcess* fn_91_E3B4(ShootProcess*);
}
extern "C" void fn_91_E1B0(ShootProcess*, soModuleAccesser* accesser) {
    ShootArticleManager* manager = static_cast<ShootArticleManager*>(accesser->m_enumerationStart->m_generateArticleManageModule);
    void* article = __dynamic_cast(manager->getArticle(2), 0,
        lbl_91_data_719C, lbl_91_data_2C90, 0);
    soWorkManageModule* work = &accesser->getWorkManageModule();
    float maximum = static_cast<float>(soValueAccesser::getConstantInt(accesser, 0x5dc0, 0));
    int charge = work->getInt(0x10000040);
    float proportion = static_cast<float>(charge) / maximum;
    fn_91_13334(article, proportion);
    work = &accesser->getWorkManageModule();
    float recoil = soValueAccesser::getConstantFloat(accesser, 0xfae, 0);
    charge = work->getInt(0x10000040);
    Vec3f speed(-(static_cast<float>(charge) * recoil), lbl_91_rodata_18[0], lbl_91_rodata_18[0]);
    accesser->getKineticModule().addSpeed(&speed, accesser);
}
extern "C" ShootProcess* fn_91_E32C(ShootProcess* process, short deleting) {
    if (process != 0 && deleting > 0) operator delete(process);
    return process;
}
extern "C" {
ShootRegistration lbl_91_bss_1E8;
ShootProcess lbl_91_bss_1F4;
}
extern "C" void fn_91_E36C() {
    fn_91_E3B4(&lbl_91_bss_1F4);
    __register_global_object(&lbl_91_bss_1F4, reinterpret_cast<void*>(fn_91_E32C), &lbl_91_bss_1E8);
}
#pragma dont_inline on
extern "C" ShootProcess* fn_91_E3B4(ShootProcess* process) {
    process->vtable = &lbl_91_data_77A8;
    return process;
}
#pragma dont_inline reset
extern "C" {
extern ShootTypeInfo lbl_91_data_781C;
ShootVtable lbl_91_data_77A8 = { &lbl_91_data_781C, 0,
    { reinterpret_cast<ShootMethod>(fn_91_E32C), reinterpret_cast<ShootMethod>(fn_91_E1B0),
      fn_91_E10C, fn_91_E150, fn_91_E108, fn_91_E104, fn_91_E100, fn_91_E0FC,
      fn_91_E0F8, fn_91_E0F0, fn_91_E0EC, fn_91_E0E4, fn_91_E0E0, fn_91_E0D8 } };
__declspec(align(4)) char lbl_91_data_77E8[] = "ftMarioStatusUniqProcessSpecialLwShoot";
ShootBaseInfo lbl_91_data_7810 = { lbl_91_data_779C, 0, 0 };
ShootTypeInfo lbl_91_data_781C = { lbl_91_data_77E8, &lbl_91_data_7810, 0 };
}
__declspec(section ".ctors") extern void (*const shootInitializer)() = fn_91_E36C;
