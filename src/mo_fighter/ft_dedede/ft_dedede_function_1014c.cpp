#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

// Only the article-manager interface used here is absent from the shared headers.
class DededeArticleManager {
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
    virtual void slot4C();
    virtual void slot50();
    virtual int getArticleCount(int kind);
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void* getArticle(int kind, int index);
};

struct DededeCommonInputParameters {
    unsigned char prefix[0x18];
    float stickThreshold;
    int flickFrames;
    float flickBonus;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
DededeCommonInputParameters* fn_27_14548C(void*);
extern const float lbl_117_rodata_60, lbl_117_rodata_64;
extern const char lbl_117_data_3254[], lbl_117_data_3A3C[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getInstance__9itManagerFv();
int fn_27_2A3EC8(void*, int);
float randf__Fv();
bool fn_117_20B30(void*);
void fn_117_20BBC(void*);
}

static inline double absoluteStick(float value) {
    return __fabs(value);
}

static inline float addFlickBonus(int frames, float bonus) {
    return static_cast<float>(frames) + bonus;
}

extern "C" void fn_117_1014C(void*, soModuleAccesser* accesser) {
    float stick = absoluteStick(accesser->getControllerModule().getStickX());
    if (stick >= fn_27_14548C(g_ftCommonDataAccesser)->stickThreshold) {
        soControllerModule& controller = accesser->getControllerModule();
        float bonus = fn_27_14548C(g_ftCommonDataAccesser)->flickBonus;
        float frames = addFlickBonus(fn_27_14548C(g_ftCommonDataAccesser)->flickFrames, bonus);
        if (controller.getFlickNoResetX() < frames) {
            accesser->getWorkManageModule().onFlag(0x22000014);
        }
    }
    accesser->getPostureModule().setStickLR(lbl_117_rodata_60);
    accesser->getPostureModule().updateRotYLr();
    if (accesser->getWorkManageModule().getInt(0x10000041) > 0) {
        accesser->getWorkManageModule().setInt(0, 0x20000000);
        accesser->getWorkManageModule().subInt(1, 0x10000041);
    } else {
        float hammer = soValueAccesser::getConstantFloat(accesser, 0xdb2, 0);
        float extra = lbl_117_rodata_64 * hammer * soValueAccesser::getConstantFloat(accesser, 0xfb3, 0);
        float normalWeight = soValueAccesser::getConstantFloat(accesser, 0xfaf, 0);
        float waddleDooWeight = soValueAccesser::getConstantFloat(accesser, 0xfb0, 0);
        float gordoWeight = extra + soValueAccesser::getConstantFloat(accesser, 0xfb1, 0);
        float itemWeight = soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
        int kind;
        if (fn_27_2A3EC8(getInstance__9itManagerFv(), 9)) {
            itemWeight += gordoWeight + (normalWeight + waddleDooWeight);
            float choice = itemWeight * randf__Fv();
            if (choice < normalWeight) kind = 0;
            else if (choice < normalWeight + waddleDooWeight) kind = 1;
            else if (choice < gordoWeight + (normalWeight + waddleDooWeight)) kind = 2;
            else kind = 3;
        } else {
            gordoWeight += normalWeight + waddleDooWeight;
            float choice = gordoWeight * randf__Fv();
            if (choice < normalWeight) kind = 0;
            else if (choice < normalWeight + waddleDooWeight) kind = 1;
            else kind = 2;
        }
        if (kind != 0) {
            accesser->getWorkManageModule().setInt(
                soValueAccesser::getConstantInt(accesser, 0x5dc3, 0), 0x10000041);
        }
        accesser->getWorkManageModule().setInt(kind, 0x20000000);
    }
    accesser->getWorkManageModule().setFloat(
        soValueAccesser::getConstantFloat(accesser, 0xfac, 0), 0x21000004);
    if (accesser->getWorkManageModule().getInt(0x20000000) != 3) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        int maxCount = soValueAccesser::getConstantInt(accesser, 0x5dc2, 0);
        if (work.getInt(0x10000040) >= maxCount) {
            DededeArticleManager* articles = static_cast<DededeArticleManager*>(
                accesser->m_enumerationStart->m_generateArticleManageModule);
            int count = articles->getArticleCount(4);
            for (int i = 0; i < count; ++i) {
                void* article = articles->getArticle(4, i);
                if (article != 0) {
                    void* waddle = __dynamic_cast(article, 0,
                        lbl_117_data_3254, lbl_117_data_3A3C, 0);
                    if (fn_117_20B30(waddle)) {
                        fn_117_20BBC(waddle);
                        accesser->getWorkManageModule().onFlag(0x22000018);
                        break;
                    }
                }
            }
        }
    }
}
