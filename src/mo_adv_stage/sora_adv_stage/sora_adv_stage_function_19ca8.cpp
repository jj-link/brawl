#include <string.h>
#pragma force_active on

extern "C" {
    extern char lbl_40_data_3ED0[];
    extern const float lbl_40_rodata_278;

    struct fn_40_19CA8_t {
        void* m_ptr;
        char m_byte;
        int m_int;
        int m_unk0C;
        int m_unk10;
        float m_floats[8];
        char m_name[32];
    };

    fn_40_19CA8_t* fn_40_19CA8(fn_40_19CA8_t* obj, int param, const char* name) {
        obj->m_int = param;
        obj->m_ptr = &lbl_40_data_3ED0;
        obj->m_byte = 0;
        obj->m_unk0C = 0;
        obj->m_unk10 = 0;
        obj->m_floats[0] = lbl_40_rodata_278;
        obj->m_floats[1] = lbl_40_rodata_278;
        obj->m_floats[2] = lbl_40_rodata_278;
        obj->m_floats[3] = lbl_40_rodata_278;
        obj->m_floats[4] = lbl_40_rodata_278;
        obj->m_floats[5] = lbl_40_rodata_278;
        obj->m_floats[6] = lbl_40_rodata_278;
        obj->m_floats[7] = lbl_40_rodata_278;
        memset(obj->m_name, 0, 0x20);
        strncpy(obj->m_name, name, 0x1f);
        return obj;
    }
}
