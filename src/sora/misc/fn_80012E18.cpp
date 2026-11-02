#include <types.h>
#include <new>
#pragma force_active on

extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
extern f32 lbl_805A13B4;
extern f32 lbl_805A13B8;

class QNonCopyable {
protected:
    QNonCopyable() { }
    ~QNonCopyable();
};

class QLink : private QNonCopyable {
public:
    QLink() : next(0), prev(0) { }
    ~QLink();
    QLink* next;
    QLink* prev;
};

class QListImpl : private QNonCopyable {
public:
    QListImpl() { Initialize_(); }
    ~QListImpl();
    void Initialize_() {
        count = 0;
        head.next = &head;
        head.prev = &head;
    }
    u32 count;
    QLink head;
};

class QList : public QListImpl {
public:
    QList() { }
    ~QList();
};

struct QFlags {
    u8 leaf : 1;
    u8 rest : 7;
    QFlags() { leaf = 1; }
};

struct QNode {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    u8 depth;
    QFlags flags;
    QNode* parent;
    QNode* children[4];
    QList list;

    QNode(f32 ax0, f32 ay0, f32 ax1, f32 ay1, QNode* p)
        : x0(ax0), y0(ay0), x1(ax1), y1(ay1), depth(0), flags(), parent(p), list() {
        if (p) {
            depth = p->depth + 1;
        }
        children[0] = 0;
        children[1] = 0;
        children[2] = 0;
        children[3] = 0;
    }
};

extern "C" void fn_80012E18(QNode* node) {
    f32 w = node->x1 - node->x0;
    f32 h = node->y1 - node->y0;
    if (w > lbl_805A13B4 && h > lbl_805A13B4) {
        QNode* mem = (QNode*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(2, sizeof(QNode) * 4);
        f32 x0 = node->x0;
        f32 y0 = node->y0;
        f32 x1 = node->x1;
        f32 y1 = node->y1;
        f32 mx = lbl_805A13B8 * (x0 + x1);
        f32 my = lbl_805A13B8 * (y0 + y1);
        node->children[0] = new (&mem[0]) QNode(x0, my, mx, y1, node);
        node->children[1] = new (&mem[1]) QNode(x0, y0, mx, my, node);
        node->children[2] = new (&mem[2]) QNode(mx, my, x1, y1, node);
        node->children[3] = new (&mem[3]) QNode(mx, y0, x1, my, node);
        for (u32 i = 0; i < 4; i++) {
            fn_80012E18(node->children[i]);
        }
        node->flags.leaf = 0;
    }
}
