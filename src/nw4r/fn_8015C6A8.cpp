#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_Rect.h>
#pragma force_active on

struct Node {
    char pad0[0x2C];
    float x;
    float y;
    char pad1[0xF];
    unsigned char flag;
    float rate;
    char pad2[0x10];
    int count;
};

struct Data {
    Node* node;
    char pad[4];
    float base;
};

extern "C" float fn_8015F814(Node*);
extern "C" float fn_8015F874(Node*);
extern "C" float fn_8016017C(Node*);

extern "C" int fn_8015C6A8(void* arg1, nw4r::ut::Rect* out, int mode, Data* data)
{
    switch (mode) {
    case 10: {
        Node* moving;
        Node* object = data->node;
        out->right = object->x;
        out->top = object->y;

        moving = data->node;
        float start = data->base;
        float y = moving->y;
        float nextY = y + fn_8016017C(moving);
        moving->x = start;
        moving->y = nextY;

        out->left = object->x;
        float objY = object->y;
        out->bottom = objY + fn_8015F874(data->node);
        out->Normalize();
        return 3;
    }

    case 9: {
        int count;
        Node* moving;
        Node* object = data->node;
        out->left = object->x;

        moving = data->node;
        count = moving->count;
        if (count > 0) {
            float rate;
            if (moving->flag != 0)
                rate = moving->rate;
            else
                rate = fn_8015F814(moving);

            float start;
            float x;
            x = moving->x;
            start = data->base;
            float delta = x - start;
            float interval = (float)count * rate;
            int steps = (int)(delta / interval);
            moving->x = start + interval * (float)(steps + 1);
        }

        out->right = object->x;
        out->top = object->y;
        out->bottom = out->top + fn_8015F874(object);
        out->Normalize();
        return 1;
    }

    default:
        return 0;
    }
}
