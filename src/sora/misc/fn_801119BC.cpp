#pragma force_active on
struct clSegment2D {
    float x1;
    float y1;
    float x2;
    float y2;
};

struct grCollisionLine {
    unsigned short start;
    unsigned short end;
};

struct Vertex {
    float x;
    float y;
    float z;
    float w;
};

struct grCollision {
    char pad[0x10];
    Vertex *verts;
};

extern "C" void getSegment__11grCollisionFP11clSegment2DP15grCollisionLine(grCollision *self, clSegment2D *seg, grCollisionLine *line) {
    Vertex *v0 = self->verts + line->start;
    Vertex *v1 = self->verts + line->end;
    seg->x1 = v0->x;
    seg->y1 = v0->y;
    seg->x2 = v1->x;
    seg->y2 = v1->y;
}
