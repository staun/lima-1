/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** give.c
**
*/

#include <mudlib.h>

inherit VERB_OB;

void do_give_obj_to_liv(object ob, object liv) {
    if (!try_to_acquire(ob))
	return;
    if( ob->is_worn())
	write( "You'll need to remove it first.\n");
    else
    {
	this_body()->targetted_action("$N $vgive a $o to $t.\n", liv, ob);
	//### Need to check the return value
	ob->move(liv);
    }
}

void do_give_obs_to_liv(array info, object liv) {
    handle_obs(info, (: do_give_obj_to_liv :), liv);
}

//##see comments in get
mixed can_give_wrd_str_to_liv(string amount, string str, object who) {
    int z;
    string s1, s2;

    sscanf(amount, "%d%s", z, s1);
    if (s1 != "") return 0;

    sscanf(str, "%s %s", s1, s2);
    if (s2) {
	if (s2 != "coin" && s2 != "coins")
	    return 0;
	return 1;
    }
    return str == "coin" || str == "coins";
}

void do_give_wrd_str_to_liv(string amount, string str, object who)
{
    string s;
    int number;

    sscanf(amount, "%d", number);

    sscanf(str, "%s %s", str, s);

    if(this_body()->query_amt_money(str) < number) {
	write("You dont have "+ number +" "+ str +" cons.\n");
	return;
    } else {
	who->add_money(str,number);
	this_body()->subtract_money(str,number);
	this_body()->simple_action("$N $vgive $o some money.",who);
    }
}

array query_verb_info()
{
    return ({ ({ "OBS to LIV", "WRD STR to LIV" }),
      ({ "hand" }) });
}

#ifdef OLD_CODE

/****************************************/
/*     give verb                        */
/*                                      */
/*  zifnab 2/95          */
/*                                      */
/*   case 1 - give 
     /*   case 2 - give OBJ                  */
/*   case 3 - give OBJ to LIV           */
/*   case 4 - give STR                  */
/*   case 5 - give all                   */
/*   case 6 - give OBJ to OBJ           */
/****************************************/

//   do_give is the function called within the obnject that you want
//     to give something to.

do_give(object ob, object ob2) {
    if(!ob2->give_to(ob, ob2))
	this_body()->simple_action("The $o0 $vlook at the $o1 very carefully, then hurls it back at $n.", ob2, ob);
}

int i;

give( rule, stack, input ) {
    switch(rule) {

    case 1:

	//  CASE 1 --  HANDLES GIVE WITH NO OTHER COMMNADS
	//

	interrogate(input);
	return(1);

    case 2:


	if(this_body() == environment(stack[1]))

	{
	    this_body()->my_action("$N can't see any $o0 here!\n", stack[3]);
	    break;
	}

	else
	{
	    this_body()->my_action("You're not holding that!\n");
	    break;
	}

    case 3:

	if(find_monster_in_room(stack[3]->query_name(),environment(this_body()))) {

	    do_give(stack[1], stack[3]);
	    break;
	}
	else {
	    this_body()->simple_action("$N $vgive $o0 to $o1.", stack[1], stack[3]);
	    stack[1]->move(stack[3]);
	    break;

	}
    case 4:

	write( "You don't see that here.\n" );
	break;

    case 5:
	for ( i = sizeof(stack[1]); i--;) 
	{
	    if (environment(stack[1][i]) == this_body() ) {
		stack[1][i]->move(stack[3]);
		this_body()->simple_action("$N $vgive $o0 to $o1.", stack[1], stack[3]);
	    }
	}
	break;

    case 6:
	this_body()->my_action("$N can't give a $o0 to $o1!\n", stack[1],stack[3]);
	break;
    }
    return(1);
}

#endif /* OLD_CODE */
