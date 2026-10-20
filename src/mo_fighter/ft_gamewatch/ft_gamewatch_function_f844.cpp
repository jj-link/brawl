#pragma force_active on
typedef short s16;

extern "C" void fn_107_F7F4(void* object, void* arg);
extern "C" void fn_107_FD64(s16* destination, const s16* source);
extern "C" void fn_107_F8D4(void* object, s16* source, void* arg);

struct Ft107Flags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_107_F844(void* self, s16* source, void* arg) {
    unsigned char* obj = static_cast<unsigned char*>(self);
    Ft107Flags* sub = reinterpret_cast<Ft107Flags*>(obj + 0xc);
    s16 tmp[4];

    if ((source[0] & 1) != 0) {
        bool flag = sub->flag;
        if (flag == true && sub->next == 0) {
            fn_107_F7F4(sub, arg);
        }
    }

    fn_107_FD64(tmp, source);
    fn_107_F8D4(obj + 4, tmp, arg);
}
