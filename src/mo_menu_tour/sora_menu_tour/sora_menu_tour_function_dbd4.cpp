#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_800B5854(void*, int, int, int, int);
void* memset(void*, int, unsigned long);
unsigned long strlen(const char*);
void fn_8006BAB0(char*, const void*, int, int);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
void fn_800B92D8(void*, unsigned long, char*, unsigned long);
extern char lbl_3_data_CB8[];
}

struct Entry {
    char data[0x2c];
};

struct Menu {
    char pad0[0x44];
    int state;
    char pad48[4];
    int field4c;
    char pad50[0xb0];
    void* message;
    char pad104[4];
    Entry entries[9];
    void* panels[3];
    void* items[24];
    u32 count;
    char pad304[0x38];
    u32 selected;
    char pad340[0x38];
    int field378;
};

extern "C" void fn_3_DBD4(Menu* self, u32 selected) {
    self->state = 15;
    self->selected = selected;
    self->field4c = 0;
    self->field378 = 0;

    fn_800B5854(self->panels[0], 3, 1, 1, 0);
    fn_800B5854(self->panels[1], 3, 0x11, 1, 0);
    fn_800B5854(self->panels[2], 3, 0x13, 1, 0);

    u32 i;
    char* cursor = (char*)self;
    for (i = 0; i < self->count; cursor += 4, ++i) {
        if (i != selected)
            fn_800B5854(*(void**)(cursor + 0x2a0), 8, 0x11, 1, 0);
        else
            fn_800B5854(*(void**)(cursor + 0x2a0), 9, 0x11, 1, 0);
    }

    Entry* entry = &self->entries[selected];
    for (int j = 0; j < 5; ++j) {
        char buffer[8];
        memset(buffer, 0, 8);
        fn_8006BAB0(buffer, entry, j, 1);

        if (strlen(buffer) == 0)
            printf__5MuMsgFUlPCce(self->message, j + 1, lbl_3_data_CB8);
        else
            fn_800B92D8(self->message, j + 1, buffer, strlen(buffer));
    }
}
