#include <types.h>
#include <gm/gm_global.h>
#include <ms/ms_message.h>
#include <snd/snd_system.h>
#include <mu/selchar/mu_selchar.h>
#include <stdio.h>
#include <string.h>

#pragma force_active on

struct WifiTask {
    char pad[0xFCA];
    u8 flags;
};

struct SelCharTaskState {
    char pad000[0x40];
    s32 value40;
    void* areas;
    char pad048[0x24];
    s32 value6C;
    char pad070[0x558];
    u8 value5C8;
    char pad5C9[3];
    s32 value5CC;
    char pad5D0[4];
    s32 value5D4;
    s32 value5D8;
    s32 value5DC;
    s32 value5E0;
    char pad5E4[0x1C];
    s32 value600;
    s32 value604;
    s32 value608;
    void* value60C;
    Message* message;
    s32 value614;
    s32 timer;
    u8 value61C;
    char pad61D[0x19];
    s8 value636;
    u8 value637[4];
    char pad63B;
    s32 value63C;
    u8 value640;
    char pad641[3];
    s32 value644;
    s32 value648;
};

struct SelCharBits {
    u8 a : 2;
    u8 b : 2;
    u8 c : 2;
    u8 pad0 : 2;
    u8 d : 3;
    u8 e : 1;
    u8 pad1 : 4;
};

struct MessageArgs {
    u8 flag;
    char pad1[3];
    s32 a;
    u8 b;
    char pad2[3];
    s32 c;
    u8 d;
};

extern "C" {
extern WifiTask* g_muWifiInterfaceTask;
extern const char lbl_10_data_4C[];

int fn_800CBCB0(void*, s32*);
void fn_10_B1CC(void*);
void* fn_800C9B00(s32);
int fn_800C9B14(s32);
void fn_10_10ACC(void*, u8);
void* fn_800BF048(int, void*, int, void*, void*, int, int, int, int, int, int, int);
void fn_10_19EF0(void*, u8);
void fn_10_1C57C(void*, u8);
void fn_800BF928(void*, void*);
int fn_800CCA9C(void*, s32*, s32*);
int fn_800D69C8(void*, int);
void fn_10_4A54(void*, int, int, void*);
u8 fn_10_1278();
u8 fn_800D4544(void*);
void fn_800DA6EC(s32, u32, int);
void fn_10_C450(void*, int);
int fn_10_61D8(void*);
void fn_10_C420(void*, int);
int fn_800D4EF0(void*, s32*, u8*, s32*);
void fn_10_C7E0(void*);
int fn_800D82E8(void*, u8*, int);
void fn_10_F784(void*, int);
void fn_10_10324(void*);
void fn_10_FD00(void*, int);
int fn_10_BA4C(void*, s32*, s32*, MessageArgs*);
void fn_10_10398(void*, int);
void fn_10_1046C(void*, int, s32, u8);
void fn_10_105A0(void*, int);
void fn_10_F4E0(void*, int);
void fn_10_4374(void*);
void fn_10_F9D4(void*, int, int);
void fn_10_C4C8(void*, int);
int fn_803F6150(const void*, const void*, unsigned long);
void fn_800D81C4(void*, void*, u32);
void fn_10_10AF8(void*, int);
void fn_10_10BE0(void*, int);
}

static inline void openWifiMessage(SelCharTaskState* self, char* const& textData, const u32& lengthData) {
    char* text;
    u32 length;
    length = lengthData;
    text = textData;
    fn_10_B1CC(self);
    fn_10_10ACC(self, 0);
    self->value60C = fn_800BF048(
        0, text, length, (void*)self->value608,
        (void*)self->value6C, 0x74, 0x1E, 0x2A, 0x2A, 0, 0, 0xF0);
}

static inline void setAreasBusy(SelCharTaskState* self) {
    void** area = (void**)self;
    for (int i = 0; i < self->value648; ++i) {
        fn_10_19EF0(*(void**)((char*)area[0x11] + 0x1A8), 1);
        fn_10_1C57C(*(void**)((char*)area[0x11] + 0x1AC), 1);
        ++area;
    }
}

static inline bool hasMatchingPlayerCount() {
    WifiTask* task = g_muWifiInterfaceTask;
    bool indicator = (task->flags >> 5) & 1;
    if (!indicator) {
        u8 local = fn_10_1278();
        if (local == 0xFF)
            local = 4;
        u8 current = fn_800D4544(task);
        indicator = (current == local);
    }
    return indicator;
}

#define CLASSIFY_STATE() \
    state = ((u8*)g_GameGlobal->m_selCharData)[4]; \
    if (state >= 0 && state < 4) result = 1; else result = 0; \
    if (result != 0) { \
        result = 0; \
    } else { \
        if (state >= 4 && state < 0xC) result = 1; else result = 0; \
        if (result != 0) { \
            result = 1; \
        } else { \
            int inRange; \
            if (state >= 0xC && state < 0x10) inRange = 1; else inRange = 0; \
            result = 3; \
            if (inRange != 0) result = 2; \
        } \
    }

#define SYNC_PACKET() \
    CLASSIFY_STATE(); \
    if (result == 2) { \
        if (hasMatchingPlayerCount()) { \
            union { SelCharBits bits; u8 bytes[4]; } data; \
            memset(&data, 0, 4); \
            data.bits.a = self->value5D4; \
            data.bits.b = self->value5CC; \
            data.bits.c = (self->value5C8 != 0); \
            data.bytes[2] = self->value5D8; \
            data.bytes[3] = self->value5DC; \
            data.bits.d = self->value604; \
            data.bits.e = self->value600; \
            if (fn_803F6150(&data, self->value637, 4) != 0) { \
                fn_800D81C4(g_muWifiInterfaceTask, &data, 1); \
                self->value637[0] = data.bytes[0]; \
                self->value637[1] = data.bytes[1]; \
                self->value637[2] = data.bytes[2]; \
                self->value637[3] = data.bytes[3]; \
            } \
        } \
    }

extern "C" void fn_10_5368(SelCharTaskState* self) {
    s32 value58[3];
    s32 value54;
    u32 value50;
    char* value4C;
    s32 value48;
    s32 value44;
    s32 value40;
    s32 value3C;
    u32 textLength;
    char* text;
    u32 value30;
    char* value2C;
    s32 value28;
    s32 value24;
    char buffer[0x80];
    int state;
    WifiTask* wifi;
    int result;
    MessageArgs args;
    char* savedText;
    u32 savedLength;

    wifi = g_muWifiInterfaceTask;
    if (self->value40 != 7) {
        result = fn_800CBCB0(wifi, &value54);
        if (result != 0) {
            fn_10_B1CC(self);
            Message::getPrintIndexData(
                self->message, (u32)fn_800C9B00(result), &text, &textLength);

            savedLength = textLength;
            savedText = text;

            fn_10_B1CC(self);
            fn_10_10ACC(self, 0);
            self->value60C = fn_800BF048(
                0, savedText, savedLength, (void*)self->value608,
                (void*)self->value6C, 0x74, 0x1E, 0x2A, 0x2A, 0, 0, 0xF0);

            setAreasBusy(self);

            if (fn_800C9B14(result) != 0) {
                Message::getPrintIndexData(self->message, 0x13, &value4C, &value50);
                memcpy(buffer, value4C, value50);
                value50 += sprintf(buffer + value50, lbl_10_data_4C, value54);
                fn_800BF928(self->value60C, buffer);
            }

            fn_10_4A54(self, 7, 0, 0);
            return;
        }

        if (self->value640 != 0 && self->value644 != 2) {
            int selection = -1;
            if (self->value644 == 0) {
                switch (fn_800CCA9C(wifi, &value40, &value3C)) {
                case 1:
                    break;
                case 2:
                    self->value644 = 1;
                    break;
                case 6:
                    selection = 0x1B;
                    break;
                case 7:
                    selection = 0x1C;
                    break;
                }
            } else {
                switch (fn_800D69C8(wifi, 0)) {
                case 0:
                    break;
                case 1:
                    self->value644 = 2;
                    break;
                case 2:
                    selection = 0x1B;
                    break;
                }
            }

            if (selection >= 0) {
                fn_10_B1CC(self);
                Message::getPrintIndexData(
                    self->message, selection, &value2C, &value30);

                openWifiMessage(self, value2C, value30);

                setAreasBusy(self);

                fn_10_4A54(self, 7, 0, 0);
                self->value644 = 3;
                return;
            }
        }
    }

    if (self->value40 == 7 || self->value40 == 1)
        return;

    if (self->value61C != 0 && self->value40 != 1 && self->timer > 0) {
        --self->timer;
        if (self->timer <= 0x12C && self->timer % 60 == 0)
            g_sndSystem->playSE((SndID)0xA, -1, 0, 0, -1);

        fn_800DA6EC(self->value614, (self->timer + 0x3B) / 60, 0);
        if (self->timer <= 0) {
            fn_10_4A54(self, 1, 0, 0);
            return;
        }
    }

    CLASSIFY_STATE();
    if (result != 2)
        return;

    if (self->value40 != 8) {
        if (fn_800D4EF0(wifi, value58, (u8*)self + 0x635, &value48) != 0) {
            fn_10_B1CC(self);
            self->value636 = (u8)value48;
            fn_10_4A54(self, 8, 0, value58);
        }
    }

    fn_10_C450(self, 0xB8);
    if (fn_10_61D8(self) != 0)
        fn_10_C420(self, 0xB8);

    if (hasMatchingPlayerCount())
        return;

    if (--self->value63C > 0)
        return;
    self->value63C = 0;

    if (fn_800D82E8(wifi, (u8*)&value44, 0) == 0)
        return;

    state = ((u8*)g_GameGlobal->m_selCharData)[4];
    switch (state) {
    case 0xD:
        self->value604 = (((u8*)&value44)[1] >> 5) & 7;
        fn_10_F784(self, self->value604);
        fn_10_10324(self);
        fn_10_FD00(self, 3);
        result = fn_10_BA4C(self, &value24, &value28, &args);
        ((muSelCharTask*)self)->dispHighScore(4, result, value24);
        fn_10_10398(self, value28);

        if (args.flag != 0) {
            fn_10_1046C(self, 0, args.a, args.b);
            fn_10_1046C(self, 1, args.c, args.d);
        } else {
            fn_10_105A0(self, 0);
            fn_10_105A0(self, 1);
        }
        break;

    case 0xE:
        self->value600 = (((u8*)&value44)[1] >> 4) & 1;
        fn_10_F4E0(self, self->value600);
        fn_10_105A0(self, 0);
        fn_10_105A0(self, 1);
        fn_10_10324(self);
        fn_10_4374(self);
        break;

    case 0xF:
        self->value5E0 = (((u8*)&value44)[1] >> 1) & 7;
        fn_10_F9D4(self, self->value5E0, 1);
        break;

    default:
        result = (((u8*)&value44)[0] >> 2) & 3;
        if ((result != 0) != self->value5C8)
            fn_10_C4C8(self, result != 0);

        self->value5D4 = (((u8*)&value44)[0] >> 6) & 3;
        SYNC_PACKET();

        self->value5D8 = ((u8*)&value44)[2];
        SYNC_PACKET();

        self->value5DC = ((u8*)&value44)[3];
        SYNC_PACKET();

        fn_10_C7E0(self);
        result = (((u8*)&value44)[0] >> 4) & 3;
        if (result != self->value5CC) {
            fn_10_10AF8(self, result == 2);
            self->value5CC = (((u8*)&value44)[0] >> 4) & 3;
        }
        break;
    }

    fn_10_10BE0(self, 0x20);
    self->value63C = 0xB4;
}
