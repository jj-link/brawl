#pragma force_active on
struct Object { unsigned char pad0[0x2C]; float x; float y; unsigned char pad1[0x0F]; unsigned char hasRate; float rate; unsigned char pad2[0x10]; int count; };
struct Data { Object* object; unsigned char pad[4]; float start; };
extern "C" float fn_8015F814(Object*);
extern "C" float fn_801602AC(Object*);
extern "C" int fn_8015C8E0(void*, int mode, Data* data) {
    switch (mode) {
    case 10: {
        Object* moving = data->object;
        float start = data->start;
        float y = moving->y;
        float nextY = y + fn_801602AC(moving);
        moving->x = start;
        moving->y = nextY;
        return 3;
    }
    case 9: {
        Object* moving = data->object;
        int count = moving->count;
        if (count > 0) {
            float rate;
            if (moving->hasRate != 0) rate = moving->rate;
            else rate = fn_8015F814(moving);
            float start;
            float x;
            x = moving->x;
            start = data->start;
            float delta = x - start;
            float interval = (float)count * rate;
            int steps = (int)(delta / interval);
            moving->x = start + interval * (float)(steps + 1);
        }
        return 1;
    }
    default: return 0;
    }
}