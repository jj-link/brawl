#pragma force_active on
struct Rect {
    float left, right, up, down;
};

struct cmAIController {
    unsigned char pad[0x94];
    unsigned char flags;
    unsigned char pad95[0xF3];
    Rect range;
};

extern cmAIController* g_cmAIController;

extern "C" void setCameraLimitRange__7stMeleeFffff(
    void*, float a, float b, float c, float d)
{
    cmAIController* camera = g_cmAIController;
    if (camera) {
        Rect range;
        range.left = camera->range.left;
        range.right = camera->range.right;
        camera->flags |= 2;
        range.left = a;
        range.right = b;
        range.up = c;
        range.down = d;
        camera->range = range;
    }
}
