#pragma force_active on
extern float lbl_805A4590;
typedef void (*Callback)(void*, void*, char**);
inline void invoke(char* self, char* data, char** items) {
    Callback callback = *(Callback*)(*items + (unsigned char)self[1] * 0x34 + 0x16B4);
    if (callback) callback(self, data, items);
}
extern "C" void fn_802FF49C(char* self, char** items, float a, float b) {
    char* data;
    switch ((unsigned char)self[0]) {
    case 2:
    case 6:
        data = self + 0x20;
        invoke(self, data, items);
        break;
    case 4:
        data = self + 0x30;
        if (*(float*)(self + 0x1C) == a)
            *(float*)(self + 0x1C) = b;
        else
            *(float*)(self + 0x1C) = lbl_805A4590;
        invoke(self, data, items);
        break;
    case 0: break;
    case 1:
    case 3:
    case 5: return;
    }
}