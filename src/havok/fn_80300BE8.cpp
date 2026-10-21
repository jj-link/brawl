#pragma force_active on
struct Entry {
    char pad[6];
    unsigned short id;
};

extern "C" void fn_80300BE8(int unused, char* arg1, short arg2) {
    Entry* base = (Entry*)(arg1 + 0xC);
    int count = ((unsigned char*)base)[2];
    int i;
    for (i = 0; i < count; i++) {
        if (base[i].id == 0xFFFF) {
            base[i].id = arg2;
            return;
        }
    }
}
