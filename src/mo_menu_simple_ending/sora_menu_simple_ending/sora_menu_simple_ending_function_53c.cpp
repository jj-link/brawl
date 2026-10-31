#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
struct App { unsigned char pad[0xf8]; u16 rate; };
struct Menu { unsigned char pad[0x50]; void* msg; };
extern "C" {
extern App* g_gfApplication;
extern const char lbl_19_data_88[];
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);

void fn_19_53C(Menu* self, u32 time) {
    u32 rate = g_gfApplication->rate;
    u32 minutes;
    u32 seconds;
    s32 frames;
    if (time >= rate * 6000) {
        minutes = 99;
        seconds = 59;
        frames = 99;
    } else {
        u32 perMinute = rate * 60;
        minutes = time / perMinute;
        time -= minutes * perMinute;
        seconds = time / rate;
        time -= seconds * rate;
        frames = (s32)(100.0f * (float)time / (float)rate);
    }
    printf__5MuMsgFUlPCce(self->msg, 0, lbl_19_data_88, minutes, seconds, frames);
}
}
