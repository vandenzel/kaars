use strict;
use Data::Dumper;

my @words = ();

while ( <> ) {
	chomp;
	next if /^#/;
	push @words, split /\s+/;

}

my $version = shift @words;
my $width = shift @words;
my $height = shift @words;
my $maxvalue = shift @words;

my @matrix = ();
foreach my $r ( 0 .. $height - 1 ) {
	foreach my $c ( 0 .. $width - 1 ) {

		my $p = shift @words;
		$matrix[ $c ][ $r ] = $p
	}
}

warn Dumper( \@matrix );

printf( "{\n    %s\n}\n", join( ",\n    ", map { 
sprintf( "{%s }", join( ", ", map { sprintf "%4d", $_ } @$_ ) );
} @matrix ) );
