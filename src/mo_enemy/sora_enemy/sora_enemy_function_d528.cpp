#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class emManager {
public:
    void removeArchiveAll();

    u8 _00[0x0C];
    u32 m_count; // 0x0C
};

extern "C" void* fn_41_D5A0(emManager* self, u32 idx);
extern "C" void fn_41_D4B8(emManager* self, void* p);

void emManager::removeArchiveAll() {
    for (u32 i = 0; i < m_count; i++) {
        u8* e = (u8*)fn_41_D5A0(this, i);
        if (e != 0 && e[0] == 1) {
            fn_41_D4B8(this, *(void**)(e + 0x0C));
        }
    }
}
