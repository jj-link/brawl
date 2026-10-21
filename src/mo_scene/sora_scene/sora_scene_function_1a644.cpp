#pragma force_active on
typedef unsigned char u8;

struct Entry {
    u8 kind;
    u8 state;
    u8 pad2[4];
    u8 f6;
    u8 pad7[3];
    u8 count;
    u8 rest[0x5C - 0xB];
};

struct Global {
    u8 pad[8];
    u8* data;
};

extern "C" int fn_27_2480CC(int);
extern Global* g_GameGlobal;

extern "C" void fn_1_1A644() {
    u8* data = g_GameGlobal->data;
    Entry* ei = (Entry*)(data + 0x98);
    Entry* ej;
    int i = 0;
    do {
        ei->count = 0;
        if (ei->state != 3) {
            int k = fn_27_2480CC(ei->kind);
            if (k != 0x23) {
                ej = (Entry*)(data + 0x98);
                int j = 0;
                while (j < i) {
                    if (ej->state != 3 && k == fn_27_2480CC(ej->kind) && ei->f6 == ej->f6) {
                        ei->count++;
                    }
                    ej++;
                    j++;
                }
            }
        }
        i++;
        ei++;
    } while (i < 4);
}
