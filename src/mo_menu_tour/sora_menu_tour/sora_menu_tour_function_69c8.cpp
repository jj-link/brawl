#include <mu/mu_msg.h>
#include <string.h>
#pragma force_active on

extern "C" {
void fn_3_2DD4(void*, unsigned long);
void fn_3_8880(void*);
void fn_800B92D8(MuMsg*, unsigned long, char*, unsigned long);
const char* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, int*);
extern void* g_GameGlobal;
}

struct TourTable {
    int values[3][9];
};

extern "C" const TourTable lbl_3_rodata_82B8;

extern "C" void fn_3_69C8(void* self, int update)
{
    char* s = static_cast<char*>(self);
    TourTable table = lbl_3_rodata_82B8;
    int size3;
    int size1;
    int size2;

    MuObject* object = *reinterpret_cast<MuObject**>(s + 0x628);
    object->setFrameNode(static_cast<float>(*reinterpret_cast<unsigned int*>(s + 0x9ec)));

    MuMsg* msg = *reinterpret_cast<MuMsg**>(s + 0xf8);
    msg->printIndex(0, *reinterpret_cast<unsigned int*>(s + 0x9ec) + 2, 0);
    msg = *reinterpret_cast<MuMsg**>(s + 0xf8);
    msg->setAlignMode(1, MuMsg::Align_Center);
    msg = *reinterpret_cast<MuMsg**>(s + 0xf8);
    msg->printIndex(1, *reinterpret_cast<unsigned int*>(s + 0x9ec) + 0x14, 0);

    if (update) {
        fn_3_2DD4(self, 3);

        {
            int value = *reinterpret_cast<int*>(s + 0x9e0);
            unsigned long pos = 0;
            char buffer[0x80];
            const char* data;

            memset(buffer, 0, sizeof(buffer));
            if (static_cast<unsigned int>(value) >= 10) {
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), value / 10 + 0x2b, &size1);
                memcpy(buffer, data, size1);
                pos = size1;
            }
            data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), value % 10 + 0x2b, &size1);
            memcpy(buffer + pos, data, size1);
            pos += size1;
            data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 4, &size1);
            memcpy(buffer + pos, data, size1);
            fn_800B92D8(*reinterpret_cast<MuMsg**>(s + 0xf8), 2, buffer, pos + size1);
        }

        {
            int value = reinterpret_cast<int (*)[9]>(
                reinterpret_cast<char*>(&table) - 0x48)
                [*reinterpret_cast<unsigned int*>(s + 0x9e0)]
                [*reinterpret_cast<unsigned int*>(s + 0x9e4)];
            unsigned long pos = 0;
            char buffer[0x80];
            const char* data;

            memset(buffer, 0, sizeof(buffer));
            if (static_cast<unsigned int>(value) >= 10) {
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), value / 10 + 0x2b, &size2);
                memcpy(buffer, data, size2);
                pos = size2;
            }
            data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), value % 10 + 0x2b, &size2);
            memcpy(buffer + pos, data, size2);
            pos += size2;
            data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 5, &size2);
            memcpy(buffer + pos, data, size2);
            fn_800B92D8(*reinterpret_cast<MuMsg**>(s + 0xf8), 3, buffer, pos + size2);
        }

        {
            unsigned char* settings = *reinterpret_cast<unsigned char**>(
                static_cast<char*>(g_GameGlobal) + 0x1c);
            unsigned long pos = 0;
            char buffer[0x100];
            const char* data;

            memset(buffer, 0, sizeof(buffer));
            switch (settings[2]) {
            case 0:
                if (settings[3] >= 10) {
                    data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), settings[3] / 10 + 0x2b, &size3);
                    memcpy(buffer, data, size3);
                    pos = size3;
                }
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), settings[3] % 10 + 0x2b, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 0x35, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 6, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                break;

            case 1:
                if (settings[4] >= 10) {
                    data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), settings[4] / 10 + 0x2b, &size3);
                    memcpy(buffer, data, size3);
                    pos = size3;
                }
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), settings[4] % 10 + 0x2b, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 0x36, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 7, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                break;

            case 2:
                if (settings[3] >= 10) {
                    data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), settings[3] / 10 + 0x2b, &size3);
                    memcpy(buffer, data, size3);
                    pos = size3;
                }
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), settings[3] % 10 + 0x2b, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 0x35, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                data = getMsgData__5MuMsgFUlPPv(*reinterpret_cast<MuMsg**>(s + 0xf8), 8, &size3);
                memcpy(buffer + pos, data, size3);
                pos += size3;
                break;
            }

            fn_800B92D8(*reinterpret_cast<MuMsg**>(s + 0xf8), 4, buffer, pos);
        }

        fn_3_8880(self);
    }
}
