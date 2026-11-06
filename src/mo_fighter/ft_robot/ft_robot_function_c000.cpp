#pragma force_active on
namespace {
typedef unsigned char Byte;
struct RobotEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
RobotEventEntry* fn_120_CB6C(void*, int);
RobotEventEntry* fn_120_CA84(void*, int);
RobotEventEntry* fn_120_C99C(void*, int);
RobotEventEntry* fn_120_C8B4(void*, int);
RobotEventEntry* fn_120_C7CC(void*, int);
RobotEventEntry* fn_120_C6E4(void*, int);
RobotEventEntry* fn_120_C5FC(void*, int);
RobotEventEntry* fn_120_C514(void*, int);
void fn_120_CB34(RobotEventEntry*, void*);
void fn_120_CA4C(RobotEventEntry*, void*);
void fn_120_C964(RobotEventEntry*, void*);
void fn_120_C87C(RobotEventEntry*, void*);
void fn_120_C794(RobotEventEntry*, void*);
void fn_120_C6AC(RobotEventEntry*, void*);
void fn_120_C5C4(RobotEventEntry*, void*);
void fn_120_C4DC(RobotEventEntry*, void*);
}

extern "C" void fn_120_C000(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_CB6C(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_CB34(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_CA84(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_CA4C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_C99C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_C964(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_C8B4(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_C87C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_C7CC(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_C794(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_C6E4(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_C6AC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_C5FC(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_C5C4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        RobotEventEntry* entry = fn_120_C514(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_120_C4DC(entry, event);
    }
}
