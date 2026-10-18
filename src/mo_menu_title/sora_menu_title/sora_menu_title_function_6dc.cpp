#pragma force_active on
#pragma once
struct MenuTitleBase {
    char _pad[0x1d4];
    int m_flag;
};

extern "C" void fn_24_6DC(MenuTitleBase* self) {
    self->m_flag = 7;
}
