/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CMD;

// Rust/Belboz
private void main( mixed *arg)
{

    object	start_place;
    object	target;
    string	target_name;

    target = arg[0];
    start_place = environment( target );
    target->move( environment( this_body() ) );
    if( environment( target ) == start_place )
    {
	out( "Trans:  move failed.\n" );
	return;
    }
    target_name = target->query_name();
    if( ! target_name )
	target_name = target->short();

    /* Be careful here or it will be impossible to trans someone with no env() */
    if (!(target->query_link() && interactive(target->query_link()) && target_name == "Someone") && start_place)
	tell_object( start_place , sprintf( "%s dissapears in a puff of smoke.\n",
	    target_name ) );
    outf( "You summon %s to you.\n", target_name );
    tell_object( target, "You are magically transported somewhere.\n" );

    if( !( target->query_link() && interactive(target->query_link()) &&
	   target_name == "Someone" ) )
    {
	tell_room( environment( target ), sprintf("%s arrives in a puff of smoke.\n",
	    target_name ), 0, ({ target, this_body() }) );
    }

    return;
}

int help()
{
    write("trans <object> :  moves the object specified to your environment\n" );
    return 1;
}
