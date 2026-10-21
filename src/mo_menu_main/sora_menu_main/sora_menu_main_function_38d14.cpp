#pragma force_active on
typedef int s32;

class ntFriendInfo {
public:
    static ntFriendInfo* getInstance();
};

extern "C" {
s32 fn_800305B0(s32);
s32 fn_80030548(s32);
ntFriendInfo* fn_80030DEC(s32, s32);
s32 fn_80030F58(s32);
s32 fn_8014C97C(ntFriendInfo*, s32*, s32*);
void fn_800307B4();
void* memcpy(void*, const void*, unsigned int);

void fn_2_38D14(char* self) {
    ntFriendInfo* p;
    s32 flag = 0;
    s32 spC;
    s32 sp8 = 0x2804;
    if (fn_800305B0(2) != 0) {
        s32 t = fn_80030548(0x2B);
        *(s32*)(self + 0x1EC) = t;
        if (t != 0) {
            p = fn_80030DEC(t, 2);
            ntFriendInfo* g = ntFriendInfo::getInstance();
            if (fn_8014C97C(g, &spC, &sp8) != 0) {
                memcpy(p, (void*)spC, sp8);
                if (fn_80030F58(*(s32*)(self + 0x1EC)) != 0) {
                    flag = 1;
                }
            }
        }
        if (flag == 0 && *(s32*)(self + 0x1EC) != 0) {
            fn_800307B4();
            *(s32*)(self + 0x1EC) = 0;
        }
    }
}
}
