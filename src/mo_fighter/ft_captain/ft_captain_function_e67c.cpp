#pragma force_active on
extern "C" {
int fn_100_10794(void* self, void* c);
void fn_100_FF9C(int x);
void fn_100_10288();
void fn_100_1046C();
void fn_100_FF50();
void fn_100_10518(void* self, int x);
void fn_100_10B74(void* self);
void fn_100_10A4C(void* self);
void fn_100_FC20(void* self);
void fn_100_FCE0();
void fn_100_10C78(int x);
void fn_100_10774();
void fn_100_10CEC(int x);
void fn_100_F7F4();
void fn_100_FB5C(void* self, void* args);
extern void* g_soWorld;
}

struct CaptainEvent {
    int id;
    unsigned char flag;
    int value;
    unsigned char rest[36];
};

extern "C" void fn_100_E67C(void* unused, void* self, void* c) {
    (void)unused;
    if (fn_100_10794(self, c) != 0) {
        CaptainEvent args;
        args.id = 0x44F;
        args.flag = 0;
        args.value = 3;
        fn_100_FB5C(self, &args);
        return;
    }
    fn_100_FF9C(1);
    fn_100_10288();
    fn_100_1046C();
    fn_100_FF50();
    fn_100_10518(self, 0);
    *(unsigned char*)((char*)g_soWorld + 0xd) = 1;
    fn_100_10B74(self);
    fn_100_10A4C(self);
    fn_100_FC20(self);
    fn_100_FCE0();
    fn_100_10C78(1);
    fn_100_10774();
    fn_100_10CEC(0);
    fn_100_F7F4();
}
