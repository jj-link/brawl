#include <ft/fighter.h>
#include <ft/ft_owner.h>
#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" {
unsigned int fn_27_111E60(ftOwner*);
unsigned int fn_27_111E00(ftOwner*);
unsigned int fn_27_111EC0(ftOwner*);
unsigned int fn_27_111DD0(ftOwner*);
unsigned int fn_27_111E90(ftOwner*);
int fn_27_112060(ftOwner*);
int fn_27_11206C(ftOwner*);
void fn_27_1392D4(Fighter*, float, float, int, int, int);
float fn_27_18B520(soModuleAccesser*, int, int);
void fn_27_137EA4(Fighter*, bool, int, int, int, float);
extern const float lbl_27_rodata_1048;
extern const float lbl_27_rodata_1058;
}
void Fighter::setupEquipment() {
    int kind;
    soModuleAccesser* acc;
    ftOwner* owner = getOwner();
    acc = m_moduleAccesser;
    if (!owner->isSubOwner() && fn_27_111E60(owner) == 1)
        setCurry(true, -1);
    if (fn_27_111E00(owner) == 1)
        setMetal(true, lbl_27_rodata_1058, -1);
    if (fn_27_111EC0(owner) == 1) {
        float a = soValueAccesser::getConstantFloat(acc, 0xd88, 0);
        float b = soValueAccesser::getConstantFloat(acc, 0xd86, 0);
        fn_27_1392D4(this, lbl_27_rodata_1048, (soValueAccesser::getConstantFloat(acc, 0xd89, 0) - b) / a, 1, 1, 0);
    }
    if (fn_27_111DD0(owner) == 1)
        acc->m_enumerationStart->m_itemManageModule->attachItem((itKind)0x44, 0, true);
    if (fn_27_111E90(owner) == 1)
        acc->m_enumerationStart->m_itemManageModule->attachItem((itKind)1, 0, true);
    if (fn_27_112060(owner)) {
        kind = !fn_27_11206C(owner) ? 3 : 5;
        fn_27_137EA4(this, true, fn_27_112060(owner), kind, -1, fn_27_18B520(acc, kind, fn_27_112060(owner)));
    }
}