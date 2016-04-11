#!/usr/bin/perl -w


$fname = $ARGV[0];
open INFILE, $fname or die "cannot open $fname\n";
@lines = <INFILE>;
close INFILE;

for $line(@lines) {
  chomp($line);
    ( $first ) = split( /\s+/, $line );
    @count = split( /d/, $first );
    $count = @count-1;
  if( $count > -1 ) {
    print $line . " " . $count  ."\n";
  }
}


#print "$_ " foreach ($su,$st,$sl,$vu,$vt,$vl,"\n");
