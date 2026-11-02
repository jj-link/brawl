#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
struct Vec3f { float x,y,z; void set(float a,float b,float c) {x=a;y=b;z=c;} };
struct Params {
    float base;
    char pad04[0x8C];
    float low, high, rate;
    char pad9C[0xC];
    float up, down;
};
struct Record {
    Vec3f pos, previous;
    char pad18[8];
    float angle, velocity, offset;
    unsigned char falling, kind;
    char pad2E[6];
};
struct Stage;
struct StageBase { char pad00[0x3C]; };
struct Stage : StageBase {
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
    virtual void vf81();
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
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual unsigned int test(Vec3f*);
    virtual unsigned int height(float*,Vec3f*,int);
    char pad40[0x5C];
    Params* params;
    char padA0[0xA64];
    Record record;
    char padB38[0x68];
    char padBA0[0x30];
    unsigned char mode;
    char padBD1[7];
    float extra;
};
struct Constants { float v[28]; };
extern "C" const unsigned char lbl_81_rodata_0[];
extern "C" void* fn_27_222878(void*, unsigned int);
extern "C" int stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(Vec3f*,Vec3f*,Vec3f*,Vec3f*,bool,void*,bool,unsigned char);
extern "C" float fn_80162540(float,float);
inline float clampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_81_2DB4(Stage* self,int index,float dt) {
    Stage* slot;
    const Constants* constants=(const Constants*)lbl_81_rodata_0;
    Params* params=self->params;
    if (!params) return;
    slot=(Stage*)((char*)self+index*0x34);
    float x,z;
    z=slot->record.pos.z;
    x=slot->record.pos.x;
    Vec3f start={x,constants->v[26],z};
    Vec3f direction={constants->v[0],constants->v[27],constants->v[0]};
    Vec3f hit, normal;
    if (!stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(&start,&direction,&hit,&normal,true,fn_27_222878(self,0),false,1) || normal.y<=constants->v[0]) {
        slot->record.falling=1;
        slot->record.angle=constants->v[0];
        slot->record.previous=slot->record.pos;
        float ignored=constants->v[0];
        if (self->test(&slot->record.pos)==1) ignored+=constants->v[10];
        float unused;
        if (self->height(&unused,&slot->record.pos,1)==1) ignored+=unused;
        if (self->mode!=10) ignored+=self->extra;
        float delta=slot->record.pos.y-slot->record.offset;
        float change=constants->v[0];
        if (slot->record.kind==1) {
            if (delta>constants->v[0]) change-=params->up*dt;
            else change+=params->down*dt;
        } else {
            if (delta>constants->v[0]) change-=params->rate*dt;
            else change+=params->rate*dt;
        }
        slot->record.velocity=change;
        slot->record.pos.y+=(float)(double)change*dt;
        if (slot->record.pos.y < params->low+constants->v[20]*(params->high-params->low)+nw4r::math::FAbs(params->base))
            slot->record.offset+=params->rate;
        else
            slot->record.offset-=params->rate;
    } else {
        float adjust=constants->v[0];
        if (self->test(&slot->record.pos)==1) adjust+=constants->v[10];
        float value;
        if (self->height(&value,&slot->record.pos,1)==1) adjust+=value;
        if (self->mode!=10) adjust+=self->extra;
        slot->record.previous=slot->record.pos;
        float delta=slot->record.pos.y-(adjust+(hit.y+slot->record.offset));
        float change=constants->v[0];
        if (slot->record.kind==1) {
            if (delta>constants->v[0]) { float m=constants->v[20]*params->up; change-=m*dt; }
            else { float m=constants->v[20]*params->down; change+=m*dt; }
        } else {
            if (delta>constants->v[0]) { float m=constants->v[20]*params->rate; change-=m*dt; }
            else { float m=constants->v[20]*params->rate; change+=m*dt; }
        }
        slot->record.velocity=change;
        slot->record.pos.y+=(float)(double)change*dt;
        if (hit.y+slot->record.offset>slot->record.pos.y) {
            slot->record.falling=0;
            slot->record.pos.y=hit.y+slot->record.offset;
        }
        float nx=normal.x;
        float ny=normal.y;
        float f=fn_80162540(ny,nx);
        slot->record.angle=constants->v[18]*f-constants->v[19];
        if (constants->v[0]!=adjust) slot->record.offset+=nw4r::math::FAbs(slot->record.velocity);
        else slot->record.offset-=nw4r::math::FAbs(slot->record.velocity);
        slot->record.offset=clampRange(slot->record.offset,params->low,params->high);
    }
}
