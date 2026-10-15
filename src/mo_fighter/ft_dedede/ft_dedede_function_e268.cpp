// The interface pointer for this entry points 0xB8 bytes past the complete
// object; this entry slot re-derives the complete object pointer and
// tail-calls the in-module handler fn_117_9E84.
//
// Target evidence (original ft_dedede.rel): .text[0xE268,0xE270) is the raw
// word pair 3863ff48 4bffbc18 = addi r3,r3,-0xB8 ; b 0x9E84. No relocation
// of any import stream patches the branch word, so the displacement is the
// link-time-resolved intra-module branch, unlike the sibling thunks E208 /
// E210 / E218 whose branches carry module-27 REL24 relocations.
//
// Referencing-slot context (original ft_dedede.rel, self-stream records):
// exactly one record references 0xE268, the ADDR32 slot at .data 0x330. The
// recorded physical slot values around it: .data 0x32C points to .text
// 0xA358, whose bytes disassemble as the five-instruction sequence
// extsh r4,r4 ; mr r0,r5 ; mr r5,r3 ; extsb r6,r0 ; b <link-patched>
// (the same instruction sequence recurs at .text 0xA330/0xA344/0xA36C);
// .data 0x334 points to E260; .data 0x338 points to .data 0x698; raw words
// -0xB8 and -0xC4 sit at .data 0x328 and 0x33C, and the negative words
// across this table step by 0xC (-0xA0/-0xAC/-0xB8/-0xC4); the same slot
// values recur in a second copy (.data 0x814/0x818/0x81C -> .text
// 0xA358/E1D0/E1C8 and 0x820 -> .data 0xB94), which has no E268 entry.
// Because the bytes at .text 0xA358 are executable code, the initial
// draft's "typeinfo" label for slot 0x32C is withdrawn. Whether this region
// is a C++ vtable or some other structure is not resolved by this evidence;
// no structural classification of the surrounding records is asserted, and
// the reconstruction relies only on the single E268 reference and the 8
// target bytes.
//
// fn_117_9E84, from the disassembly of its preserved 0x64 bytes
// (evidence/fn_117_9E84.disasm.txt): it saves the incoming r3/r4/r5 into
// r29/r30/r31, calls the local function at 0x946C, restores r4/r5 and makes
// a virtual slot-12 call, then restores r3/r4/r5 and invokes fn_27_135EDC
// with the original first three arguments. No instruction of fn_117_9E84
// reads or writes r6/r7, so its own code passes the incoming r6/r7 to that
// call site unchanged; r6/r7 are caller-saved in this ABI, however, and
// fn_117_9E84 makes intervening calls (0x946C and the virtual call) before
// it, so whether fn_27_135EDC observes E268's original r6/r7 values is not
// established by this evidence. The declaration mirrors the shape already
// accepted for E1D0's direct fn_27_135EDC tail call (void* event,
// soModuleAccesser* accesser, int kind, int index); the only semantically
// guaranteed transformation in E268's own 8 bytes is r3 -= 0xB8 with every
// other incoming register passed through unchanged.
class soModuleAccesser;

extern "C" void fn_117_9E84(void* object, void* event,
        soModuleAccesser* accesser, int kind, int index);

extern "C" void fn_117_E268(void* interface, void* event,
                            soModuleAccesser* accesser, int kind, int index) {
    fn_117_9E84(static_cast<unsigned char*>(interface) - 0xB8, event, accesser,
                kind, index);
}
