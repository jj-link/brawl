#pragma force_active on

// The original is a 16-byte tail-call thunk: it loads the vtable pointer
// stored at offset 0x3c of `this` and jumps to the entry at offset 0xac,
// forwarding `this` unchanged.  This is modelled as a class whose
// non-polymorphic base occupies the first 0x3c bytes, with a non-virtual
// helper tail-calling the virtual function in that slot.

struct BaseData {
    char pad[0x3c];
};

#define V(n) virtual void v##n();

struct Handler : BaseData {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43)

    void dispatch() { v41(); }
};

extern "C" void fn_100_130C8(Handler* self) {
    self->dispatch();
}
