#pragma force_active on
struct PikminProcessEntry {
    void* vtable;
    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

class soModuleAccesser;

extern "C" {
PikminProcessEntry* fn_113_FCD4(void*, int);
PikminProcessEntry* fn_113_FBEC(void*, int);
PikminProcessEntry* fn_113_FB04(void*, int);
PikminProcessEntry* fn_113_FA1C(void*, int);
PikminProcessEntry* fn_113_F934(void*, int);
PikminProcessEntry* fn_113_F84C(void*, int);
PikminProcessEntry* fn_113_F764(void*, int);
PikminProcessEntry* fn_113_F67C(void*, int);

void fn_113_FC9C(PikminProcessEntry*, soModuleAccesser*);
void fn_113_FBB4(PikminProcessEntry*, soModuleAccesser*);
void fn_113_FACC(PikminProcessEntry*, soModuleAccesser*);
void fn_113_F9E4(PikminProcessEntry*, soModuleAccesser*);
void fn_113_F8FC(PikminProcessEntry*, soModuleAccesser*);
void fn_113_F814(PikminProcessEntry*, soModuleAccesser*);
void fn_113_F72C(PikminProcessEntry*, soModuleAccesser*);
void fn_113_F644(PikminProcessEntry*, soModuleAccesser*);
}

extern "C" void fn_113_F168(unsigned char* processes, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_FCD4(processes + 0x208, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_FC9C(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_FBEC(processes + 0x1cc, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_FBB4(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_FB04(processes + 0x180, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_FACC(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_FA1C(processes + 0x138, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_F9E4(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_F934(processes + 0xf0, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_F8FC(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_F84C(processes + 0x98, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_F814(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_F764(processes + 0x64, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_F72C(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_F67C(processes + 8, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_F644(entry, accesser);
    }
}