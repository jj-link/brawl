#include <ft/ft_manager.h>
#include <ft/ft_common_data_accesser.h>

#pragma force_active on

struct Entry {
    int id;
    int kind;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry* slot2(int index);
    virtual int slot3();
    virtual unsigned int slot4();
};

extern "C" const float lbl_27_rodata_2718;

extern "C" float fn_27_1D5658(Object_vptr_0* self, Entry* entry) {
    float result = lbl_27_rodata_2718;
    if (!g_ftManager->m_noOnePatternOffsett) {
        return result;
    }
    ftDataCommon* common = g_ftCommonData.dataCommon;
    if (entry->kind == 0 || self->slot4() == 1U) {
        result += **reinterpret_cast<float**>(reinterpret_cast<char*>(common) + 0x44);
        return result;
    }
    int count = self->slot3();
    unsigned int unchanged = 1;
    for (int i = 0; i < count; ++i) {
        Entry* other = self->slot2(i);
        if (other->kind == entry->kind && other->id != entry->id) {
            unchanged = 0;
            result -= (*reinterpret_cast<float**>(reinterpret_cast<char*>(common) + 0x44))[i + 1];
        }
    }
    if (unchanged == 1U) {
        result += **reinterpret_cast<float**>(reinterpret_cast<char*>(common) + 0x44);
    }
    return result;
}
