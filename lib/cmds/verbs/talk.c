/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

void do_talk() {
    this_body()->simple_action("$N $vstart babbling about nothing (and to noone) in particular.\n");
}

void do_talk_to_liv(object liv) {
    liv->begin_conversation();
}

array query_verb_info() {
    return ({ ({ "", "to LIV" }) });
}
