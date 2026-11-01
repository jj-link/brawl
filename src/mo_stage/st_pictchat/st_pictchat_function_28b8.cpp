#pragma force_active on
struct Pictchat {
    unsigned char pad[0x1e5];
    unsigned char order[27];
};
extern "C" float randf__Fv();
extern "C" void fn_73_28B8(Pictchat* self) {
    unsigned char count = 27;
    for (unsigned char i = 0; i < count; ++i)
        self->order[i] = i + 1;
    for (unsigned char i = 0; i < count; ++i) {
        unsigned char j = (unsigned char)(count * randf__Fv());
        unsigned char t = self->order[i];
        self->order[i] = self->order[j];
        self->order[j] = t;
    }
}
