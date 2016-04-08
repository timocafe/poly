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


for my $key (keys %table) {
    my ($su,$st,$sl,$vu,$vt,$vl)=@{$table{$key}}{'scalar_ulp','scalar_throughput','scalar_latency','vector_ulp','vector_throughput','vector_latency'};

    print "$_ " foreach ($key,$su,$st,$sl,$vu,$vt,$vl,"\n");
}

