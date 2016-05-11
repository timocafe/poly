#!/usr/bin/perl -w

use strict;

my %table_s=();
my %table_v=();

my %sort_table_s=();
my %sort_table_v=();

my $filename = shift;
open(my $fh, '<:encoding(UTF-8)', $filename)
  or die "Could not open file '$filename' $!";

while (my $row = <$fh>) {
  chomp $row;
  my ($algo,$ulp_s,$th_s,$la_s,$ulp_v,$th_v,$la_v,$count)= split(/\s/,$row,8);
  $table_s{$algo} = [$ulp_s,$th_s,$la_s];
  $table_v{$algo} = [$ulp_v,$th_v,$la_v];
}

sub pretty_poly {
     my ($method,$degree)=@_;
     return "P_e^{$degree}" if $method eq "e";
     return "P_b^{$degree}" if $method eq "b";
     return "P_{h^$1}^{$degree}" if $method=~/hkth(\d+)/;
}

sub sort_tl{
     my @v_lines=();
     my $count=0;
     my ($my_table, $my_i)=@_;
     for my $key (sort {$my_table->{$a}[$my_i] <=> $my_table->{$b}[$my_i] } keys %$my_table) {
         my ($ulp,$th,$la)=@{$my_table->{$key}};
         my $poly=$key;
         $poly=~s/(e|b|hkth\d+)d(\d+)/pretty_poly($1,$2)/eg;
         push @v_lines, sprintf("\$%s\$ & %.2f & %.2f & %d ",$poly,$th,$la,$ulp);
         last if ++$count>=10;
     }
     return @v_lines;
}

my @v_lines_th = sort_tl(\%table_v,1);
my @s_lines_th = sort_tl(\%table_s,1);
my @v_lines_l = sort_tl(\%table_v,2);
my @s_lines_l = sort_tl(\%table_s,2);

print << '__header';
\begin{table}[ht]
\begin{center}
\begin{tabular}{ l c c c  l c c  c }
\hline
		       & \multicolumn{3}{c}{scalar}              &           &  \multicolumn{3}{c}{vector}\\
		       & \multicolumn{3}{c}{Throughput Criteria} &           &  \multicolumn{3}{c}{Throughput Criteria}\\
 Algorithm             & Th.  & La.     & ULP                    & Algorithm & Th.   & La.     & ULP\\
__header

for my $i ( 0 .. $#s_lines_th ) {
    print "$s_lines_th[$i] & $v_lines_th[$i]\\\\\n";
}

print << '__middle';
		       & \multicolumn{3}{c}{Latency Criteria} &           &  \multicolumn{3}{c}{Latency Criteria}\\
__middle

for my $i ( 0 .. $#s_lines_l ) {
    print "$s_lines_l[$i] & $v_lines_l[$i]\\\\\n";
}

print << '__footer';
\end{tabular}
\end{center}
\caption{Best Latency/throughput [cycle] polynomial evaluation on all platforms. The criteria indicates the sort the tuple (throughput, latency, ulp),
on a specific part \label{LTR_EXP}}
\end{table}%
__footer
