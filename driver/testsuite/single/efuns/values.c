void do_test() {
    mapping m = ([ 1 : 2, 3 : 4, 5 : 6 ]);
    mixed *k = keys(m);
    mixed x, y;

    foreach (x, y in m) {
	k -= ({ y });
    }
    ASSERT(k == ({}));
}
