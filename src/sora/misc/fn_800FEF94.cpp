#pragma force_active on
typedef void (*Fn)(void*, unsigned char);
struct Table {
    int pad[2];
    Fn fn;
};
extern const Table lbl_804091B8;

extern "C" void fn_800FEF94(void* self, unsigned char arg) {
    unsigned char* s = (unsigned char*)self;
    s[0x114] = arg;
    *(int*)(s + 0x110) = 1;
    if (lbl_804091B8.fn) lbl_804091B8.fn(self, arg);
}
