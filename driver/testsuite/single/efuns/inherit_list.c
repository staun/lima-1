void do_tests() {
    mixed *x;
    ASSERT(inherit_list(this_object()) == ({}));
    x = inherit_list(load_object("/single/efuns/inh2.c"));
    ASSERT(sizeof(x) == 1);
    ASSERT(x[0] == "single/efuns/inh1.c");
}
