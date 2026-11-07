#pragma force_active on
class soModuleAccesser;

struct KoopaProcessEntry {
    void* vtable;
    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

extern "C" {
KoopaProcessEntry* fn_102_BDD8(void*, int);
KoopaProcessEntry* fn_102_BCF0(void*, int);
KoopaProcessEntry* fn_102_BC08(void*, int);
KoopaProcessEntry* fn_102_BB20(void*, int);
KoopaProcessEntry* fn_102_BA38(void*, int);
KoopaProcessEntry* fn_102_B950(void*, int);
KoopaProcessEntry* fn_102_B868(void*, int);
KoopaProcessEntry* fn_102_B780(void*, int);
void fn_102_BDA0(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_BCB8(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_BBD0(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_BAE8(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_BA00(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_B918(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_B830(KoopaProcessEntry*, soModuleAccesser*);
void fn_102_B748(KoopaProcessEntry*, soModuleAccesser*);
}

extern "C" void fn_102_B26C(unsigned char* object, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_BDD8(object + 0x208, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_BDA0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_BCF0(object + 0x1cc, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_BCB8(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_BC08(object + 0x180, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_BBD0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_BB20(object + 0x138, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_BAE8(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_BA38(object + 0xf0, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_BA00(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_B950(object + 0x98, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_B918(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_B868(object + 0x64, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_B830(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KoopaProcessEntry* entry = fn_102_B780(object + 0x8, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_102_B748(entry, accesser);
    }
}
