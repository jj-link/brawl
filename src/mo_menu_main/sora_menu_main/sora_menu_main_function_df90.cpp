#include <stdio.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

extern "C" {
extern const char lbl_2_data_11B8[];
}

struct soraMenuMain {
    u8 _0[0x44];
    u8 m_byte;             // 0x44
    u8 _1[0x290 - 0x45];   // 0x45 .. 0x28F
    gfFileIOHandle m_handle; // 0x290
    u8 _2[0x2B0 - 0x294];   // 0x294 .. 0x2AF
    void* m_data[2];        // 0x2B0
    int m_index;            // 0x2B8
};

extern "C" void fn_2_DF90(soraMenuMain* obj) {
    char buf[0x40];
    sprintf(buf, lbl_2_data_11B8, obj->m_byte);
    obj->m_handle.readRequest(buf, obj->m_data[obj->m_index], 0, 0);
    obj->m_index++;
    if (obj->m_index >= 2) obj->m_index = 0;
}
