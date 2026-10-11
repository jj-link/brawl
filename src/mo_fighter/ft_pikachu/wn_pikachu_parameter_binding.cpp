#include <so/so_module_accesser.h>
#include <ft/ft_common_data_accesser.h>

struct PikachuParameterOwner {
    char prefix[0xc4];
    int parameter;
    int kind;
};
struct PikachuParameterBinding {
    int* ownerParameter;
    void* heapModule;
};
struct PikachuParameterLookupStatus {
    bool flags[2];
    inline PikachuParameterLookupStatus() { flags[0] = false; flags[1] = false; }
};
extern "C" {
extern const char lbl_98_data_906C[];
extern const char lbl_98_data_2458[];
extern const char lbl_98_data_2F88[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_27_14815C(ftCommonDataAccesser*, int, bool*);
void* fn_98_11DF8(void*, int, const PikachuParameterBinding*, void*);

void* fn_98_1776C(void* object, soModuleAccesser* accesser) {
    *static_cast<const void**>(object) = lbl_98_data_906C;
    PikachuParameterLookupStatus status;
    const int kind = static_cast<PikachuParameterOwner*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_2458, lbl_98_data_2F88, short(1)))->kind;
    void* heapModule = accesser->m_enumerationStart->m_heapModule;
    PikachuParameterOwner* owner = static_cast<PikachuParameterOwner*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_2458, lbl_98_data_2F88, short(1)));
    PikachuParameterBinding binding = { &owner->parameter, heapModule };
    void* parameters = fn_27_14815C(&g_ftCommonDataAccesser, kind, &status.flags[1]);
    fn_98_11DF8(static_cast<char*>(object) + 4, 0, &binding, parameters);
    return object;
}
}
