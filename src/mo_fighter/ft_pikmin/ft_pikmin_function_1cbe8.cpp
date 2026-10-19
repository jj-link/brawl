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
PikminProcessEntry* fn_113_1D434(void*, int);
PikminProcessEntry* fn_113_1D34C(void*, int);
PikminProcessEntry* fn_113_1D264(void*, int);
PikminProcessEntry* fn_113_1D17C(void*, int);
PikminProcessEntry* fn_113_1D094(void*, int);
PikminProcessEntry* fn_113_1CFE4(void*, int);

void fn_113_1D3FC(PikminProcessEntry*, soModuleAccesser*);
void fn_113_1D314(PikminProcessEntry*, soModuleAccesser*);
void fn_113_1D22C(PikminProcessEntry*, soModuleAccesser*);
void fn_113_1D144(PikminProcessEntry*, soModuleAccesser*);
void fn_113_221CC(PikminProcessEntry*, soModuleAccesser*);
void fn_113_20B38(PikminProcessEntry*, soModuleAccesser*);
}

extern "C" void fn_113_1CBE8(unsigned char* processes, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_1D434(processes + 0x110, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_1D3FC(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_1D34C(processes + 0xf0, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_1D314(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_1D264(processes + 0xa4, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_1D22C(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_1D17C(processes + 0x68, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_1D144(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_1D094(processes + 0x48, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_221CC(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        PikminProcessEntry* entry = fn_113_1CFE4(processes + 0x08, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_113_20B38(entry, accesser);
    }
}
