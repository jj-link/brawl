#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct soAreaData {
    u8 a, b;
    u16 c;
    u32 d, e, f;
    float x, y, z, w;
};

template <class T> struct soSet;

struct ykAreaData {
    u32 data[3];
};

struct grYakumono {
    void setAreaGimmick(soAreaData*, soSet<soAreaData>*, ykAreaData*, bool);
};

struct StageData {
    u8 pad[0x20];
    float x, y, z, w;
};

struct ObjectBase {
    u8 pad0[0x3c];

    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual StageData* getData();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void getPos(Vec3f*);
};

struct Object : ObjectBase {
    u8 pad40[0x14c - 0x40];
    void* yakumono;
    StageData* data;
    u8 pad154[0x168 - 0x154];
    soAreaData area;
    u8 set[8];
    ykAreaData yk;
    u8 pad19c[0x1b0 - 0x19c];
    u8 state;
};

extern "C" void* memset(void*, int, unsigned long);
extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(void*, int, int);
extern "C" void setObserveYakumono__9stTriggerFP8Yakumono(void*, void*);
extern "C" void* g_stTriggerMng;

extern "C" void fn_63_165AC(Object* self) {
    if (self->state == 1) {
        Vec3f pos;
        self->getPos(&pos);
        setPos__9grGimmickFP5Vec3f(self, &pos);
    } else {
        self->data = self->getData();
        memset(&self->yk, 0, 12);
        self->area.a = 0;
        self->area.b = 0x15;
        self->area.d = 0;
        self->area.e = 0;
        self->area.c = 1;
        self->area.f = 0;
        self->area.x = self->data->x;
        self->area.y = self->data->y;
        self->area.z = self->data->z;
        self->area.w = self->data->w;
        ((grYakumono*)self)->setAreaGimmick(
            &self->area,
            (soSet<soAreaData>*)self->set,
            &self->yk,
            false
        );
        void* trigger = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(
            g_stTriggerMng, 0x23, -1
        );
        setObserveYakumono__9stTriggerFP8Yakumono(trigger, self->yakumono);
        self->state = 1;
    }
}
