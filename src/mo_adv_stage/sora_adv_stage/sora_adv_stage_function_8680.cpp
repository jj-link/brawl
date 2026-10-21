#pragma force_active on
extern "C" {
struct GameGlobal {
    char pad[8];
    char* data;
};
extern GameGlobal* g_GameGlobal;
extern void* g_ftManager;
extern const float lbl_40_rodata_2C[];
int getEntryId__9ftManagerFi(void*, int);
unsigned int isValidEntryId__9ftManagerFi(void*, int);
void* getOwner__9ftManagerFi(void*, int);
void fn_27_1125BC(float, void*);

int fn_40_8680(void*, int index, float value) {
    char* entry;
    char* data = g_GameGlobal->data;
    int id = getEntryId__9ftManagerFi(g_ftManager, index);
    int result = 0;
    if (isValidEntryId__9ftManagerFi(g_ftManager, id) == 1) {
        entry = data;
        entry += index * 0x5c;
        void* owner = getOwner__9ftManagerFi(g_ftManager, id);
        if (lbl_40_rodata_2C[0] != *(float*)(entry + 0xc4)) {
            fn_27_1125BC(*(float*)(entry + 0xc4) * value, owner);
        } else {
            fn_27_1125BC(value, owner);
        }
        result = 1;
    }
    return result;
}
}
