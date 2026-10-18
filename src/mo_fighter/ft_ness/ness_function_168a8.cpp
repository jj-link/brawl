#pragma force_active on

struct NessTable { float m_data[16]; };
struct NessTableHolder { NessTable* table; };

extern "C" {
extern const NessTable lbl_101_data_99A0;
}

extern "C" void fn_101_168A8(NessTableHolder* holder) {
    holder->table = const_cast<NessTable*>(&lbl_101_data_99A0);
}
