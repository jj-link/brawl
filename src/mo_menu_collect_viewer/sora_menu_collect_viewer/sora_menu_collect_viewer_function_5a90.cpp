#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
extern void* g_sndSystem;
extern const u8 lbl_6_rodata_5B0[];
extern char lbl_6_data_0[];

void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
int fn_800BA2E0();
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
}

struct ViewerBase {
    char pad0[0x3C];
};

struct Viewer : ViewerBase {
    virtual void at8();
    virtual void atC();
    virtual void at10();
    virtual void at14();
    virtual void at18();
    virtual void at1C();
    virtual void at20();
    virtual void at24();
    virtual void at28();
    virtual void at2C();
    virtual void at30();
    virtual void at34();
    virtual void at38();
    virtual void at3C();
    virtual void at40();
    virtual void at44();
    virtual void at48();
    virtual void at4C();
    virtual void at50();
    virtual void at54();
    virtual void at58();
    virtual void at5C();
    virtual void at60();
    virtual void at64();
    virtual void at68();
    virtual void at6C();
    virtual void at70();
    virtual void at74();
    virtual void at78();
    virtual void at7C();
    virtual void at80();
    virtual void at84();
    virtual void at88();
    virtual void at8C();
    virtual void at90();
    virtual void at94();
    virtual void at98();
    virtual void at9C();
    virtual void atA0();
    virtual void atA4();
    virtual void atA8();
    virtual void atAC();
    virtual void atB0();
    virtual void atB4();
    virtual void atB8();
    virtual int atBC(int);
    virtual void atC0();
    virtual void atC4();
    virtual void atC8();
    virtual void atCC();
    virtual void atD0();
    virtual void atD4();
    virtual void atD8();
    virtual void atDC();
    virtual void atE0();
    virtual void atE4();
    virtual void atE8(int, int);
    virtual void atEC();
    virtual void atF0();
    virtual void atF4();
    virtual void atF8();
    virtual void atFC();
    virtual void at100(int);
    virtual void at104();
    virtual void at108();
    virtual void at10C();
    virtual void at110();
    virtual void at114();
    virtual void at118();
    virtual void at11C();
    virtual void at120(int, int);
    virtual void at124(int, int);

    char pad40[0x168];
    u32 flags;
    char* data;
};

extern "C" void fn_6_5A90(Viewer* self) {
    if (self->flags & 4) {
        self->atF4();
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
    } else if (self->flags & 2) {
        if (self->atBC(*(int*)(self->data + 0x1A0))) {
            self->at100(fn_800BA2E0());
        }
    } else if (*(u32*)(self->data + 0x1B50) & 8) {
        self->at124(1, 5);
    } else if (*(u32*)(self->data + 0x1B50) & 4) {
        *(int*)(self->data + 0x1BFC) = *(int*)(self->data + 0x1C00);

        int next;
        switch (*(int*)(self->data + 0x1C00)) {
        case 7:
            next = 6;
            break;
        case 8:
            next = 7;
            break;
        case 30:
            next = 8;
            break;
        case 34:
            next = 9;
            break;
        }

        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        self->atE8(next, 1);

        if (lbl_6_rodata_5B0[next]) {
            printf__5MuMsgFUlPCce(
                *(void**)(self->data + 0x1C7C), 0, lbl_6_data_0);
            printf__5MuMsgFUlPCce(
                *(void**)(self->data + 0x1C7C), 2, lbl_6_data_0);
            self->atD8();
        }
    } else {
        self->at120(1, 5);
    }
}
