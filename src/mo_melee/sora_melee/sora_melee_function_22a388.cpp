#pragma force_active on
struct Point {
    float x, y;
};

struct Segment {
    Point a, b;
    float extra;
};

struct Node {
    char pad[15];
    unsigned char flags;
};

struct Entry {
    Node* node;
    void* value;
    void* owner;
    unsigned char type;
    unsigned char flag : 1;
    unsigned char rest : 7;

    Entry() : node(0), value(0), owner(0), type(0), flag(0) {}
};

extern "C" {
extern float lbl_27_rodata_3708;

void fn_80111968(void*, Segment*, Node*, int);
void fn_800408C4(Segment*, Point*, Point*);
int fn_80113EC0(Entry*, Entry*);
int fn_80113DF8(Entry*, Entry*);

void fn_27_22A388(
    void*, Entry* input, Point* output, unsigned int* count,
    float left, float right
) {
    Point* cursor;
    unsigned int m;
    unsigned int n = 0;
    Entry current;
    Entry next;
    Point first[8];
    Point second[8];
    Segment segment;
    Point line;
    Point intersection;
    cursor = first;

    current = *input;
    do {
        fn_80111968(current.owner, &segment, current.node, 0);
        if (left < segment.a.x) {
            ++n;
            *cursor++ = segment.a;
        } else {
            line.x = left;
            line.y = lbl_27_rodata_3708;
            fn_800408C4(&segment, &line, &intersection);
            first[n].x = intersection.x;
            first[n].y = intersection.y;
            ++n;
            break;
        }

        if (!fn_80113EC0(&current, &next) || !(next.node->flags & 1))
            break;
        current = next;
    } while (true);

    for (unsigned int i = 0; i < n; ++i)
        output[i] = first[n - 1 - i];

    current = *input;
    m = 0;
    cursor = second;
    do {
        fn_80111968(current.owner, &segment, current.node, 0);
        if (segment.b.x < right) {
            ++m;
            *cursor++ = segment.b;
        } else {
            line.x = right;
            line.y = lbl_27_rodata_3708;
            fn_800408C4(&segment, &line, &intersection);
            second[m].x = intersection.x;
            second[m].y = intersection.y;
            ++m;
            break;
        }

        fn_80113DF8(&current, &next);
        if (!fn_80113DF8(&current, &next) || !(next.node->flags & 1))
            break;
        current = next;
    } while (true);

    unsigned int outIndex = n;
    for (unsigned int i = 0; i < m; ++i, ++outIndex)
        output[outIndex] = second[i];

    *count = n + m;
}
}
