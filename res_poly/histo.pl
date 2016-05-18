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

open(my $fd1, ">>","histo_sb1.txt");
open(my $fd2, ">>","histo_sb2.txt");
open(my $fd3, ">>","histo_sb3.txt");
open(my $fd4, ">>","histo_sb4.txt");
open(my $fd5, ">>","histo_sb5.txt");

for my $key (keys %table) {
    my ($su,$st,$sl,$vu,$vt,$vl)=@{$table{$key}}{'scalar_ulp','scalar_throughput','scalar_latency','vector_ulp','vector_throughput','vector_latency'};
    my $count = split( /d/, $key );
    $count = $count-1;
    if($count == 1){
         print $fd1 "$_ " foreach ($key,$su,$st,$sl,$vu,$vt,$vl,$count,"\n");
    }
    if($count == 2){
         print $fd2 "$_ " foreach ($key,$su,$st,$sl,$vu,$vt,$vl,$count,"\n");
    }
    if($count == 3){
         print $fd3 "$_ " foreach ($key,$su,$st,$sl,$vu,$vt,$vl,$count,"\n");
    }
    if($count == 4){
         print $fd4 "$_ " foreach ($key,$su,$st,$sl,$vu,$vt,$vl,$count,"\n");
    }
    if($count == 5){
         print $fd5 "$_ " foreach ($key,$su,$st,$sl,$vu,$vt,$vl,$count,"\n");
    }
}

close $fd1;
close $fd2;
close $fd3;
close $fd4;
close $fd5;

