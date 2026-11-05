#pragma force_active on
#pragma fp_contract on
extern float lbl_805A4748;
extern float lbl_805A474C;
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Node;
struct Link;
struct Owner { char pad[0x30]; Link* link; };
struct Link { Owner* owner; char pad[8]; Node* node; };
struct Node {
    float x, y, z;
    char pad0[4];
    float distance;
    Vec4* point;
    char pad1[0x2c];
    int state;
};
struct Context {
    float min, max;
    char pad[4];
    int count;
    char pad2[0xdd0];
    Node* nodes[1];
};
extern "C" int fn_80320008(Context* ctx, Node* node, Vec4* point, int* count, Link** output) {
    float epsilon = lbl_805A4748;
    int result = 0;
    int i = 0;
    
    for (; i < 3; ++i) {
        Link* link = *(Link**)((char*)node + (i << 4) + 0x1c);
        Node* child = link->node;
        if (child->state == 0) {
            Vec4 delta;
            Vec4* p = child->point;
            int state = 1;
            delta.x = point->x - p->x;
            delta.y = point->y - p->y;
            delta.z = point->z - p->z;
            delta.w = point->w - p->w;
            float d = child->z * delta.z + (child->x * delta.x + child->y * delta.y);
            if (d > ctx->min) {
                if (d < ctx->max) ctx->max = d;
            } else {
                if (epsilon + d > ctx->min) ctx->min = epsilon + d;
                state = 2;
            }
            if (ctx->min >= ctx->max) state = 4;
            child->state = state;
            if (state == 1) {
                result = fn_80320008(ctx, child, point, count, output);
                if (result == 2) break;
            } else if (child->state == 4) {
                result = 2;
                break;
            }
        }
        if (child->state == 2) {
            link->owner->link = link;
            ++*count;
            *output = link;
        }
    }
    node->distance = lbl_805A474C;
    ctx->nodes[ctx->count++] = node;
    return result;
}