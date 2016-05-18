#!/usr/bin/perl -w

use strict;

my %table=();

while (<>) {
    if (/latency/) {
    my ($algo,$scalar,$vector)=(m'.*latency_(\w+).*scalar::poly\s+(\S+).*vector::poly\s+(\S+)');
        $table{$algo}{'scalar_latency'}=''.$scalar;
        $table{$algo}{'vector_latency'}=''.$vector;
    }
    else {
    my ($function,$bench,$algo,$count)=(m'.*/([a-zA-Z]*)_([a-zA-Z]*_[a-zA-Z]*)_(\w+)\s+(\S+)');

    $table{$algo}{$bench}=''.$count;
    }
}

print << '__header';
<table>
<tbody>
<tr>
<th>Algorithm</th>
<th>Scalar ULP</th>
<th>Scalar Throughput</th>
<th>Scalar Latency</th>
<th>Vector ULP</th>
<th>Vector Throughput</th>
<th>Vector Latency</th>
</tr>
__header

for my $key (keys %table) {
    my ($su,$st,$sl,$vu,$vt,$vl)=@{$table{$key}}{'scalar_ulp','scalar_throughput','scalar_latency','vector_ulp','vector_throughput','vector_latency'};

    print "<tr>\n";
    print "<td><center>$_</center></td>\n" foreach ($key,$su,$st,$sl,$vu,$vt,$vl);
    print "</tr>\n";
}

print << '__footer';
</tbody>
</table>
__footer
