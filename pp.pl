#!/usr/bin/perl -w

use strict;

my %table=();

while (<>) {
   my ($bench,$algo,$count)=(m'.*/([a-zA-Z]*_[a-zA-Z]*)_(\w+)\s+(\w+)');

   $table{$algo}{$bench}=$count;
}

for my $key (keys %table) {
   my ($su,$st,$vu,$vt)=@{$table{$key}}{'scalar_ulp','scalar_throughput','vector_ulp','vector_throughput'};

   print "<tr>\n";
   print "<td>$_</td>\n" foreach ($key,$su,$st,$vu,$vt);
   print "</tr>\n";
}
